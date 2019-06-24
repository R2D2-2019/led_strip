#pragma once

#include "hsv_s.hpp"
#include "rgb_s.hpp"

namespace r2d2::led_strip {
    class led_c {
private:
    rgb_s color;

public:
    /**
     *  \brief
     *  empty constructor
	 *
	 *  an empty constructor that allows the object to be build without a color
     */
    led_c() {};

	/**
     *  \brief
     *  templated constructor for both colors or even more
     *
     *  a templated constructor that calls the set_color function with its own templated argument
	 *  this argument can either be a rgb or hsv value
     */
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