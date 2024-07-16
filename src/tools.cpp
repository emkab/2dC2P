#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "tools.hpp"
#include <Vector.hpp>

namespace tools
{
    int randomSign()
    {
        srand((unsigned)time(NULL));
        int rnd = 1 + (rand() % 2);
        if (rnd == 1)
            return 1;
        else
            return -1;
    }

    double normalize(double x)
    {
        return x / abs(x);
    }

    double getDistance(SDL_Point p1, SDL_Point p2)
    {
        return sqrt((pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
    }

    double getDistance(int p1, int p2)
    {
        return std::max(p1, p2) - std::min(p1, p2);
    }

    SDL_Point get_Size(SDL_Texture *texture)
    {
        SDL_Point size;
        SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
        return size;
    }

    SDL_Color newColor(Uint8 p_r, Uint8 p_g, Uint8 p_b, Uint8 p_a)
    {
        return SDL_Color{.r = p_r, .g = p_g, .b = p_b, .a = p_a};
    }

    // rounding helper, simplified version of the function I use
    int roundUpToMultipleOfEight(int v)
    {
        return (v + (8 - 1)) & -8;
    }

    void DrawFullCircle(SDL_Renderer *renderer, SDL_Point center, int radius, SDL_Color color)
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        // 35 / 49 is a slightly biased approximation of 1/sqrt(2)
        const int arrSize = roundUpToMultipleOfEight(radius * 8 * 35 / 49);
        SDL_Point points[arrSize];
        int drawCount = 0;

        const int32_t diameter = (radius * 2);

        int32_t x = (radius - 1);
        int32_t y = 0;
        int32_t tx = 1;
        int32_t ty = 1;
        int32_t error = (tx - diameter);

        while (x >= y)
        {
            points[drawCount + 0] = {center.x + x, center.y - y};
            points[drawCount + 1] = {center.x + x, center.y + y};
            points[drawCount + 2] = {center.x - x, center.y - y};
            points[drawCount + 3] = {center.x - x, center.y + y};
            points[drawCount + 4] = {center.x + y, center.y - x};
            points[drawCount + 5] = {center.x + y, center.y + x};
            points[drawCount + 6] = {center.x - y, center.y - x};
            points[drawCount + 7] = {center.x - y, center.y + x};

            drawCount += 8;

            if (error <= 0)
            {
                ++y;
                error += ty;
                ty += 2;
            }

            if (error > 0)
            {
                --x;
                tx += 2;
                error += (tx - diameter);
            }
        }

        // SDL_RenderDrawPoints(renderer, points, drawCount);
        SDL_RenderDrawLines(renderer, points, drawCount);
    }

    void DrawCircle(SDL_Renderer *renderer, SDL_Point center, int radius, SDL_Color color)
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        // 35 / 49 is a slightly biased approximation of 1/sqrt(2)
        const int arrSize = roundUpToMultipleOfEight(radius * 8 * 35 / 49);
        SDL_Point points[arrSize];
        int drawCount = 0;

        const int32_t diameter = (radius * 2);

        int32_t x = (radius - 1);
        int32_t y = 0;
        int32_t tx = 1;
        int32_t ty = 1;
        int32_t error = (tx - diameter);

        while (x >= y)
        {
            points[drawCount + 0] = {center.x + x, center.y - y};
            points[drawCount + 1] = {center.x + x, center.y + y};
            points[drawCount + 2] = {center.x - x, center.y - y};
            points[drawCount + 3] = {center.x - x, center.y + y};
            points[drawCount + 4] = {center.x + y, center.y - x};
            points[drawCount + 5] = {center.x + y, center.y + x};
            points[drawCount + 6] = {center.x - y, center.y - x};
            points[drawCount + 7] = {center.x - y, center.y + x};

            drawCount += 8;

            if (error <= 0)
            {
                ++y;
                error += ty;
                ty += 2;
            }

            if (error > 0)
            {
                --x;
                tx += 2;
                error += (tx - diameter);
            }
        }

        SDL_RenderDrawPoints(renderer, points, drawCount);
        // SDL_RenderDrawLines(renderer, points, drawCount);
    }

    Vector addALVectors(Vector v1, Vector v2)
    {
        float x = sin(v1.x) * v1.y + sin(v2.x) * v2.y;
        float y = cos(v1.x) * v1.y + cos(v2.x) * v2.y;

        float length = hypot(x, y);
        float angle = 0.5 * M_PI - atan2(y, x);
        return Vector(angle, length);
    }

    void write(std::string text, int x, int y, SDL_Color color, TTF_Font *font)
    {
        // Unimplented for efficiency sake.
    }

}