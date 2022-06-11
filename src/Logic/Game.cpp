#include "Game.h"

Game::Game(Actor& actor1, Actor& actor2, uint16_t boardWith, uint16_t boardHeight)
    : m_board(boardWith, boardHeight) {}