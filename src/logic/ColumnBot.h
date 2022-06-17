#pragma once

#include "Actor.h"

class ColumnBot : public Actor {
    uint16_t makeMove(const Game& game) override;
};