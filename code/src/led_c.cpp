#include "led_c.hpp"

void r2d2::led_strip::led_c::set_color(const rgb_s &rgb) {
    color = rgb;
}

void r2d2::led_strip::led_c::set_color(const hsv_s &hsv) {
	//this doesn't work
    //color = hsv;
}

void r2d2::led_strip::led_c::set_brightness(const uint8_t &percentage) {
    color = color;
}

r2d2::led_strip::rgb_s r2d2::led_strip::led_c::get_color() {
    return color;
}