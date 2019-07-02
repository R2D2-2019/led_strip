#include <stdint.h>

class ball_c
{
private:
    uint8_t x_axis;
    uint8_t y_axis;
    uint8_t direction_x;
    uint8_t direction_y;
public:
ball_c(uint8_t x_axis, uint8_t y_axis, uint8_t direction_x, uint8_t direction_y):
    x_axis(x_axis),
    y_axis(y_axis),
    direction_x(direction_x),
    direction_y(direction_y)
    {
        if(direction_x > 1)
        {
            direction_x = 1;
        }
        else if(direction_x < -1)
        {
            direction_x = -1;
        }
        if(direction_y > 1)
        {
            direction_y = 1;
        }
        else if(direction_y < -1)
        {
            direction_y = -1;
        }
        if(x_axis > 5 || x_axis < 5)
        {
            x_axis = 5;
        }
        else if(y_axis > 5 || y_axis < 5)
        {
            y_axis = 5;
        }
    }

    void update_ball();
    uint8_t check_x();
    uint8_t check_y();
    bool get_direction_x();
    bool get_direction_y();
    void swap_direction_x();
    void swap_direction_y();
};