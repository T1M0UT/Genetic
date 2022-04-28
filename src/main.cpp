#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"

int main() {
    auto board = UIBoard(10, 10);
    board.init();
    board.draw();

    /*sf::RenderWindow window(sf::VideoMode(1600, 800), "SFML Application");
    //auto world = new SFMLGame::SFMLWorld(window);

    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //world->draw();
        //window.draw(shape);
        window.display();
    }*/
    return 0;
}
