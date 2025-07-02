#ifndef _DRAW_H_
#define _DRAW_H_

#include <SFML/Graphics.hpp>
#include <cmath>

class Figure{
    private:
        uint16_t height;
        uint16_t width;
        sf::Color color;
        uint16_t fps;

    public:
        Figure(uint16_t Width= 800, uint16_t Height= 600, sf::Color Color= sf::Color::White, uint16_t Fps= 60);
        void drawScatter(double* xdata, double* ydata, uint16_t size, sf::Color Color= sf::Color::Red, uint8_t point_size= 10);
        void drawLine(double *xdata, double *ydata, sf::Color Color= sf::Color::Red);
};

#endif