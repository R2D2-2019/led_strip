#include <paddle_c.hpp>

void paddle_c::move_to(const uint8_t &new_x, const uint8_t &new_y) {
    x_axis = new_x;
    y_axis = new_y;

}

uint8_t paddle_c::get_x() {
    return x_axis;
}
uint8_t paddle_c::get_y() {
    return y_axis;
}