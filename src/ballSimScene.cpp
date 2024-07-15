#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>
#include <chrono>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Ball.hpp"
#include "tools.hpp"

#include "scenes.hpp"

namespace scenes
{
    ballSimScene::ballSimScene(RenderWindow window, bool gravity) : circle(Ball(0, 0, 10, 1, tools::newColor(0, 0, 0, 0)))
    {
        SDL_Rect windowSize = window.getWindowSize();

        srand((unsigned)time(NULL));

        // addBall(windowSize.w / 2, windowSize.h / 3, 15, tools::newColor(255, 165, 0, 255));
        // addBall(windowSize.w / 3, windowSize.h / 3, 15, tools::newColor(255, 165, 0, 255));
        // addBall(windowSize.w / 1.5, windowSize.h / 3, 15, tools::newColor(255, 165, 0, 255));
        addBallGrid(windowSize.w / 2, windowSize.h / 2, 15, 3, 3, gravity, tools::newColor(255, 165, 0, 255));

        Ball e(windowSize.w / 2, windowSize.h / 2, 250, 100, tools::newColor(139, 0, 139, 255));
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

            int index_y = index_x + 1;

            collideCircle(ball);
            ball.updatePosition(delta_Time, false);

            if (&ball == selectedBall)
            {
                SDL_GetMouseState(&mouseX, &mouseY);
                float dx = mouseX - selectedBall->x;
                float dy = mouseY - selectedBall->y;
                selectedBall->angle = atan2(dy, dx) + 0.5 * M_PI;
                selectedBall->speed = hypot(dx, dy) * 0.75;
            }

            while (index_y < balls.size())
            {
                collide(ball, balls.at(index_y));
                index_y++;
            }

            window.render(ball, 1);
            index_x++;
        }
        window.render(circle, 0);
    }

    void ballSimScene::collideCircle(Ball &ball)
    {
        int dx = circle.x - ball.x;
        int dy = circle.y - ball.y;

        float overlap = hypot(dx, dy) - (circle.getRadius() - ball.getRadius());

        if (overlap >= 0)
        {
            float tangent = atan2(dy, dx);
            ball.angle = 2 * tangent - ball.angle;
            ball.speed *= ballConsts::elasticity;

            float angle = 0.5 * M_PI + tangent;
            ball.x += sin(angle) * overlap;
            ball.y -= cos(angle) * overlap;
        }
    }

    void ballSimScene::collide(Ball &b1, Ball &b2)
    {
        float dx = b1.x - b2.x;
        float dy = b1.y - b2.y;

        float distance = hypot(dx, dy);
        if (distance < b1.radius + b2.radius)
        {
            float tangent = atan2(dy, dx);
            float angle = 0.5 * M_PI + tangent;
            float total_mass = b1.mass + b2.mass;

            Vector v1 = tools::addALVectors(Vector(b1.angle, b1.speed * (b1.mass - b2.mass) / total_mass), Vector(angle, 2 * b2.speed * b2.mass / total_mass));
            b1.angle = v1.x;
            b1.speed = v1.y;

            Vector v2 = tools::addALVectors(Vector(b2.angle, b2.speed * (b2.mass - b1.mass) / total_mass), Vector(angle + M_PI, 2 * b1.speed * b1.mass / total_mass));
            b2.angle = v2.x;
            b2.angle = v2.y;

            b1.speed *= ballConsts::elasticity;
            b2.speed *= ballConsts::elasticity;

            float overlap = 0.5 * (b1.radius + b2.radius - distance + 1);

            b1.x += sin(angle) * overlap;
            b1.y -= cos(angle) * overlap;
            b2.x -= sin(angle) * overlap;
            b2.y += cos(angle) * overlap;
        }
    }

    void ballSimScene::addBall(float x, float y, int radius, float mass, SDL_Color color)
    {
        balls.emplace_back(Ball(x, y, radius, mass, color));
        balls.back().speed = 0.01;
        balls.back().angle = M_PI / 2;
    }

    void ballSimScene::addBallGrid(float x, float y, int radius, float mass, int count, bool randDensity, SDL_Color color)
    {
        int spacing = radius / 2;

        int width = ((count * (radius * 2)) / 3);
        x -= width + spacing;
        y -= width + spacing;

        int i = 0;
        int j = 0;
        while (i < count * count)
        {
            if (!randDensity)
                addBall(x, y, radius, mass, color);
            else
            {
                int rad = (rand() % 10) + 11;
                spacing = rad / 2;
                int density = (rand() % 20) + 1;
                color = tools::newColor(200 - density * 10, 200 - density * 10, 255, 255);
                addBall(x, y, rad, density * pow(rad, 2), color);
            }
            if (j != count - 1)
            {
                x += (radius * 2) + spacing;
                j++;
            }
            else
            {
                x -= ((radius * 2) + spacing) * j;
                y += (radius * 2) + spacing;
                j = 0;
            }

            i++;
        }
    }

    void ballSimScene::mouseEvent(SDL_MouseButtonEvent &e)
    {
        switch (e.state)
        {
        case SDL_PRESSED:
        {
            Ball *b = findBalls(&balls, e.x, e.y);
            if (b != NULL)
                selectedBall = b;
            else
                break;

            selectedBallOriginalColor = selectedBall->getColor();
            selectedBall->setColor(tools::newColor(255, 0, 0, 255));
            break;
        }

        case SDL_RELEASED:
        {
            if (selectedBall != NULL)
            {
                selectedBall->setColor(selectedBallOriginalColor);
                selectedBall = NULL;
                break;
            }
            break;
        }
        }
    }

    Ball *ballSimScene::findBalls(std::vector<Ball> *balls, float x, float y)
    {
        for (Ball &b : *balls)
        {
            if (hypot(b.x - x, b.y - y) <= b.radius)
            {
                return &b;
            }
        }
        return NULL;
    }
}