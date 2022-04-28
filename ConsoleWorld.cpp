//
// Created by Тимур Краснянский on 12.04.2022.
//

#include "ConsoleWorld.h"

void ConsoleWorld::draw() {
    for(const auto& entity : entities) {
        entity.draw();
    }
}
