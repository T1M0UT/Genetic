//
// Created by Тимур Краснянский on 12.04.2022.
//

#ifndef GENETIC_CONSOLEWORLD_H
#define GENETIC_CONSOLEWORLD_H


#include <list>
#include "World.h"
#include "Entity.h"

class ConsoleWorld: public World {
public:
    using World::World;

    void draw() override;

private:
    std::list<Entity> entities;
    int scale;
};


#endif //GENETIC_CONSOLEWORLD_H
