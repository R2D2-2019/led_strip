#include <ball_c.hpp>

void ball_c::update_ball()
{
    if(direction_x && x_axis <= 9)
    {
        x_axis += 1;
    }
    else if(!direction_x && x_axis >=1)
    {
        x_axis -= 1;
    }
    if(direction_y && y_axis <= 9)
    {
        y_axis += 1;
    }
    else if(!direction_y && y_axis >= 1)
    {
        y_axis -= 1;
    }
}

uint8_t ball_c::check_x()
{
    return x_axis;
}

uint8_t ball_c::check_y()
{
    return y_axis;
}

bool ball_c::get_direction_x()
{
    return direction_x;
}

bool ball_c::get_direction_y()
{
    return direction_y;
}

void ball_c::swap_direction_x()
{
    direction_x *= -1;
}

void ball_c::swap_direction_y()
{
    direction_y *= -1;
}