#include "headers/ws2812b_c.hpp"
#include "hwlib.hpp"

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    auto weg = hwlib::target::pin_out(hwlib::target::pins::d8);

    r2d2::led_strip::ws2812b_c<100> ledjes(weg);

    //r2d2::led_strip::rgb_c kleur = {3, 0, 0};
    r2d2::led_strip::rgb_c kleur2 = {10, 10, 10};
    //r2d2::led_strip::rgb_c off = {255, 255, 255};



	
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