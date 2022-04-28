//
// Created by Тимур Краснянский on 09.04.2022.
//

#include <vector>
#include <memory>
#include <iostream>
#include <random>
#include "Board.h"


Board::Board(size_t width, size_t height): size{width, height}, distrib{0, 64}, gen{rd()} {
    field.reserve(width * height);
    for(size_t i = 0; i < width * height; ++i){
        field.push_back(std::make_unique<EmptyEntity>());
    }
}

void Board::reset() {

}

void UIBoard::init() {
    for (size_t i = 0; i < field.size(); ++i){
        int random_variable = distrib(gen);
        if (random_variable < 8) {
            field[i] = std::make_unique<UICell>();
        } else if (random_variable < 16) {
            field[i] = std::make_unique<UIOrganic>();
        }
    }
}

void UIBoard::draw() {
    for (size_t i = 0; i < field.size(); ++i){
        field[i]->draw();
        if ((i + 1) % getWidth() == 0)
            std::cout << "\n";
    }
}
