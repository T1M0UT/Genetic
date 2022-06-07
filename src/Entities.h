//
// Created by Тимур Краснянский on 11.04.2022.
//

#ifndef GENETIC_ENTITIES_H
#define GENETIC_ENTITIES_H


#include <tuple>
#include <array>
#include <cstdint>

const uint8_t GENOME_SIZE = 64;

class Entity {
public:
    virtual ~Entity() = default;
};

class EmptyEntity: public Entity { };

class Wall: public Entity { };

class Poison: public Entity { };

class Organic: public Entity { };

class CellState {
public:
    bool didMove = false;
    int energy;
    int generation;
    int minerals;
    uint8_t getCurrentCommand() const { return currentCommand; }
    void setCurrentCommand(uint8_t command) { currentCommand = command; currentCommand %= GENOME_SIZE; }
    void incrementCurrentCommand(uint8_t value) { currentCommand += value; currentCommand %= GENOME_SIZE; }
    void incrementCurrentCommand() { ++currentCommand; currentCommand %= GENOME_SIZE; }

protected:
    uint8_t currentCommand;

};

class Cell: public Entity {
    using Genome = std::array<uint8_t , 64>;

public:
    Cell(Genome genome, CellState state): genome{genome}, state{state}{};
    Cell();
    uint8_t peek(uint8_t pos);
    uint8_t peek();
    void setValue(int pos, uint8_t value);


    CellState state;
public:
    ~Cell() override = default;

protected:
    Genome genome;
};


#endif //GENETIC_ENTITIES_H
