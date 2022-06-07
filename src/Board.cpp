//
// Created by Тимур Краснянский on 09.04.2022.
//

#include <iostream>
#include <random>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Board.h"


Board::Board(size_t width, size_t height): size{width, height} {
    field.reserve(width * height);
    for(size_t i = 0; i < width * height; ++i){
        field.push_back(std::make_unique<EmptyEntity>());
    }
}

void Board::reset() {
    for(size_t i = 0; i < getWidth() * getHeight(); ++i){
        field.push_back(std::make_unique<EmptyEntity>());
    }
}

void ConsoleBoard::draw() {
    for (size_t i = 0; i < field.size(); ++i){
        auto entity = getEntityAt(i);
        // Check if entity is of type Cell
        if (Board::isOfType<Cell>(entity)) {
            std::cout << "C";
        } else if (Board::isOfType<Organic>(entity)) {
            std::cout << "O";
        } else if (Board::isOfType<EmptyEntity>(entity)){
            std::cout << "E";
        } else if (Board::isOfType<Poison>(entity)){
            std::cout << "P";
        } else if (Board::isOfType<Wall>(entity)){
            std::cout << "W";
        } else {
            std::cout << "?";
        }
        if ((i + 1) % getWidth() == 0)
            std::cout << "\n";
    }
    std::cout << std::endl;
}

//template<typename T> requires (std::is_base_of_v<Board, T>)

void SFMLBoard::draw() {
    window->clear();
    // DRAW
    auto cellSize = 50.0f;

    for (size_t y = 0; y < getHeight(); ++y) {
        for (size_t x = 0; x < getWidth(); ++x) {
            auto entity = getEntityAt(x, y);
            // Check if entity is of type Cell
            if (Board::isOfType<Cell>(entity)) {
                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(cellSize, cellSize));
                rectangle.setOutlineColor(sf::Color::Red);
                rectangle.setOutlineThickness(5);
                rectangle.setPosition(x * cellSize, y * cellSize);
                window->draw(rectangle);
            } else if (Board::isOfType<Organic>(entity)) {

            } else if (Board::isOfType<EmptyEntity>(entity)) {

            } else if (Board::isOfType<Poison>(entity)) {

            } else if (Board::isOfType<Wall>(entity)) {

            } else {

            }
        }
    }
    //std::cout << "a";
    // END OF DRAW
    window->display();
}
