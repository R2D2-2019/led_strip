#include <hwlib.hpp>
#include <HC_SR04_c.hpp>
#include <screen_c.hpp>
#include <ball_c.hpp>
#include <peddle_c.hpp>

class game_c
{
private:
    screen_c & screen;
    HC_SR04_c & sensor_one;
    HC_SR04_c & sensor_two;
    peddle_c peddle_one;
    peddle_c peddle_two;
    ball_c ball;
public:
game_c(screen_c & screen, HC_SR04 & sensor_one, HC_SR04 & sensor_two):
    screen(screen),
    sensor_one(sensor_one),
    sensor_two(sensor_two)
    {}

    bool check_collision();

    void update_game();
    
}//gianluca is bea