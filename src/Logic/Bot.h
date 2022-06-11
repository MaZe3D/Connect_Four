#pragma once

#include "Actor.h"

class Bot : private Actor {
public:
    uint16_t makeMove(const Game& game) override;
};