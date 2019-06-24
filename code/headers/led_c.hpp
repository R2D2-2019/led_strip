#pragma once

#include "hsv_s.hpp"
#include "rgb_s.hpp"
#include <stdint.h>

namespace r2d2::led_strip {
    class led_c {
private:
    rgb_s color;

public:
    led_c() {};

	template <typename T>
	led_c(const T &new_color) {
        set_color(new_color);
	}

    void set_color(const rgb_s &rgb);
    void set_color(const hsv_s &hsv);
    void set_brightness(const uint8_t &percentage);
    rgb_s get_color();

    };
} //namespace R2D2