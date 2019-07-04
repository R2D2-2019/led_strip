#pragma once

#include <stdint.h>
#include "led_strip_c.hpp"

namespace r2d2::led_strip {
	template <unsigned int N>
    class screen_c {
    private:
        uint16_t width, height;
        led_strip_c<N> &leds;
    public:
        screen_c(const uint16_t &width, const uint16_t &height,
                 led_strip_c<N> &leds) 
			: width(width), height(height), leds(leds) {}

		void draw(const uint16_t &x, const uint16_t &y, const rgb_s &color = {10,10,10}) {
            uint16_t index = (y % 2 == 1) ? ((width - x) - 1) : (x);
            index += y * height;
            leds[index].set_color(color);		
		}

        void clear(const rgb_s &color = {0, 0, 0}) {
            leds.set_color(color);
        }

        void update() {
            leds.send();
        }
    };
} // namespace r2d2::led_strip