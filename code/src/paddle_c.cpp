#include <paddle_c.hpp>

void paddle_c::move_to(const uint8_t & new_y) {
    y_axis = (new_y < 3) ? 3 : new_y;
    y_axis = (new_y > 10) ? 10 : new_y;

}