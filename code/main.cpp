#include "headers/ws2812b_c.hpp"
#include "headers/screen_c.hpp"
#include "headers/game_c.hpp"
#include "headers/HC_SR04_c.hpp"
#include "hwlib.hpp"

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    auto data_out = hwlib::target::pin_out(hwlib::target::pins::d8);

    r2d2::led_strip::ws2812b_c<100> leds(data_out);

	r2d2::led_strip::screen_c screen (10, 10, leds);



    auto echo_pin = hwlib::target::pin_in(hwlib::target::pins::d2);
    auto trigger_pin = hwlib::target::pin_out(hwlib::target::pins::d3);

	
    auto echo_pin2 = hwlib::target::pin_in(hwlib::target::pins::d12);
    auto trigger_pin2 = hwlib::target::pin_out(hwlib::target::pins::d11);

    R2D2::Distance::HC_SR04_c sensor1(echo_pin, trigger_pin);
    R2D2::Distance::HC_SR04_c sensor2(echo_pin2, trigger_pin2);


	game_c game(screen, sensor1, sensor2);



    for (;;) {
            game.update_game();
			
		
    }
}