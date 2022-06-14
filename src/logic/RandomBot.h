#pragma once

#include "Actor.h"

class RandomBot : public Actor {
public:
    uint16_t makeMove(const Game& game) override;
};
