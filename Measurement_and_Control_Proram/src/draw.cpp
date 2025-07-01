#include "draw.h"
using namespace sf;

Figure::Figure(uint16_t Width, uint16_t Height, Color Color, uint16_t Fps){
    width = Width;
    height = Height;
    color = Color;
    fps = Fps;
}

void Figure::drawScatter(double* xdata, double* ydata, uint16_t size, Color Color, uint8_t point_size){
    auto window = RenderWindow(VideoMode({width, height}), "Figure");
    window.setFramerateLimit(fps);

    uint16_t x_lens;
    uint16_t y_lens;

    int x_max = xdata[0];
    int y_max = ydata[0];
    int x_min = xdata[0];
    int y_min = ydata[0];

    // 找到最大最小值
    for(uint16_t i = 1; i < size; i++){ 
        if (xdata[i] > x_max) x_max = xdata[i];
        if (xdata[i] < x_min)  x_min = xdata[i];
        if (ydata[i] > y_max)  y_max = ydata[i];
        if (ydata[i] < y_min)  y_min = ydata[i];
    }
    x_lens = x_max - x_min; // x轴长度
    y_lens = y_max - y_min; // y轴长度

    // 坐标系变换
    auto toPixel = [&](double x, double y) {
        return Vector2f(
            (x - x_min) * ((double)(width-40 )/ x_lens) + 20, 
            height - (y - y_min) * ((double)(height-40) / y_lens) - 20
        );
    };

    // 绘制坐标轴
    sf::Vertex axes[] = {
        Vertex{Vector2f(width - 20, height - 20), Color::Black},
        Vertex{Vector2f(20, height - 20), Color::Black},
        Vertex{Vector2f(20, height - 20), Color::Black},
        Vertex{Vector2f(20, 20), Color::Black}
    };

    // Vertex shapes[6];
    // shapes[0].position = Vector2f(width - 20, height - 20);
    // shapes[0].color = Color::Black;
    // shapes[1].position = Vector2f(width - 20 - 8.6, height - 20 + 8.6);
    // shapes[1].color = Color::Black;
    // shapes[2].position = Vector2f(width - 20 + 8.6, height - 20 + 8.6);
    // shapes[2].color = Color::Black;

    // 绘制散点
    Vertex shapes[size*3];
    for(uint16_t i = 0; i < size; i++){
        Vector2f point = toPixel(xdata[i], ydata[i]);
        shapes[3*i + 0].position = Vector2f(point.x, point.y - point_size);
        shapes[3*i + 0].color = Color;
        shapes[3*i + 1].position = Vector2f(point.x - 0.86*point_size, point.y + 0.86*point_size);
        shapes[3*i + 1].color = Color;
        shapes[3*i + 2].position = Vector2f(point.x + 0.86*point_size, point.y + 0.86*point_size);
        shapes[3*i + 2].color = Color;
    } 

    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<Event::Closed>()){
                window.close();
            }
        }

        window.clear(color);
        window.draw(axes, 4, PrimitiveType::Lines);
        window.draw(shapes, size * 3, PrimitiveType::Triangles);
        window.display();
    }
}
