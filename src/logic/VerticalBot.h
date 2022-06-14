#pragma once

#include "Actor.h"

class VerticalBot :  public Actor {
public:
    uint16_t makeMove(const Game& game) override;
};

