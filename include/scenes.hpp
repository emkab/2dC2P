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
    class ballScene
    {
    public:
        ballScene(RenderWindow window);
        void tick(RenderWindow window, float delta_Time);

    private:
        SDL_Rect windowSize;
        std::vector<Entity> entities;
        std::vector<Ball> balls;
        double floorPoint;
        double grassPoint;
        double dampeningFactor;
        SDL_Point grassTextureSize;
        Ball e;
    };

    class ballSimScene
    {
    public:
        ballSimScene(RenderWindow window);
        void tick(RenderWindow window, float delta_Time);
        void addBall(SDL_Point point, int radius, SDL_Color color);

    private:
        SDL_Rect windowSize;
        std::vector<Entity> entities;
        std::vector<Ball> balls;
        double floorPoint;
        double grassPoint;
        double dampeningFactor;
        SDL_Point grassTextureSize;
        Ball e;
    };
}