//
// Created by Тимур Краснянский on 09.04.2022.
//

#ifndef GENETIC_WORLD_H
#define GENETIC_WORLD_H


#include "Vector2D.h"

class World {
public:
    World(unsigned int width, unsigned int height);
    [[nodiscard]] unsigned int getWidth() const { return size.X; }
    [[nodiscard]] unsigned int getHeight() const { return size.Y; }
    virtual void draw() = 0;

protected:
    Vector2D size;
};


#endif //GENETIC_WORLD_H
