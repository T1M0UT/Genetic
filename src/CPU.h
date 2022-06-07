//
// Created by Тимур Краснянский on 06.06.2022.
//

#ifndef GENETIC_CPU_H
#define GENETIC_CPU_H


#include "Entities.h"
#include "Board.h"
#include "GameParams.h"

class CPU {
public:
    CPU(Board *board, GameParams *params);
    void iterate();

private:
    // TODO: field view
    void decode();
    void look();
    void move();
    void grab();
    void mineralIntoEnergy();
    void checkEnergy();
    Cell *currentEntity;
    Board *board;
    size_t X, Y;
    GameParams *params;

    bool tryMove(int dx, int dy);

    bool canMove(int dx, int dy);

    void move(int newX, int newY);
};


#endif //GENETIC_CPU_H
