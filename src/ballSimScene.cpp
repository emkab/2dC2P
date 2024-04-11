#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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

        floorPoint = (windowSize.h);

        balls.emplace_back(windowSize.w / 2, windowSize.h / 2, 15, SDL_Color{.r = 255, .g = 165, .b = 0, .a = 255});
        balls.at(0).setXVelocity(1 + (rand() % 3));
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
        for (Ball &ball : balls)
        {
            ball.setYVelocity(ball.getYVelocity() + 4);
            double distance = tools::getDistance(SDL_Point{.x = ball.getX(), .y = ball.getY()}, SDL_Point{.x = e.getX(), .y = e.getY()});
            float collisionX = tools::isCollidingBigCircleX(ball.getX(), ball.getRadius(), e.getX(), e.getRadius(), distance);
            if (collisionX != 0)
            {
                std::cout << "X"
                          << ", " << collisionX << std::endl;
                ball.setXVelocity(ball.getXVelocity() * -1 * dampeningFactor);
                ball.setX(ball.getX() - collisionX / ball.getRadius());
            }
            float collisionY = tools::isCollidingBigCircleY(ball.getY(), ball.getRadius(), e.getY(), e.getRadius(), distance);
            if (collisionY != 0)
            {
                std::cout << "Y"
                          << ", " << collisionY << std::endl;
                ball.setYVelocity(ball.getYVelocity() * -1 * dampeningFactor);
                ball.setY(ball.getY() - collisionY / ball.getRadius());
            }

            if ((collisionX != 0 || collisionY != 0) && ball.getName() == "B")
            {
                addBall(SDL_Point{.x = ball.getX(), .y = ball.getY()}, ball.getRadius(), ball.getColor());
            }

            ball.updatePosition();
            window.render(ball, 1);
        }
        window.render(e, 0);
    }

    void ballSimScene::addBall(SDL_Point point, int radius, SDL_Color color)
    {
        balls.emplace_back(Ball(point.x, point.y, radius, color));
        balls.back().setXVelocity(1 + (rand() % 3));
    }
}