#pragma once

#include "led_strip_c.hpp"
#include "hwlib.hpp"

namespace r2d2::led_strip {
	template <unsigned int N>
    class ws2812 : public led_strip_c<N> {
    private:
        const uint16_t time_0_high_ns = 350;
        const uint16_t time_0_low_ns  = 800;
        const uint16_t time_1_high_ns = 700;
        const uint16_t time_1_low_ns  = 600;
        const uint16_t time_reset_us  = 50;

        hwlib::pin_out &data_pin;
        void send(const rgb_s &rgb) override;

    public:
        ws2812(hwlib::pin_out &data_out) 
			: data_pin(data_out){};
    };
} // namespace r2d2::led_strip
