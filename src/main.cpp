#include <filesystem>
#include <iostream>
#include <chrono>
#include <thread>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "tools.hpp"
#include <unistd.h>

int main(int argc, char *argv[])
{
    using namespace std::chrono;
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDl initialization error: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG initialization failed: " << SDL_GetError() << std::endl;

    RenderWindow window("FLUIDSIM v1.0", 1280, 720, 4);

    SDL_Texture *dirtTexture = window.loadTexture("res/gfx/ground_dirt.png");
    SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass.png");
    SDL_Texture *onionTexture = window.loadTexture("res/gfx/Onion-Sheet.png");

    std::vector<Entity> entities;

    for (int i = 0; i < 10; i++)
    {
        entities.emplace_back(Entity(32 * i, 32 * 4.7, grassTexture));
    }

    Entity onion(128, 0, onionTexture);

    bool running = true;

    SDL_Event event;

    long long last_Tick = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    float delta_Time = 0.0;
    int fps = 60;

    SDL_Point grassTextureSize = tools::getsize(grassTexture);

    while (running == true)
    {
        long long now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        delta_Time = (now - last_Tick) / 1000.0;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }
        window.clear();
        for (Entity &entity : entities)
        {
            window.render(entity);
        }
        if (onion.getY() < 32 * 4.7 - grassTextureSize.y)
            onion.setYVelocity(onion.getYVelocity() + 0.05);
        else
        {
            onion.setYVelocity(0);
            onion.setY(32 * 4.7 - grassTextureSize.y);
        }
        onion.updatePosition();
        window.render(onion);
        window.display();
        last_Tick = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        std::this_thread::sleep_for(milliseconds(1000 / fps));
        std::cout << "Delta Time: " << delta_Time << " " << now << ", " << last_Tick << std::endl;
        std::cout << onion.getY() << ", " << grassTextureSize.y << std::endl;
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
