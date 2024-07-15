#include <filesystem>
#include <iostream>
#include <chrono>
#include <thread>
#include <SDL2/SDL.h>
#include <vector>

#include "RenderWindow.hpp"
#include "tools.hpp"
#include "scenes.hpp"
#include <unistd.h>

int main(int argc, char *argv[])
{
    using namespace std::chrono;
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL initialization error: " << SDL_GetError() << std::endl;

    RenderWindow window("2dC2P v1.0", 1280, 720, 1, tools::new_Color(0, 0, 0, 255));
    SDL_Rect windowSize = window.getWindowSize();

    bool running = true;

    SDL_Event event;

    long long last_Tick = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    float delta_Time = 0.0;
    int fps = 60;

    scenes::ballSimScene scene(window);

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
        scene.tick(window, delta_Time);
        window.display();
        last_Tick = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        std::this_thread::sleep_for(milliseconds(1000 / fps));
        // std::cout << "Delta Time: " << delta_Time << " " << now << ", " << last_Tick << std::endl;
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
