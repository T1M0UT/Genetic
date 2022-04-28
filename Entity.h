//
// Created by Тимур Краснянский on 11.04.2022.
//

#ifndef GENETIC_ENTITY_H
#define GENETIC_ENTITY_H


#include "Vector2D.h"

class Entity {
public:
    virtual void draw() const = 0;
    virtual Vector2D getOrigin() = 0;
};

#endif //GENETIC_ENTITY_H
