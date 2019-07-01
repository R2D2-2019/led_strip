#include <stdint.h>

class ball_c
{
private:
    uint8_t x_axis;
    uint8_t y_axis;
    bool direction;
public:
ball_c(uint8_t x_axis, uint8_t y_axis, bool direction):
    x_axis(x_axis),
    y_axis(y_axis),
    direction(direction)
    {}

    void move_ball(uint8_t x, uint8_t y);
}