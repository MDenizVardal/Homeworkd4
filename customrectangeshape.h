#ifndef CUSTOMRECTANGESHAPE_H
#define CUSTOMRECTANGESHAPE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class CustomRectangeShape:public sf::RectangleShape
{
private:
    int m_speed_x = 0;
    int m_speed_y=0;
    int m_speed_r=0;
    int bound_x0=0;
    int bound_x1=0;
    int bound_y0=0;
    int bound_y1=0;

public:
    sf::RectangleShape rectangle;
    CustomRectangeShape(sf::Vector2f size,sf::Vector2f position);
    void setFillColor(sf::Color c);
    void setSpeed(int x,int y,int r);
    void animate(const sf::Time &elapsed);
    void setBounds(int x0, int x1, int y0,int y1);
};

#endif // CUSTOMRECTANGESHAPE_H
