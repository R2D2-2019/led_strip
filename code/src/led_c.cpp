#include "led_c.hpp"

void r2d2::led_strip::led_c::set_color(const rgb_s &rgb) {
    color = rgb;
}

void r2d2::led_strip::led_c::set_color(const hsv_s &hsv) {
	//this doesn't work
    //color = hsv;
}

void r2d2::led_strip::led_c::set_brightness(const uint8_t &percentage) {
    uint16_t red   = color.red * percentage / 100;
    uint16_t green = color.red * percentage / 100;
    uint16_t blue  = color.red * percentage / 100;

	color.red   = (red   > 255)  ? 255 : red;
    color.green = (green > 255)  ? 255 : green;
    color.blue  = (green > blue) ? 255 : blue;
}

r2d2::led_strip::rgb_s r2d2::led_strip::led_c::get_color() {
    return color;
}