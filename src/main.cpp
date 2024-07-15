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
#include "scenes.hpp"
#include <unistd.h>

int main(int argc, char *argv[])
{
    using namespace std::chrono;
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL initialization error: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG initialization failed: " << SDL_GetError() << std::endl;

    RenderWindow window("2dC2P v1.0", 1280, 720, 1, tools::newColor(0, 0, 0, 255));
    SDL_Rect windowSize = window.getWindowSize();

    bool running = true;

    SDL_Event event;

    long long last_Tick = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    float delta_Time = 0.0;
    int fps = 60;

    int ballCount = 3;
    if (argc > 1)
        ballCount = *argv[1] - '0';

    bool gravity;
    std::string gravity_p(argv[2]);
    if (gravity_p == "true")
        gravity = true;
    else if (gravity_p == "false")
        gravity = false;
    else
        gravity = true;

    bool randDensity;
    std::string randDensity_p(argv[3]);
    if (randDensity_p == "true")
        randDensity = true;
    else if (randDensity_p == "false")
        randDensity = false;
    else
        randDensity = true;

    scenes::ballSimScene scene(window, ballCount, randDensity);

    while (running == true)
    {
        long long now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        delta_Time = (now - last_Tick) / 1000.0;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                scene.mouseEvent(event.button);
                break;

            case SDL_MOUSEBUTTONUP:
                scene.mouseEvent(event.button);
                break;
            }
        }
        window.clear();
        scene.tick(window, delta_Time, gravity);
        window.display();
        last_Tick = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        std::this_thread::sleep_for(milliseconds(1000 / fps));
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
