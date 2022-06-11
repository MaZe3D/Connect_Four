#pragma once

#include "Actor.h"

class Player : public Actor {
public:
    Player();
    uint16_t makeMove(const Game& game) override;
};