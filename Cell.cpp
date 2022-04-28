//
// Created by Тимур Краснянский on 11.04.2022.
//

#include <iostream>
#include "Cell.h"


SFMLGame::Cell::Cell(Vector2D origin): _origin(origin) {

}

void SFMLGame::Cell::draw() const {
    std::cout << "#";
}
