#include <SDL2/SDL.h>
#include <iostream>
#include "RenderWindow.hpp"
#include "Ball.hpp"
#include "tools.hpp"

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h, float p_scale, SDL_Color p_bg) : window(nullptr), renderer(nullptr), scale(p_scale)
{
    bg = p_bg;
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if (window == nullptr)
        std::cout << "Window initialization failed: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
    SDL_RenderClear(renderer);
}

SDL_Rect RenderWindow::getWindowSize()
{
    SDL_Rect size = SDL_Rect{.x = 0, .y = 0};
    SDL_GetWindowSize(window, &size.w, &size.h);
    return size;
}

float RenderWindow::getScale() { return scale; }
float RenderWindow::setScale(float p_scale)
{
    scale = p_scale;
    return scale;
}

void RenderWindow::render(Ball &p_ball, int type)
{
    if (type == 0)
        tools::DrawCircle(renderer, Vector(p_ball.x * (int)scale, p_ball.y * (int)scale).toPoint(), p_ball.getRadius() * scale, p_ball.getColor());
    else if (type == 1)
        tools::DrawFullCircle(renderer, Vector(p_ball.x * (int)scale, p_ball.y * (int)scale).toPoint(), p_ball.getRadius() * scale, p_ball.getColor());
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}
