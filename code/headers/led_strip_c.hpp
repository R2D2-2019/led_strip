#pragma once

#include "led_c.hpp"

namespace r2d2::led_strip {
    template <unsigned int N>
    class led_strip_c {
    private:
        led_c led[N];

    public:
        /**
         *  \brief
         *  default constructor
         */
        led_strip_c(){};

        virtual void send() = 0;

        /**
         *  \brief
         *  function that increases or decreases all leds brightness by given
         * percentage 0% - 255%
         *
         *  the brightness increases by the given percentage when above 100%
         *  the brightness decreases by the given percentage when below 100% at
         * 100% nothing happens
         */
        void set_brightness(const uint8_t &percentage) {
            for (led_c single_led : led) {
                single_led.set_brightness(percentage);
            }
        }

        /**
         *  \brief
         *  [] operator that returns the led selected at x
         *
         *  prevents out of bound error by using the modulo
         */
        led_c &operator[](unsigned int x) {
            return led[x % N];
        }

        template <typename T>
        void set_color(const T &new_color) {
            for (led_c single_led : led) {
                single_led.set_color(new_color);
            }
        }
    };
} // namespace r2d2::led_strip
