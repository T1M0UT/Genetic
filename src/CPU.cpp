//
// Created by Тимур Краснянский on 06.06.2022.
//

#include "CPU.h"
#include "iostream"

CPU::CPU(Board *board, GameParams *params): board(board), params(params) {
    currentEntity = nullptr;
    X = 0;
    Y = 0;
}


void CPU::decode() {
    auto cell = dynamic_cast<Cell*>(currentEntity);

    if (!cell){
        return;
    }

   // std::cout<<"I'm a cell" << cell->peek()<<std::endl;

    if (cell->state.energy <= 0) {
        //die();
    }

    cell->state.didMove = false;
    auto attempts = 0;
//    if(cell->state.energy > 500) {
//        reproduce();
//    }

//    if(cell->y > board->getHeight()/2){
//        auto bonus = int(map(cell->y, field.length/2, field.length, 1, 2));
//        cell->minerals += bonus;
//    }

    while(!cell->state.didMove && attempts < 10){
        //command = (int)(random(0, 64))
        auto command = cell->peek(cell->state.getCurrentCommand());
        if (command >= uint8_t{0} && command < uint8_t{8}) {
            auto dir = cell->peek(cell->state.getCurrentCommand() + 1) % 8;
            //cell->direction = (cell->direction + dir) % 8;
            cell->state.didMove = tryMove(1, 1);
            cell->state.incrementCurrentCommand();
        }
        else {
            switch(command) {
                case 8:
                case 9:
                case 10:
                case 11:
                    //cell->photosynthesis();
                    cell->state.didMove = true;
                    break;
                case 12:
                case 13:
                case 14:
                case 15:
                    //cell->state.didMove = cell->tryEatOrganic();
                    break;
                case 16:
                case 17:
                    //cell->state.didMove = cell->tryReproduce();
                    break;
                case 18:
                    //cell->state.didMove = cell->tryEatCell();
                    break;
                case 19:
                case 20:
                    //cell->look();
                    break;
                case 21:
                case 22:
                case 23:
                case 24:
                    //cell->state.didMove = cell->tryOrganicToEnergy();
                    break;
                case 25:
                case 26:
                    //cell->checkEnergy();
                    break;
                case 27:
                case 28:
                case 29:
                    //cell->state.didMove = cell->tryGrab();
                    break;
                case 30:
                case 31:
                case 32:
                    //cell->tryShareEnergy();
                    break;
                default:
                    //cell->state.incremetCurrentCommand(command - 1);
                    break;
            }
        }
        cell->state.incrementCurrentCommand();
        attempts++;
    }
    //cell->lifetime++;
    cell->state.energy--;
}

void CPU::iterate() {
    // Iterate through the board
    for (Y = 0; Y < board->getHeight(); Y++) {
        for (X = 0; X < board->getWidth(); X++) {
            auto entity = board->getEntityAt(X, Y);
            if (Board::isOfType<Cell>(entity)) {
                currentEntity = dynamic_cast<Cell*>(entity);
                decode();
            }
        }
    }

    for (Y = 0; Y < board->getHeight(); Y++) {
        for (X = 0; X < board->getWidth(); X++) {
            auto entity = board->getEntityAt(X, Y);
            if (Board::isOfType<Cell>(entity)) {
                auto ent = dynamic_cast<Cell *>(entity);
                ent->state.didMove = false;
                decode();
            }
        }
    }
}

bool CPU::tryMove(int dx, int dy){
    if (canMove(dx, dy)) {
        move(X + dx, Y + dy);
    }
    return false;
}

bool CPU::canMove(int newX, int newY) {
    return board->isWithinMap(newY) &&
           !Board::isOfType<EmptyEntity>(board->getEntityAt(newX, newY));
}

/*
this.canMove = function(dx, dy)  {
    return isWithinBoundsOfArray(this.y + dy) &&
           (field[this.y + dy][this.x + dx] == null)
}

 */
void CPU::move(int newX, int newY) {
    auto width = board->getWidth();

    board->swap(newX, newY, X, Y);
    currentEntity->state.energy--;
}