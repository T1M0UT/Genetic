//
// Created by Тимур Краснянский on 11.04.2022.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "SFMLWorld.h"

using namespace SFMLGame;


void SFMLWorld::draw() {
    sf::RectangleShape rectangle(sf::Vector2f(40, 40));
    rectangle.setFillColor(sf::Color(150, 50, 250));
    _window.draw(rectangle);
}


SFMLWorld::SFMLWorld(sf::RenderWindow &window): World(window.getSize().x, window.getSize().y),
    _window(window), entities(list<int>{}) {
    scale = 10;
}
