#pragma once

#include <stdint.h>

namespace r2d2::led_strip {
    /**
     *  \brief
     *  Struct which contains the hue, saturation and value
     */
    struct hsv_s {
        uint16_t hue;
	    uint8_t saturation;
        uint8_t value;
    };
} // namespace r2d2::led_strip
