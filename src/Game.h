//
// Created by Тимур Краснянский on 06.06.2022.
//

#ifndef GENETIC_GAME_H
#define GENETIC_GAME_H


#include "Board.h"
#include "GameParams.h"
#include "CPU.h"

class Game {
    using CPUs = std::vector<CPU*>;

public:
    Game(Board *board, int numberOfCPUs, GameParams *params);
    void run();
    void iteration();
    Board* getBoard() { return board; }

private:
    Board *board;
    CPUs cpus;
    GameParams *params;
};


#endif //GENETIC_GAME_H
