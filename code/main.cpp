#include "headers/ws2812_c.hpp"
#include "hwlib.hpp"

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    auto weg = hwlib::target::pin_out(hwlib::target::pins::d8);

    r2d2::led_strip::ws2812<4> ledjes(weg);

    //r2d2::led_strip::rgb_s kleur = {255, 0, 0};
    r2d2::led_strip::rgb_s kleur2 = {3, 0, 0};
    r2d2::led_strip::rgb_s off = {0, 0, 0};



    // ledjes.set_color(kleur);
    ledjes[0].set_color(kleur2);
    ledjes[1].set_color(off);
    ledjes[2].set_color(off);
    ledjes[3].set_color(off);

    
    ledjes.send();

    for (;;) {
        ledjes[0].set_color(kleur2);
        ledjes[1].set_color(off);
        ledjes[2].set_color(off);
        ledjes[3].set_color(off);
        ledjes.send();
        hwlib::wait_ms(10);
        ledjes[0].set_color(off);
        ledjes[1].set_color(kleur2);
        ledjes[2].set_color(off);
        ledjes[3].set_color(off);
        ledjes.send();
        hwlib::wait_ms(10);
        ledjes[0].set_color(off);
        ledjes[1].set_color(off);
        ledjes[2].set_color(kleur2);
        ledjes[3].set_color(off);
        ledjes.send();
        hwlib::wait_ms(10);
        ledjes[0].set_color(off);
        ledjes[1].set_color(off);
        ledjes[2].set_color(off);
        ledjes[3].set_color(kleur2);
        ledjes.send();
        hwlib::wait_ms(10);
    }
}