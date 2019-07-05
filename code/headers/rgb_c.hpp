#pragma once

#include <stdint.h>

namespace r2d2::led_strip {
    /**
     *  \brief
     * rgb adt
     * \details
     * this is an ADT that implements rgb values
     * the appropiate operators & constructor are provided
     *  
     */
    class rgb_c {
    private:   
        uint8_t red;
        uint8_t green;
        uint8_t blue;

    public:
        rgb_c(const uint8_t & red, const uint8_t & green, const uint8_t & blue):
        red(red),
        green(green),
        blue(blue)
        {}

        /**
         * \brief
         * compare two rgb_c values
         * \details
         * This operator tests for equality. It returns true
         * if and only if the values of both operands are equal.
         *
         * @return returns true if both operands are equal 
         */    
        bool operator==(const rgb_c &rhs) const;

        /**
         * \brief
         * multiply a rgb_c by an integer
         * \details
         * This operator* multiplies a rational value by an integer value.
         */
        rgb_c operator*(const int rhs) const;

        /**
         * \brief
         * add a rgb_c to another rgb_c
         * \details
         * This operator+= adds a rgb_c value to a rgb_c value
         */
        rgb_c & operator+=(const rgb_c & rhs);

        /** 
         * \brief
         * multiply a rgb_c with an integer
         * \details
         * This operator *= multiplies a rgb_c with an integer.
         */
        rgb_c & operator*=(const int & rhs );
    };
}