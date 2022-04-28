//
// Created by Тимур Краснянский on 11.04.2022.
//


#include <iostream>
#include "Entities.h"

UICell::UICell() {
    for (uint8_t i = 0; i < genome.size(); ++i){
        genome[i] = 11;
    }
}

void UICell::draw() const {
    std::cout << "C";
}

void UIOrganic::draw() const {
    std::cout << "M";
}

void EmptyEntity::draw() const {
    std::cout << " ";
}
