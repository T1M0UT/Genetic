//
// Created by Тимур Краснянский on 11.04.2022.
//

#ifndef GENETIC_ENTITIES_H
#define GENETIC_ENTITIES_H


#include <tuple>
#include <array>

class Entity {
public:
    virtual void draw() const = 0;
};

class EmptyEntity: public Entity {
    void draw() const override;
};

class CellState {
public:
    bool hasMoved;
    uint8_t currentCommand;
};

class Cell : public Entity {
protected:
    CellState state;
    std::array<uint8_t , 64> genome;
};

class UICell : public Cell {
public:
    explicit UICell();
    void draw() const override;
};

class UIOrganic : public Entity {
public:
    void draw() const override;
};


#endif //GENETIC_ENTITIES_H
