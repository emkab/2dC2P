#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Ball.hpp"
#include "tools.hpp"

#include "scenes.hpp"

namespace scenes
{
    ballSimScene::ballSimScene(RenderWindow window) : e(Ball(0, 0, 10, SDL_Color{.r = 0, .g = 0, .b = 0, .a = 0}))
    {
        SDL_Rect windowSize = window.getWindowSize();

        srand((unsigned)time(NULL));

        floorPoint = (windowSize.h);

        balls.emplace_back(windowSize.w / 2, windowSize.h / 2, 15, SDL_Color{.r = 255, .g = 165, .b = 0, .a = 255});
        balls.at(0).setXVelocity((rand() % 5) * tools::randomSign());
        std::cout << balls.at(0).getXVelocity() << ", " << tools::randomSign() << ", " << rand() << std::endl;
        balls.at(0).setName("B");

        Ball b1(windowSize.w / 2, windowSize.h / 2, 250, SDL_Color{.r = 139, .g = 0, .b = 139, .a = 255});
        e = b1;

        dampeningFactor = 0.95;
    };

    void ballSimScene::tick(RenderWindow window, float delta_Time)
    {
        for (Entity &entity : entities)
        {
            window.render(entity);
        }
        int index_x = 0;
        for (Ball &ball : balls)
        {
            ball.setYVelocity(ball.getYVelocity() + 9.8 * 3 * delta_Time);

            int index_y = index_x;
            for (Ball &ball1 : balls)
            {
                if (index_x == index_y)
                    continue;
                if (tools::isCollidingCircleX(ball.getX(), ball.getRadius(), ball1.getX(), ball1.getRadius()))
                {
                    ball1.setXVelocity(ball1.getXVelocity() + ball.getXVelocity() / 2);
                    ball.setXVelocity(ball.getXVelocity() * -1 / 2);
                }
                if (tools::isCollidingCircleY(ball.getY(), ball.getRadius(), ball1.getY(), ball1.getRadius()))
                {
                    ball1.setYVelocity(ball1.getYVelocity() + ball.getYVelocity() / 2);
                    ball.setYVelocity(ball.getYVelocity() * -1 / 2);
                }
                index_y++;
            }

            double distance = tools::getDistance(SDL_Point{.x = ball.getX(), .y = ball.getY()}, SDL_Point{.x = e.getX(), .y = e.getY()});
            float collisionX = tools::isCollidingBigCircleX(ball.getX(), ball.getRadius(), e.getX(), e.getRadius(), distance);
            if (collisionX != 0)
            {
                ball.setXVelocity(ball.getXVelocity() * -1 * dampeningFactor);
                ball.setX(ball.getX() - collisionX * delta_Time);
            }
            float collisionY = tools::isCollidingBigCircleY(ball.getY(), ball.getRadius(), e.getY(), e.getRadius(), distance);
            if (collisionY != 0)
            {
                ball.setYVelocity(ball.getYVelocity() * -1 * dampeningFactor);
                ball.setY(ball.getY() - collisionY * delta_Time);
            }

            if ((collisionX != 0 || collisionY != 0) && ball.getName() == "B")
            {
                addBall(SDL_Point{.x = ball.getX(), .y = ball.getY()}, ball.getRadius(), SDL_Color{.r = 255, .g = 255, .b = 0, .a = 255});
            }

            ball.updatePosition();
            window.render(ball, 1);
            index_x++;
        }
        window.render(e, 0);
    }

    void ballSimScene::addBall(SDL_Point point, int radius, SDL_Color color)
    {
        balls.emplace_back(Ball(point.x, point.y, radius, color));
        balls.back().setXVelocity(balls.at(0).getXVelocity());
    }
}