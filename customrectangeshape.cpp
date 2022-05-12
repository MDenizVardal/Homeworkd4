#include "customrectangeshape.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

CustomRectangeShape::CustomRectangeShape(sf::Vector2f size,sf::Vector2f position)
{
    rectangle.setSize(size);
    rectangle.setPosition(position);

}
void CustomRectangeShape::setFillColor(sf::Color c){
    rectangle.setFillColor(c);
}
void CustomRectangeShape::setSpeed(int x,int y,int r){
   m_speed_x=x;
   m_speed_y=y;
   m_speed_r=r;
}
void CustomRectangeShape::animate(const sf::Time &elapsed){

}
void CustomRectangeShape::setBounds(int x0, int x1, int y0,int y1){
    bound_x0=x0;
    bound_x1=x1;
    bound_y0=y0;
    bound_y1=y1;
}
