#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Ball.hpp"

namespace scenes
{
    class ballSimScene
    {
    public:
        ballSimScene(RenderWindow window);
        void tick(RenderWindow window, float delta_Time);
        void addBall(float x, float y, int radius, SDL_Color color);

    private:
        SDL_Rect windowSize;
        std::vector<Entity> entities;
        std::vector<Ball> balls;
        void collideBall(Ball &ball);
        float delta_Time;
        double dampeningFactor;
        Ball circle;
    };
}