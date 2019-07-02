#include "rgb_c.hpp"


bool r2d2::led_strip::rgb_c::operator==(const rgb_c &rhs) const {
    return  red     == rhs.red      &&
            green   == rhs.green    &&
            blue    == rhs.blue; 
}

r2d2::led_strip::rgb_c r2d2::led_strip::rgb_c::operator*(const int rhs) const {
    return rgb_c(red * rhs, green * rhs, blue * rhs );

}

r2d2::led_strip::rgb_c & r2d2::led_strip::rgb_c::operator+=(const rgb_c & rhs) {
    red = red + rhs.red;
    green = green + rhs.green;
    blue = blue + rhs.blue;
    return *this;
}

r2d2::led_strip::rgb_c & r2d2::led_strip::rgb_c::operator*=(const int & rhs ) {
    red = red * rhs;
    green = green * rhs;
    blue = blue * rhs;
    return *this;
}