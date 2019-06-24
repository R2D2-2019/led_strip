#pragma once

#include "hsv_s.hpp"
#include "rgb_s.hpp"
#include <stdint.h>

namespace R2D2::led_strip {
    class led_c {
private:
    R2D2::led_strip::rgb_s color;

public:
    void set_color(const R2D2::led_strip::rgb_s *rgb);
    void set_color(const R2D2::led_strip::hsv_s *hsv);
    void set_brightness(const uint8_t *percentage);
    R2D2::led_strip::rgb_s get_color();

    };
} //namespace R2D2