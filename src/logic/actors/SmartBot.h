#pragma once

#include "../Actor.h"

class SmartBot : public Actor {
public:
    uint16_t makeMove(const Game& game) override;
};