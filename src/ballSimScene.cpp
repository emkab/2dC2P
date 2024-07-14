#include <iostream>
#include <stdio.h>
#include <math.h>
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
    ballSimScene::ballSimScene(RenderWindow window) : circle(Ball(0, 0, 10, SDL_Color{.r = 0, .g = 0, .b = 0, .a = 0}))
    {
        SDL_Rect windowSize = window.getWindowSize();

        srand((unsigned)time(NULL));

        addBall(windowSize.w / 2, windowSize.h / 3, 15, SDL_Color{.r = 255, .g = 165, .b = 0, .a = 255});

        Ball e(windowSize.w / 2, windowSize.h / 2, 250, SDL_Color{.r = 139, .g = 0, .b = 139, .a = 255});
        circle = e;
    };

    void ballSimScene::tick(RenderWindow window, float delta_Time_In)
    {
        delta_Time = delta_Time_In;
        for (Entity &entity : entities)
        {
            window.render(entity);
        }
        int index_x = 0;
        for (Ball &ball : balls)
        {

            int index_y = index_x;

            collideBall(ball);
            ball.updatePosition(delta_Time);
            std::cout << delta_Time << std::endl;
            window.render(ball, 1);
            index_x++;
        }
        window.render(circle, 0);
    }

    void ballSimScene::collideBall(Ball &ball)
    {
        int dx = circle.x - ball.x;
        int dy = circle.y - ball.y;

        float overlap = hypot(dx, dy) - (circle.getRadius() - ball.getRadius());
        // std::cout << overlap << std::endl;

        if (overlap >= 0)
        {
            std::cout << "True" << std::endl;
            float tangent = atan2(dy, dx);
            ball.angle = 2 * tangent - ball.angle;
            ball.speed *= ballConsts::elasticity;

            float angle = 0.5 * M_PI + tangent;
            ball.x += sin(angle) * overlap;
            ball.y -= cos(angle) * overlap;
        }
    }

    void ballSimScene::addBall(float x, float y, int radius, SDL_Color color)
    {
        balls.emplace_back(Ball(x, y, radius, color));
        balls.back().speed = 0.01;
        balls.back().angle = M_PI / 2;
    }
}