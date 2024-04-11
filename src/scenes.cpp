#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "tools.hpp"

#include "scenes.hpp"

namespace scenes
{
    testScene::testScene(RenderWindow window) : e(Entity(0, 0, window.loadTexture("res/gfx/blank.png")))
    {
        SDL_Rect windowSize = window.getWindowSize();

        SDL_Texture *dirtTexture = window.loadTexture("res/gfx/ground_dirt.png");
        SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass.png");
        SDL_Texture *onionTexture = window.loadTexture("res/gfx/Onion-Sheet.png");

        floorPoint = (windowSize.h / window.getScale()) - 32;

        for (int i = 0; i < 10; i++)
        {
            entities.emplace_back(Entity(32 * i, floorPoint, grassTexture));
        }

        Entity onion(128, 0, onionTexture);
        e = onion;

        grassTextureSize = tools::get_Size(grassTexture);
    };

    void testScene::tick(RenderWindow window, float delta_Time)
    {
        for (Entity &entity : entities)
        {
            window.render(entity);
        }
        if (e.getY() < floorPoint - grassTextureSize.y)
            e.setYVelocity(e.getYVelocity() + (9.8 * delta_Time));
        e.updatePosition();
        if (e.getY() > floorPoint - grassTextureSize.y)
        {
            e.setYVelocity(0);
            e.setY(floorPoint - grassTextureSize.y);
        }
        window.render(e);
    }
}