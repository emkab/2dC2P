#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"

namespace scenes
{
    class testScene
    {
    public:
        testScene(RenderWindow window);
        void tick(RenderWindow window, float delta_Time);

    private:
        SDL_Rect windowSize;
        std::vector<Entity> entities;
        double floorPoint;
        SDL_Point grassTextureSize;
        Entity e;
    };
}