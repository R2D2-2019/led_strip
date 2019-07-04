#include <HC_SR04_c.hpp>
#include <ball_c.hpp>
#include <hwlib.hpp>
#include <paddle_c.hpp>
#include <screen_c.hpp>

template <unsigned int N>
class game_c {
private:
    r2d2::led_strip::screen_c<N> &screen;
    R2D2::Distance::HC_SR04_c &sensor_one;
    R2D2::Distance::HC_SR04_c &sensor_two;
    paddle_c paddle_one;
    paddle_c paddle_two;
    ball_c ball;
    int score_one, score_two;
    int game_timer;
    uint8_t num[10][15] = {{1, 1, 1,
							1, 0, 1, 
							1, 0, 1, 
							1, 0, 1, 
							1, 1, 1},

						   {0, 0, 1,
							0, 0, 1, 
							0, 0, 1,
							0, 0, 1, 
							0, 0, 1},
			
						   {1, 1, 1, 
							0, 0, 1, 
							1, 1, 1, 
							1, 0, 0, 
							1, 1, 1},

						   {1, 1, 1, 
							0, 0, 1, 
							1, 1, 1, 
							0, 0, 1, 
							1, 1, 1},

						   {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
						   {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
						   {1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
						   {1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
						   {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
						   {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}};

public:
    game_c(r2d2::led_strip::screen_c<N> &screen,
           R2D2::Distance::HC_SR04_c &sensor_one,
           R2D2::Distance::HC_SR04_c &sensor_two)
        : screen(screen),
          sensor_one(sensor_one),
          sensor_two(sensor_two),
          paddle_one(1, 0),
          paddle_two(1, 9),
          ball(4, 6, 1, 1),
          score_one(0),
          score_two(0),
          game_timer(0) {
    }

    bool player_collision() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((ball.get_y() - 1) == paddle_one.get_y()) {
                    if ((ball.get_x() + (i - 1)) == (paddle_one.get_x() + j)) {
                        if ((ball.get_direction_x() == (i - 1))) {
                            return true;
                        }
                    }
                } else if ((ball.get_y() + 1) == paddle_two.get_y()) {
                    if ((ball.get_x() + (i - 1)) == (paddle_two.get_x() + j)) {
                        if ((ball.get_direction_x() == (i - 1))) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    void check_collision() {

        /*if (((ball.get_y() + 1) == paddle_two.get_y()) &&
            (ball.get_x() == paddle_two.get_x() + 1)) {
            ball.swap_direction_y();
        } else if (((ball.get_y() - 1) == paddle_one.get_y()) &&
                   (ball.get_x() == paddle_one.get_x() + 1)) {
            ball.swap_direction_y();
        }*/
        if (ball.get_x() == 9 || ball.get_x() == 0) {
            ball.swap_direction_x();
        }

        if (player_collision()) {
            ball.swap_direction_y();
        }

        if (ball.get_y() == 9) {

            screen.draw(ball.get_x(), ball.get_y(), {20, 0, 0});
            screen.update();
            hwlib::wait_ms(500);
            screen.clear();
            screen.update();
            hwlib::wait_ms(200);
            screen.draw(ball.get_x(), ball.get_y(), {20, 0, 0});
            screen.update();
            hwlib::wait_ms(500);
            screen.clear();
            screen.update();

            ball.move_ball(4, 8);
            ball.swap_direction_y();

			score_one++;
			if (score_one > 9)
			{
                            screen.clear({30, 0, 0});
                            screen.update();
                            hwlib::wait_ms(2000);
                            score_one = 0;
                            score_two = 0;

			}

        } else if (ball.get_y() == 0) {

            screen.draw(ball.get_x(), ball.get_y(), {0, 0, 20});
            screen.update();
            hwlib::wait_ms(500);
            screen.clear();
            screen.update();
            hwlib::wait_ms(200);
            screen.draw(ball.get_x(), ball.get_y(), {0, 0, 20});
            screen.update();
            hwlib::wait_ms(500);
            screen.clear();
            screen.update();
            ball.move_ball(4, 1);
            ball.swap_direction_y();

			score_two++;

			if (score_two > 9) {
                            screen.clear({0, 0, 30});
                            screen.update();
                            hwlib::wait_ms(2000);
                            score_two = 0;
                            score_one = 0;

                        }
        }
    }

    void update_game() {
        screen.clear();

        if (game_timer == 14) {
            check_collision();
            ball.update_ball();
            game_timer = 0;
        }

        draw_score(6, 6, {20, 0, 0}, num[score_one]);
        draw_score(1, 7, {0, 0, 20}, num[score_two], true);

        for (unsigned int i = 0; i < 3; i++) {
            screen.draw(paddle_one.get_x() + i, paddle_one.get_y(), {20, 0, 0});
            screen.draw(paddle_two.get_x() + i, paddle_two.get_y(), {0, 0, 20});
        }
        int result = sensor_one.get_distance() / 10;
        result = (result < 10) ? 0 : (result - 10);
        result = (int)(result / 5);
        result = (result > 7) ? 7 : result;
        paddle_one.move_to(result, paddle_one.get_y());

        result = sensor_two.get_distance() / 10;
        result = (result < 10) ? 0 : (result - 10);
        result = (int)(result / 5);
        result = (result > 7) ? 7 : result;
        paddle_two.move_to(result, paddle_two.get_y());

        screen.draw(ball.get_x(), ball.get_y(), {30, 30, 30});
        screen.update();
        hwlib::wait_ms(10);
        ++game_timer;
    }

    void draw_score(int x, int y, r2d2::led_strip::rgb_s rgb, uint8_t number[],
                    bool mirror = false) {
        for (unsigned int i = 0; i < 15; i++) {
            if (!mirror) {
                if (number[i]==1)
                    screen.draw(x + (i % 3), y - (int)(i/3), rgb);
            } else {
                if (number[14 - i]==1)
                    screen.draw(x + (i % 3), y - (int)(i / 3), rgb);
            }
        }
    }

       

}; // gianluca is bea