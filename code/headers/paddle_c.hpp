#include <stdint.h>


class paddle_c {
private:
    uint8_t x_axis;
    uint8_t y_axis;

public:
    paddle_c(const uint8_t & x_axis, const uint8_t & y_axis):
    x_axis(x_axis),
    y_axis(y_axis)
    {}
    void move_to(const uint8_t &new_x, const uint8_t &new_y);
    uint8_t get_x();
    uint8_t get_y();

};