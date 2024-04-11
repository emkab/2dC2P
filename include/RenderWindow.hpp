#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"

class RenderWindow
{
public:
    RenderWindow(const char *p_title, int p_w, int p_h, float scale);
    SDL_Texture *loadTexture(const char *p_filePath);
    void cleanUp();
    void clear();
    float getScale();
    float setScale(float p_scale);
    void render(Entity &p_entity);
    void display();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    float scale;
};
