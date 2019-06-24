#include "led_c.hpp"

void r2d2::led_strip::led_c::set_color(const rgb_s &rgb) {
    color = rgb;
}

void r2d2::led_strip::led_c::set_color(hsv_s &hsv) {
    hsv.hue         = (hsv.hue > 360)       ? 360   : hsv.hue; 
    hsv.saturation  = (hsv.saturation > 1)  ? 1     : hsv.saturation;
    hsv.value       = (hsv.value > 1)       ? 1     : hsv.value;

    //set c x & m values
    uint8_t c = hsv.value * hsv.saturation;
    //be sure it is absolute
    uint8_t result = (hsv.hue / 60) % 2 - 1;
    uint8_t x = c * (1 - result);
    uint8_t m = hsv.value - c;
    rgb_s newrgb;

    //decide the new r,g,b values
    switch(hsv.hue) {
        case 0 ... 59:
           newrgb = {c, x, 0};
            break;
        case 60 ... 119:
            newrgb = {x, c, 0};
            break;
        case 120 ... 179:
            newrgb = {0, c, x};
            break;
        case 180 ... 239:
            newrgb = {0, x, c};
            break;
        case 240 ... 299:
            newrgb = {x, 0 , c};
            break;
        case 300 ... 360:
            newrgb = {c, 0, x};
            break;
        default:
            newrgb = {255,0,0};
            break;
    }
    //calculate the new rgb values
    uint8_t new_red = (newrgb.red + m) * 255;
    uint8_t new_green = (newrgb.green + m) * 255;
    uint8_t new_blue = (newrgb.blue + m) * 255;
    newrgb = {new_red, new_green, new_blue};

    set_color(newrgb);
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