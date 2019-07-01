#include <stdint.h>

class ball_c
{
private:
    uint8_t x_axis;
    uint8_t y_axis;
    bool direction_x;
    bool direction_y;
public:
ball_c(uint8_t x_axis, uint8_t y_axis, bool direction_x, bool direction_y):
    x_axis(x_axis),
    y_axis(y_axis),
    direction_x(direction_x),
    direction_y(direction_y)
    {}

    void update_ball();
    uint8_t check_x();
    uint8_t check_y();
    bool get_direction_x();
    bool get_direction_y();
    void swap_direction_x();
    void swap_direction_y();
};