//
// Created by Тимур Краснянский on 09.04.2022.
//

#ifndef GENETIC_BOARD_H
#define GENETIC_BOARD_H

#include <memory>
#include <array>
#include <vector>
#include <random>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entities.h"


class Board {
    using Field = std::vector<std::unique_ptr<Entity>>;
    using Size  = std::tuple<size_t, size_t>;

public:
    Board(size_t width, size_t height);
    [[nodiscard]] size_t getWidth() const { return std::get<0>(size); } // TODO: Does inline make sense here?
    [[nodiscard]] size_t getHeight() const { return std::get<1>(size); }
    Entity* getEntityAt(size_t i) { return field.at(i).get(); }
    inline Entity* getEntityAt(size_t x, size_t y) { return getEntityAt(x + y * getWidth()); }
    void setEntityAt(Entity* entity, size_t i) { field[i].reset(entity); }
    void setEntityAt(Entity* entity, size_t x, size_t y) { setEntityAt(entity, x + y * getWidth()); }
    virtual void draw() = 0;

    void swap(size_t i, size_t j) { std::swap(field[i], field[j]); }
    void swap(size_t x1, size_t y1, size_t x2, size_t y2) { swap(x1 + y1 * getWidth(), x2 + y2 * getWidth()); }
    void reset();

    template<typename T> requires (std::is_base_of_v<Entity, T>)
    static bool isOfType(Entity *entity) {
        return dynamic_cast<T*>(entity) != nullptr;
    }

    bool isWithinMap(int y) const {
        size_t n = y;
        return y >= 0 && n < getHeight();
    }

protected:
    Size size;
    Field field;
};

class ConsoleBoard: public Board {
public:
    using Board::Board;
    void draw() override;

};

class SFMLBoard: public Board {
public:
    using Board::Board;
    void draw() override;
    sf::RenderWindow *window;
};

template<typename T> requires (std::is_base_of_v<Board, T>)
T *createBoard(size_t width, size_t height) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib{0, 64};
    std::mt19937 gen{rd()}; // Remove rd to make non-random
    auto *board = new T{width, height};
    for (size_t i = 0; i < board->getWidth() * board->getHeight(); ++i){
        int random_variable = distrib(gen);
        if (random_variable < 8) {
            board->setEntityAt(new Cell{}, i);
        } else if (random_variable < 16) {
            board->setEntityAt(new Organic{}, i);
        }
    }
    return board;
}


#endif //GENETIC_BOARD_H
