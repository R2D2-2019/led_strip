#include <game_c.hpp>

bool game_c::check_collision()
{
    if(ball.get_x() == 1 && ball.direction_x = -1 && (ball.get_y() == peddle.get_y() || ball.get_y()+1 == peddle.get_y()+1 || ball.get_y()+1 == peddle.get_y()+2 ))
    {
        ball.swap_direction_x();
    }
    else if(ball.get_x() == 9 && ball.direction_x = 1 && (ball.get_y() == peddle.get_y() || ball.get_y()+1 == peddle.get_y()+1 || ball.get_y()+1 == peddle.get_y()+2 ))
    {
        ball.swap_direction_x();
    }

    if((ball.get_y() == 10 && ball.get_direction_y() == 1) || (ball.get_y() == 0 && ball.get_direction_y() == -1) )
    {
        ball.swap_direction_y();
    }
}

void game_c::update_game()
{
    screen.clear();
    for(unsigned int i = 0; i < 3; i++)
    {
        screen.draw(peddle_one.get_x(), peddle_one.get_y()+i, {20,0,0});
        screen.draw(peddle_two.get_x(), peddle_two.get_y()+i, {0,20,0});
    }
    screen.draw(ball.get_x(), ball.get_y(), {0,0,20});
    screen.update();
    hwlib::wait_ms(250);
}