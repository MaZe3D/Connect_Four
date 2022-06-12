#include "Player.h"
#include <cassert>

Player::Player(uint16_t (* const inputCallback)(const Game&))
    : m_inputCallback{inputCallback}
{
    assert(m_inputCallback != nullptr);
}

uint16_t Player::makeMove(const Game &game) {
    return m_inputCallback(game);
}