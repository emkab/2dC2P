#pragma once

#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Ball.hpp"

    class Scene
    {
    public:
        Scene(RenderWindow window);
        void tick(RenderWindow window, float delta_Time);
        void addBall(float x, float y, int radius, float mass, SDL_Color color);
        void mouseEvent(SDL_MouseButtonEvent &e);
        void help();

    private:
        SDL_Rect windowSize;
        std::vector<Entity> entities;
        std::vector<Ball> balls;
        Ball *findBalls(std::vector<Ball> *balls, float x, float y);
        int mouseX, mouseY;
        float delta_Time;
        TTF_Font *font;
    };