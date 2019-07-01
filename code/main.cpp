#include "headers/ws2812_c.hpp"
#include "hwlib.hpp"

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    auto weg = hwlib::target::pin_out(hwlib::target::pins::d8);

    r2d2::led_strip::ws2812<100> ledjes(weg);

    //r2d2::led_strip::rgb_s kleur = {3, 0, 0};
    r2d2::led_strip::rgb_s kleur2 = {10, 10, 10};
    //r2d2::led_strip::rgb_s off = {255, 255, 255};



	
	ledjes.set_color(kleur2);

    
    ledjes.send();

    for (;;) {
		//ledjes.set_brightness(110);
		
		ledjes.set_color(kleur2);
		//ledjes[0].set_color(off);
		ledjes.send();
		hwlib::wait_ms(200);
		//kleur2.red++;
		
    }
}