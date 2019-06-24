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

    /**
     *  \brief
     *  function that sets the color of an individual led based on RGB values.
     *
     *  @param rgb a struct of rgb values
     *  The color is based of RGB values(red, green blue)
     *  The maximum values are 255
	 *  The minimum values are 0
     */
    void set_color(const rgb_s &rgb);

    /**
     *  \brief
     *  function that sets the color of an individual led based on HSV values.
     *
     *  @param hsv a struct of HSV values
     *  The color is based of HSV values
     *  The HSV values get transformed in to RGB values for ease of purpose.
     */
    void set_color(hsv_s &hsv);
    

	/**
     *  \brief
     *  function that increases or decreases the brightness by given percentage 0% - 255%
     *
     *  the brightness increases by the given percentage when above 100%
     *  the brightness decreases by the given percentage when below 100%
	 *  at 100% nothing happens
     */
    void set_brightness(const uint8_t &percentage);

    /**
     *  \brief
     * Function that returns a struct of RGB values
     * 
     *  @return returns a struct of RGB values
     */
    rgb_s get_color();

    };
} //namespace R2D2
