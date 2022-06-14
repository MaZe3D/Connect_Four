#pragma once

#include <stdint.h>
#include "Game.h"

class Actor {
public:
    virtual uint16_t makeMove(const Game& game) = 0;
};