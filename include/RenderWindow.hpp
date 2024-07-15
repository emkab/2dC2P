#pragma once
#include <SDL2/SDL.h>
#include "Ball.hpp"

class RenderWindow
{
public:
    RenderWindow(const char *p_title, int p_w, int p_h, float scale, SDL_Color p_bg);
    void cleanUp();
    void clear();
    SDL_Rect getWindowSize();
    float getScale();
    float setScale(float p_scale);
    void render(Ball &p_ball, int type);
    void display();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Color bg;
    float scale;
};
