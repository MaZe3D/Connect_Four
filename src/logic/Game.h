#pragma once

#include "Board.h"
#include <memory>

class Actor;

class Game {
public:
    enum class GameResult { DRAW, PLAYER1, PLAYER2 };

    Game(std::shared_ptr<Actor>& actor1, std::shared_ptr<Actor>& actor2, uint16_t boardWith, uint16_t boardHeight, void (* const turnCallback)(const Game&));
    GameResult run();
    const Board& getBoard() const;
    const std::shared_ptr<Actor>& getActor1() const;
    const std::shared_ptr<Actor>& getActor2() const;

private:
    const std::shared_ptr<Actor> m_actors[2];
    Board m_board;
    void (* const m_turnCallback)(const Game&);
};