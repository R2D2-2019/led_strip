#include "led_strip_c.hpp"

template <unsigned int N>
void r2d2::led_strip::led_strip_c<N>::set_brightness(const uint8_t &percentage) {
    for (led_c single_led : led) {
        single_led.set_brightness(percentage);
    }
}

template <unsigned int N>
void r2d2::led_strip::led_strip_c<N>::show() {
    for (led_c single_led : led) {
        send(single_led.color);
    }
}