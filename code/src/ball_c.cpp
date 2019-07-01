#include <ball_c.hpp>

void ball_c::move_ball(uint8_t x, uint8_t y)
{
    x_axis += x;
    y_axis += y; 
}

uint8_t ball_c::check_x()
{
    return x_axis;
}

uint8_t ball_c::check_y()
{
    return y_axis;
}