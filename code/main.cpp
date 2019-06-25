#include "headers/ws2812_c.hpp"
#include "hwlib.hpp"

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    auto weg = hwlib::target::pin_out(hwlib::target::pins::d8);

    r2d2::led_strip::ws2812<2> ledjes(weg);

    r2d2::led_strip::rgb_s kleur = {0, 0, 0};
    r2d2::led_strip::rgb_s kleur2 = {0, 0, 20};

    // ledjes.set_color(kleur);
    ledjes[0].set_color(kleur2);
    ledjes[1].set_color(kleur);
    
    ledjes.send();

    for (;;) {
        //ledjes.send();
    }
}