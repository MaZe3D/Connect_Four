#pragma once

#include "Actor.h"

class Player : public Actor {
public:
    Player(uint16_t (* const inputCallback)(const Game&));
    uint16_t makeMove(const Game& game) override;

private:
    uint16_t (* const m_inputCallback)(const Game&);
};