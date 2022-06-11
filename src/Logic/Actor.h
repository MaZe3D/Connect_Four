#pragma once

#include <stdint.h>

class Game;

class Actor {
public:
    virtual uint16_t makeMove(const Game& game) = 0;
};