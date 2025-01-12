#include <filesystem>
#include <iostream>
#include <chrono>
#include <thread>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "RenderWindow.hpp"
#include "scene.hpp"
#include "Entity.hpp"
#include "tools.hpp"
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ballCount = 3;
    if (argc > 1)
    {
        if (std::string(argv[1]) == "-h" | std::string(argv[1]) == "-help" | std::string(argv[1]) == "h" | std::string(argv[1]) == "help")
        {
            std::cout << "Argument format:" << std::endl;
            std::cout << "--  ./main.exe ballCount[int] gravity[bool] randDensity[bool] randSpeed[int] momentumLoss[bool]" << std::endl;
            std::cout << "In-game keybinds:" << std::endl;
            std::cout << "--  Left-Click: Grab ball" << std::endl;
            std::cout << "--  Middle-Click: Toggle momentum loss" << std::endl;
            std::cout << "--  Right-Click: Toggle gravity" << std::endl;
            return 0;
        }
        else
            ballCount = *argv[1] - '0';
    }

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


    Scene scene(window);

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
        scene.tick(window, delta_Time);
        window.display();
        last_Tick = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        std::this_thread::sleep_for(milliseconds(1000 / fps));
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
