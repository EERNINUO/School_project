#include "draw.h"
using namespace sf;

sf::Font font; //创建文字对象

Figure::Figure(uint16_t Width, uint16_t Height, Color Color, uint16_t Fps){
    width = Width;
    height = Height;
    color = Color;
    fps = Fps;

    if (!font.openFromFile("../fonts/simsun.ttc")) {   //如果加载失败，报错
        printf("load font error\n");
    }
}

void Figure::drawScatter(double* xdata, double* ydata, uint16_t size, Color Color, uint8_t point_size){
    auto window = RenderWindow(VideoMode({width, height}), "Figure");
    window.setFramerateLimit(fps);

    double x_lens;
    double y_lens;

    double x_max = xdata[0];
    double y_max = ydata[0];
    double x_min = xdata[0];
    double y_min = ydata[0];

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
            (x - x_min) * ((double)(width - 80 )/ x_lens) + 40, 
            height - (y - y_min) * ((double)(height - 80) / y_lens) - 40
        );
    };

    // 绘制坐标轴
    sf::Vertex axes[] = {
        Vertex{Vector2f(width - 40, height - 40), Color::Black},
        Vertex{Vector2f(40, height - 40), Color::Black},
        Vertex{Vector2f(40, height - 40), Color::Black},
        Vertex{Vector2f(40, 40), Color::Black}
    };

    Vertex axea_arrows[6];
    axea_arrows[0].position = Vector2f(width - 40, height - 40);
    axea_arrows[0].color = Color::Black;
    axea_arrows[1].position = Vector2f(width - 40 - 8.6, height - 40 - 8.6);
    axea_arrows[1].color = Color::Black;
    axea_arrows[2].position = Vector2f(width - 40 - 8.6, height - 40 + 8.6);
    axea_arrows[2].color = Color::Black;
    axea_arrows[3].position = Vector2f(40, 40);
    axea_arrows[3].color = Color::Black;
    axea_arrows[4].position = Vector2f(40 - 8.6, 40 + 8.6);
    axea_arrows[4].color = Color::Black;
    axea_arrows[5].position = Vector2f(40 + 8.6, 40 + 8.6);
    axea_arrows[5].color = Color::Black;

    // 绘制坐标轴上的刻度
    char x_max_str[10], y_max_str[10], x_min_str[10], y_min_str[10];
    snprintf(x_max_str, sizeof(x_min_str), "%.2f", x_max);
    snprintf(y_max_str, sizeof(y_min_str), "%.2f", y_max);
    snprintf(x_min_str, sizeof(x_max_str), "%.2f", x_min);
    snprintf(y_min_str, sizeof(y_max_str), "%.2f", y_min);

    Text text1(font, std::string(x_min_str), 20);
    Text text2(font, std::string(y_min_str), 20);
    Text text3(font, std::string(x_max_str), 20);
    Text text4(font, std::string(y_max_str), 20);
    text1.setFillColor(sf::Color::Black);
    text2.setFillColor(sf::Color::Black);
    text3.setFillColor(sf::Color::Black);
    text4.setFillColor(sf::Color::Black);
    text1.setPosition(sf::Vector2f(40, height - 40));  //位置
    text2.setPosition(sf::Vector2f(15, height - 40));
    text3.setPosition(sf::Vector2f(width - 80, height - 40));
    text4.setPosition(sf::Vector2f(15, 80));
    text2.setRotation(degrees(-90));
    text4.setRotation(degrees(-90));

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
        window.draw(axea_arrows, 6, PrimitiveType::Triangles);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(shapes, size * 3, PrimitiveType::Triangles);
        window.display();
    }
}

void Figure::drawLine(double *xdata, double *ydata, sf::Color Color){
    auto window = RenderWindow(VideoMode({width, height}), "Figure");
    window.setFramerateLimit(fps);

    double x_max = xdata[0]>xdata[1] ? xdata[0] : xdata[1];
    double y_max = ydata[0]>ydata[1] ? ydata[0] : ydata[1];
    double x_min = xdata[0]<xdata[1] ? xdata[0] : xdata[1];
    double y_min = ydata[0]<ydata[1] ? ydata[0] : ydata[1];
    double x_lens = x_max - x_min; // x轴长度
    double y_lens = y_max - y_min; // y轴长度

    // 坐标系变换
    auto toPixel = [&](double x, double y) {
        return Vector2f(
            (x - x_min) * ((double)(width-80 )/ x_lens) + 40, 
            height - (y - y_min) * ((double)(height-80) / y_lens) - 40
        );
    };

    // 绘制坐标轴
    sf::Vertex axes[] = {
        Vertex{Vector2f(width - 40, height - 40), Color::Black},
        Vertex{Vector2f(40, height - 40), Color::Black},
        Vertex{Vector2f(40, height - 40), Color::Black},
        Vertex{Vector2f(40, 40), Color::Black}
    };

    // 绘制坐标轴箭头
    Vertex axea_arrows[6];
    axea_arrows[0].position = Vector2f(width - 40, height - 40);
    axea_arrows[0].color = Color::Black;
    axea_arrows[1].position = Vector2f(width - 40 - 8.6, height - 40 - 8.6);
    axea_arrows[1].color = Color::Black;
    axea_arrows[2].position = Vector2f(width - 40 - 8.6, height - 40 + 8.6);
    axea_arrows[2].color = Color::Black;
    axea_arrows[3].position = Vector2f(40, 40);
    axea_arrows[3].color = Color::Black;
    axea_arrows[4].position = Vector2f(40 - 8.6, 40 + 8.6);
    axea_arrows[4].color = Color::Black;
    axea_arrows[5].position = Vector2f(40 + 8.6, 40 + 8.6);
    axea_arrows[5].color = Color::Black;

        char x_max_str[10], y_max_str[10], x_min_str[10], y_min_str[10];
    snprintf(x_max_str, sizeof(x_min_str), "%.2f", x_max);
    snprintf(y_max_str, sizeof(y_min_str), "%.2f", y_max);
    snprintf(x_min_str, sizeof(x_max_str), "%.2f", x_min);
    snprintf(y_min_str, sizeof(y_max_str), "%.2f", y_min);

    Text text1(font, std::string(x_min_str), 20);
    Text text2(font, std::string(y_min_str), 20);
    Text text3(font, std::string(x_max_str), 20);
    Text text4(font, std::string(y_max_str), 20);
    text1.setFillColor(sf::Color::Black);
    text2.setFillColor(sf::Color::Black);
    text3.setFillColor(sf::Color::Black);
    text4.setFillColor(sf::Color::Black);
    text1.setPosition(sf::Vector2f(40, height - 40));  //位置
    text2.setPosition(sf::Vector2f(15, height - 40));
    text3.setPosition(sf::Vector2f(width - 80, height - 40));
    text4.setPosition(sf::Vector2f(15, 80));
    text2.setRotation(degrees(-90));
    text4.setRotation(degrees(-90));

    // 绘制直线
    sf::Vertex line[] = {
        Vertex{toPixel(xdata[0], ydata[0]), Color},
        Vertex{toPixel(xdata[1], ydata[1]), Color},
    };

    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<Event::Closed>()){
                window.close();
            }
        }

        window.clear(color);
        window.draw(axes, 4, PrimitiveType::Lines);
        window.draw(axea_arrows, 6, PrimitiveType::Triangles);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(line, 2, PrimitiveType::Lines);
        window.display();
    }
}
