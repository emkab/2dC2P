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
    ballScene::ballScene(RenderWindow window) : e(Ball(0, 0, 10, SDL_Color{.r = 0, .g = 0, .b = 0, .a = 0}))
    {
        SDL_Rect windowSize = window.getWindowSize();

        SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass.png");

        floorPoint = (windowSize.h);
        grassPoint = (floorPoint / window.getScale()) - 32;

        for (int i = 0; i < windowSize.w / 32; i++)
        {
            entities.emplace_back(Entity(32 * i, grassPoint, grassTexture));
        }

        for (int i = 0; i < windowSize.w / 15; i++)
        {
            balls.emplace_back(Ball((32 * i) + 5, 10 * i, 10, SDL_Color{.r = 0, .g = 0, .b = 0, .a = 255}));
        }

        grassTextureSize = tools::get_Size(grassTexture);
        dampeningFactor = 0.85;
    };

    void ballScene::tick(RenderWindow window, float delta_Time)
    {
        for (Entity &entity : entities)
        {
            window.render(entity);
        }
        for (Ball &ball : balls)
        {
            if (ball.getY() < grassPoint - ball.getRadius())
                ball.setYVelocity(ball.getYVelocity() + (9.8 * delta_Time));
            ball.updatePosition();
            if (ball.getY() > grassPoint - ball.getRadius())
            {
                ball.setYVelocity(ball.getYVelocity() * -1 * dampeningFactor);
                ball.setY(grassPoint - ball.getRadius());
            }
            window.render(ball, 1);
        }
    }
}