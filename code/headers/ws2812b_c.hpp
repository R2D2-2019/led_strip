#pragma once

#include "led_strip_c.hpp"
#include "hwlib.hpp"

namespace r2d2::led_strip {
    //some nop instructions since hwlib::wait_ns() takes to long
    #define LEDSTRIP_WAIT_T0H() asm volatile(".rept 6\n\tNOP\n\t.endr")
    #define LEDSTRIP_WAIT_T0L() asm volatile(".rept 11\n\tNOP\n\t.endr")
    #define LEDSTRIP_WAIT_T1H() asm volatile(".rept 12\n\tNOP\n\t.endr")
    #define LEDSTRIP_WAIT_T1L() asm volatile(".rept 7\n\tNOP\n\t.endr")

    template <unsigned int N>
    class ws2812b_c : public led_strip_c<N> {
    private:
        // 3 bytes per led, 8 bits per byte
        uint8_t send_bit_buffer[N * 3 * 8];
	    
	// buffer for setting rgb in grb
        uint8_t grb_buffer[3];

	// pin used to send data to the led strip
        hwlib::pin_out &data_pin;

    public:
       /*
        *  \brief
	*  Constructor used to initiate this class
	*
	*  Parameter is a simple pin_out
	*/	
        ws2812b_c(hwlib::pin_out &data_out) : data_pin(data_out){};
	
       /*
        *  \brief
	*  Function used to send the data to the led strip
	*
	*  Each led from the strip is being buffered before being send to the ledstrip
	*  At the start of this function a reset is being called wich lasts for at least 50us
	*  each bit takes about 1.25us to be sent
	*/
        void send() override {
            data_pin.write(false);
	    data_pin.flush();
            hwlib::wait_us(50);

            uint16_t index = 0;

            for (unsigned int i = 0; i < N; i++) {
                rgb_s rgb_buffer = (*this)[i].get_color();
                grb_buffer[0] = rgb_buffer.green;
                grb_buffer[1] = rgb_buffer.red;
                grb_buffer[2] = rgb_buffer.blue;

                for (auto sending_color : grb_buffer) {
                    for (unsigned int i = 0; i < 8; i++) {
                        if ((sending_color & 128) == 128) {
                            send_bit_buffer[index++] = 1;
                        } else {
                            send_bit_buffer[index++] = 0;
                        }
                        sending_color <<= 1;
                    }
                }
            }

		 for (uint8_t bit : send_bit_buffer) {
                 if (bit) {
                    data_pin.write(1);
                    LEDSTRIP_WAIT_T1H();

                    data_pin.write(0);
                    LEDSTRIP_WAIT_T1L();
                } else {
                    data_pin.write(1);
                    LEDSTRIP_WAIT_T0H();

                    data_pin.write(0);
                    LEDSTRIP_WAIT_T0L();
                }
            }
        }
    };
} // namespace r2d2::led_strip
