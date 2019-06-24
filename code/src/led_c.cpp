#include "led_c.hpp"

void set_color(const R2D2::led_strip::rgb_s *rgb) {
    color = rgb;
}

void set_color(const R2D2::led_strip::hsv_s *hsv) {
    color = hsv;
}

void set_brightness(const uint8_t *percentage) {
    color = color;
}

R2D2::led_strip::rgb_s get_color() {
    return color;
}