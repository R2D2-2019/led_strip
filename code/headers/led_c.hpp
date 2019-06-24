#pragma once

#include "hsv_s.hpp"
#include "rgb_s.hpp"

namespace R2D2::led_strip {
    class led_c {
private:
    rgb_s color;

public:
    void set_color(const rgb_s *rgb);
    void set_color(const hsv_s *hsv);
    void set_brightness(const uint8_t *percentage);
    rgb_s get_color();

    };
} //namespace R2D2