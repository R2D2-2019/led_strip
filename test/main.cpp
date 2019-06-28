#include "ostream"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "rgb_s.hpp"

TEST_CASE("rgb ==operator, true") {
    r2d2::led_strip::rgb_s colour = {255, 255, 255};
    REQUIRE(colour == r2d2::led_strip::rgb_s{255,255,255});
}

TEST_CASE("rgb ==operator, false") {
    r2d2::led_strip::rgb_s colour = {255, 255, 255};
    REQUIRE(!(colour == r2d2::led_strip::rgb_s{0,0,0}));
}