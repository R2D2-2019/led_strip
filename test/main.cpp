#include "ostream"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "rgb_c.hpp"
#include "hwlib.hpp"
#include "ws2812b_c.hpp"

TEST_CASE("rgb equality check") {
    r2d2::led_strip::rgb_c colour(255, 255, 255);
    REQUIRE(colour == r2d2::led_strip::rgb_c(255,255,255));
}

TEST_CASE("rgb unequality check") {
    r2d2::led_strip::rgb_c x(255,255,255);
    REQUIRE(!(x == r2d2::led_strip::rgb_c(200,200,200)));
}

TEST_CASE("multiply by integer") {
    r2d2::led_strip::rgb_c x(50,50,50);
    r2d2::led_strip::rgb_c v = x * 3;
    REQUIRE(v == r2d2::led_strip::rgb_c(150,150,150));
}

TEST_CASE("multiply by integer; return value") {
    r2d2::led_strip::rgb_c v(10,10,10);
    r2d2::led_strip::rgb_c x = (v *= 3);
    REQUIRE(v == r2d2::led_strip::rgb_c(30,30,30));
    REQUIRE(x == r2d2::led_strip::rgb_c(30,30,30));
}

TEST_CASE("add rgb to rgb; return value") {
    r2d2::led_strip::rgb_c v(10,10,10);
    r2d2::led_strip::rgb_c x = (v += r2d2::led_strip::rgb_c(20,20,20));
    REQUIRE(v == r2d2::led_strip::rgb_c(30,30,30));
    REQUIRE(x == r2d2::led_strip::rgb_c(30,30,30));
}

TEST_CASE("returning [] operator with modulo") {
    hwlib::pin_out_test data_out;
    r2d2::led_strip::ws2812b_c<10> leds(data_out);
    REQUIRE(&leds[0] == &leds[10]);
}

TEST_CASE("HSV to RGB") {
    r2d2::led_strip::hsv_s color = {0, 0, 100};
    r2d2::led_strip::led_c led(color);
    REQUIRE(led.get_color() == r2d2::led_strip::rgb_c(255, 255, 255));

	color = {300, 100, 100};
    led.set_color(color);
    REQUIRE(led.get_color() == r2d2::led_strip::rgb_c(255, 0, 255));
}

TEST_CASE("set color for led strip and check single led") {
    hwlib::pin_out_test data_out;
    r2d2::led_strip::ws2812b_c<10> leds(data_out);
    leds.set_color(r2d2::led_strip::rgb_c(255, 255, 255));
    REQUIRE(leds[0].get_color() == r2d2::led_strip::rgb_c(255, 255, 255));
}

