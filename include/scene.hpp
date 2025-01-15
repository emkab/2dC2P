#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "renderWindow.hpp"
#include "entity.hpp"
#include "ball.hpp"

class Scene
{
public:
    explicit Scene(RenderWindow window)
    {
        SDL_Rect windowSize = window.getWindowSize();

        srand((unsigned)time(NULL));

        std::cout << "Scene Initialized." << std::endl;
    };
    void tick(RenderWindow window, float delta_Time_In)
    {
        delta_Time = delta_Time_In;
        for (Entity &entity : entities)
        {
            window.render(entity);
        }
        int index_x = 0;
        for (Ball &ball : balls)
        {
            int index_y = index_x + 1;

            // Insert logic

            window.render(ball, 1);
            index_x++;
        }
    };
    void addBall(float x, float y, int radius, float mass, SDL_Color color)
    {
        balls.emplace_back(Ball(x, y, radius, mass, color));
        balls.back().speed = 0.01;
        balls.back().angle = M_PI / 2;
    };
    void mouseEvent(SDL_MouseButtonEvent &e)
    {
        if (e.button == SDL_BUTTON_LEFT)
        {
            switch (e.state)
            {
            case SDL_PRESSED:
            {
                // Insert logic
                break;
            }

            case SDL_RELEASED:
            {
                // Insert logic
                break;
            }
            }
        }
    };
    void help()
    {
        std::cout << "Argument format:" << std::endl;
        // Insert prints
        std::cout << "TBD" << std::endl;
    };

private:
    SDL_Rect windowSize;
    std::vector<Entity> entities;
    std::vector<Ball> balls;
    Ball *findBalls(std::vector<Ball> *balls, float x, float y)
    {
        for (Ball &b : *balls)
        {
            if (hypot(b.x - x, b.y - y) <= b.radius)
            {
                return &b;
            }
        }
        return NULL;
    };
    int mouseX, mouseY;
    float delta_Time;
    TTF_Font *font;
};