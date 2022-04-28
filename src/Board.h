//
// Created by Тимур Краснянский on 09.04.2022.
//

#ifndef GENETIC_BOARD_H
#define GENETIC_BOARD_H


#include <array>
#include <vector>
#include <random>
#include <memory>
#include "Entities.h"


class Board {
public:
    Board(size_t width, size_t height);
    [[nodiscard]] size_t getWidth() const { return std::get<0>(size); }
    [[nodiscard]] size_t getHeight() const { return std::get<1>(size); }
    virtual void draw() = 0;
    void reset();
    virtual void init() = 0;

private:
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    //Standard mersenne_twister_engine seeded with rd()

protected:
    std::tuple<size_t, size_t> size;
    std::vector<std::unique_ptr<Entity>> field;
    std::uniform_int_distribution<> distrib;
    std::mt19937 gen;
};

class UIBoard: public Board {
public:
    using Board::Board;
    void draw() override;
    void init() override;

};


#endif //GENETIC_BOARD_H
