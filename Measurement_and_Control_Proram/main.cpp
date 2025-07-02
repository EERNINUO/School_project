#include <iostream>
#include "inc/matrix.h"
#include "inc/draw.h"

int main() {
    double a[9] = { 1, 2, 3, 
                4, 5, 6, 
                7, 8, 9};
    double b[9];

    for(int i = 0; i < 9; i++){
        b[i] = a[i] * a[i];
    }

    Figure f1(800, 600, sf::Color::White);
    f1.drawScatter(a, b, 9);

    double a1[2] = {1, 4};
    double a2[2] = {4, 5};

    Figure f2(800, 600, sf::Color::White);
    f2.drawLine(a1, a2, sf::Color::Green);

    return 0;
}


