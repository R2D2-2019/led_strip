#include "ostream"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "rgb_c.hpp"

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