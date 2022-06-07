//
// Created by Тимур Краснянский on 11.04.2022.
//


#include <iostream>
#include "Entities.h"


Cell::Cell() {
    genome = {};
    state = {};
    for (unsigned char & i : genome){
        i = 0;
    }
}

uint8_t Cell::peek(uint8_t pos) {
    return genome[pos % GENOME_SIZE];
}

uint8_t Cell::peek() {
    return genome[state.getCurrentCommand()];
}

void Cell::setValue(int pos, uint8_t value) {
    genome[pos % GENOME_SIZE] = value;
}
