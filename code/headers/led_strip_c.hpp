#pragma once

#include "led_c.hpp"

namespace r2d2::led_strip {
    template <unsigned int N>
    class led_strip_c {
    private:
        led_c led[N];

	protected:
        virtual void send(const rgb_s &rgb) = 0;

    public:
        /**
         *  \brief
         *  default constructor
         */
        led_strip_c() {};

		void show();
        void set_brightness(const uint8_t &percentage);

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