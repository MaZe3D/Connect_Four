#pragma once

#include "Actor.h"
#include "Board.h"

class Game {
public:
    Game(Actor& actor1, Actor& actor2, uint16_t boardWith, uint16_t boardHeight);
    void run();
    const Board& getBoard();
    const Actor& getActor1();
    const Actor& getActor2();

private:
    Board m_board;

};