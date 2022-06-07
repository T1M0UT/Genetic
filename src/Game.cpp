//
// Created by Тимур Краснянский on 06.06.2022.
//

#include "Game.h"

Game::Game(Board *board, int numberOfCPUs, GameParams *params): board(board), params(params){
    for (int i = 0; i < numberOfCPUs; ++i) {
        cpus.push_back(new CPU{board, params});
    }
}

void Game::run() {
    while(1){
        iteration();
    }
}

void Game::iteration() {
    // Iterate through all the CPUs
    for (CPU *cpu : cpus) {
        cpu->iterate();
    }
}
