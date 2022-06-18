#pragma once

#include "../Actor.h"

class HorizontalBot : public Actor {
public:
    uint16_t makeMove(const Game& game) override;
};