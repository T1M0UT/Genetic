//
// Created by Тимур Краснянский on 11.04.2022.
//

#ifndef GENETIC_CELL_H
#define GENETIC_CELL_H

#include <cstdint>
#include "Entity.h"

namespace SFMLGame {
    class CellState {
    public:
        bool hasMoved;
        u_int8_t currentCommand;
    };

    class Cell : public Entity {
    public:
        explicit Cell(Vector2D origin);

        void draw() const override;

        Vector2D getOrigin() override { return _origin; }

    private:
        Vector2D _origin;
        CellState state;
        int genome[];
    };
}

#endif //GENETIC_CELL_H
