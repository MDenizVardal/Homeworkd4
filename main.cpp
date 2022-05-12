#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "customrectangeshape.h"

int main() {

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    std::srand(std::time(nullptr));

    std::vector<CustomRectangeShape> rectangles;
    for(int i=0; i<10; i++)
    {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangeShape(size, position));
    }

    for(auto &rec : rectangles)
    {
        rec.setFillColor(sf::Color(0, 255, 0));
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(100, 200, 10);
    }



    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyReleased)
                {
                    if(event.key.code == sf::Keyboard::Space)
                        std::cout << "Space released ddd" << std::endl;
                }

                if(event.type == sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                        std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                        for(auto &rec : rectangles)
                            {
                              sf::Vector2f position=rec.rectangle.getPosition();
                              if(position.x<mouse_pos.x && position.x+120>mouse_pos.x && position.y<mouse_pos.y && position.y+60>mouse_pos.y ){
                                  rec.rectangle.setFillColor(sf::Color(255, 0, 0));
                              }else{
                                  rec.rectangle.setFillColor(sf::Color(0, 255, 0));
                              }

                            }


                    }
                }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
/*
        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);

        window.draw(triangle);
        */

        for(auto &rec : rectangles)
            {
                window.draw(rec.rectangle);

            }
        // end the current frame
        window.display();
    }

    return 0;
}
