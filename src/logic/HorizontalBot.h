#pragma once

#include "Actor.h"

class HorizontalBot : private Actor {
public:
    uint16_t makeMove(const Game& game) override;
};