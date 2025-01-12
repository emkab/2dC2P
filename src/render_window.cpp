#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "render_window.hpp"
#include "entity.hpp"
#include "ball.hpp"
#include "tools.hpp"

Render_Window::Render_Window(const char *p_title, int p_w, int p_h, float p_scale, SDL_Color p_bg) : window(nullptr), renderer(nullptr), scale(p_scale)
{
    bg = p_bg;
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if (window == nullptr)
        std::cout << "Window initialization failed: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *Render_Window::loadTexture(const char *p_filePath)
{
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == nullptr)
        std::cout << "Failed to load texture " << p_filePath << ": " << SDL_GetError() << std::endl;

    return texture;
}

void Render_Window::cleanUp()
{
    SDL_DestroyWindow(window);
}

void Render_Window::clear()
{
    SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
    SDL_RenderClear(renderer);
}

SDL_Rect Render_Window::getWindowSize()
{
    SDL_Rect size = SDL_Rect{.x = 0, .y = 0};
    SDL_GetWindowSize(window, &size.w, &size.h);
    return size;
}

float Render_Window::getScale() { return scale; }
float Render_Window::setScale(float p_scale)
{
    scale = p_scale;
    return scale;
}

void Render_Window::render(Entity &p_entity)
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

void Render_Window::render(Ball &p_ball, int type)
{
    if (type == 0)
        tools::DrawCircle(renderer, Vector(p_ball.x * (int)scale, p_ball.y * (int)scale).toPoint(), p_ball.getRadius() * scale, p_ball.getColor());
    else if (type == 1)
        tools::DrawFullCircle(renderer, Vector(p_ball.x * (int)scale, p_ball.y * (int)scale).toPoint(), p_ball.getRadius() * scale, p_ball.getColor());
}

void Render_Window::display()
{
    SDL_RenderPresent(renderer);
}