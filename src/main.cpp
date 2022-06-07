#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game.h"

int main() {
    auto width = 10;
    auto height = 10;
    auto board = createBoard<ConsoleBoard>(width, height);
    //board->window = new sf::RenderWindow{sf::VideoMode(width * 100, height * 100), "SFML Application"};
    // Board *board, int numberOfCPUs, GameParams params
    auto params = new GameParams{};
    auto game = new Game{board, 1, params};
    while(true) {
        board->draw();
        game->iteration();
        std::cin.get();
    }
    /* auto b = game->getBoard();
    auto sfmlboard = dynamic_cast<SFMLBoard*>(b);
    while (sfmlboard->window->isOpen()) {
        sf::Event event;

        while (sfmlboard->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                sfmlboard->window->close();
        }

        sfmlboard->draw();
        game->iteration();
    }

    //auto world = new SFMLGame::SFMLWorld(window);
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);
    */
    return 0;
}
