#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h, float p_scale, SDL_Color p_bg) : window(nullptr), renderer(nullptr), scale(p_scale)
{
    bg = p_bg;
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if (window == nullptr)
        std::cout << "Window initialization failed: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *RenderWindow::loadTexture(const char *p_filePath)
{
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == nullptr)
        std::cout << "Failed to load texture " << p_filePath << ": " << SDL_GetError() << std::endl;

    return texture;
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

void RenderWindow::render(Entity &p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getX() * scale;
    dst.y = p_entity.getY() * scale;
    dst.w = p_entity.getCurrentFrame().w * scale;
    dst.h = p_entity.getCurrentFrame().h * scale;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}
