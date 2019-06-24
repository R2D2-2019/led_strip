#include "ws2812_c.hpp"

template <unsigned int N>
inline void r2d2::led_strip::ws2812<N>::send(const rgb_s &rgb) {
    uint8_t green = rgb.green;
    uint8_t red   = rgb.red;
    uint8_t blue  = rgb.blue;

	for (unsigned int i = 0; i < 8; i++) {
        if (green & 128 == 128) {
			data_pin.write(true);
            hwlib::wait_ns(time_1_high_ns);
            data_pin.write(false);
            hwlib::wait_ns(time_1_low_ns);
        } else {
            data_pin.write(true);
            hwlib::wait_ns(time_0_high_ns);
            data_pin.write(false);
            hwlib::wait_ns(time_0_low_ns);
		}
        green <<= 1;
    }

	for (unsigned int i = 0; i < 8; i++) {
        if (red & 128 == 128) {
            data_pin.write(true);
            hwlib::wait_ns(time_1_high_ns);
            data_pin.write(false);
            hwlib::wait_ns(time_1_low_ns);
        } else {
            data_pin.write(true);
            hwlib::wait_ns(time_0_high_ns);
            data_pin.write(false);
            hwlib::wait_ns(time_0_low_ns);
        }
        red <<= 1;
    }

	for (unsigned int i = 0; i < 8; i++) {
        if (blue & 128 == 128) {
			data_pin.write(true);
            hwlib::wait_ns(time_1_high_ns);
            data_pin.write(false);
            hwlib::wait_ns(time_1_low_ns);
        } else {
            data_pin.write(true);
            hwlib::wait_ns(time_0_high_ns);
            data_pin.write(false);
            hwlib::wait_ns(time_0_low_ns);
		}
        blue <<= 1;
    }

}

