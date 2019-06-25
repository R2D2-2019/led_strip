#pragma once

#include "led_strip_c.hpp"
#include "hwlib.hpp"

namespace r2d2::led_strip {
	template <unsigned int N>
    class ws2812 : public led_strip_c<N> {
    private:
        const uint16_t time_0_high_ns = 350;
        const uint16_t time_0_low_ns  = 800;
        const uint16_t time_1_high_ns = 700;
        const uint16_t time_1_low_ns  = 600;
        const uint16_t time_reset_us  = 50;

		uint8_t grb[3];

        hwlib::pin_out &data_pin;
        

    public:
        ws2812(hwlib::pin_out &data_out) 
			: data_pin(data_out){};

		void send() override {
            data_pin.write(false);
            data_pin.flush();
            hwlib::wait_us(70);
            uint16_t time;
            uint16_t time2;
            for (unsigned int current_led = 0; current_led < N; current_led++) {
                //hwlib::cout << "     ";
                rgb_s color = (*this)[current_led].get_color();
                grb[0] = color.green;
                grb[1] = color.red;
                grb[2] = color.blue;

                for (auto sending_color : grb) {
                    for (unsigned int i = 0; i < 8; i++) {
                        if ((sending_color & 128) == 128) {
                            //hwlib::cout << "1";
                            data_pin.write(true);
                            //data_pin.flush();
                            time = hwlib::now_us();
                            hwlib::wait_ns_busy(time_1_high_ns);
                            time2 = hwlib::now_us();
                            data_pin.write(false);
                            //data_pin.flush();
                            hwlib::wait_ns_busy(time_1_low_ns);
                        } else {
                            //hwlib::cout << "0";
                            data_pin.write(true);
                            //data_pin.flush();
                            hwlib::wait_ns_busy(time_0_high_ns);
                            data_pin.write(false);
                            //data_pin.flush();
                            hwlib::wait_ns_busy(time_0_low_ns);
                        }
                        sending_color <<= 1;
                    }
                }
            }
		}
    };
} // namespace r2d2::led_strip
