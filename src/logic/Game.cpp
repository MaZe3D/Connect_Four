#include "Game.h"
#include "Actor.h"

Game::Game(std::shared_ptr<Actor>& actor1, std::shared_ptr<Actor>& actor2, uint16_t boardWith, uint16_t boardHeight, void (* const turnCallback)(const Game&))
    : m_actors{actor1, actor2}, m_board(boardWith, boardHeight), m_turnCallback{turnCallback}, m_currentActor{0} {}

Game::GameResult Game::run() {
    while (true) {
        m_turnCallback(*this);

        Board::TurnResult tr;
        uint8_t count = 0;
        do {
            uint16_t column = m_actors[m_currentActor]->makeMove(*this);
            tr = m_board.dropCoin(column, m_currentActor ? Board::CellState::PLAYER2 : Board::CellState::PLAYER1);
            count++;
        } while(tr == Board::TurnResult::INVALID && count < 3);

        if (tr == Board::TurnResult::VALID_WIN) return m_currentActor ? GameResult::PLAYER2 : GameResult::PLAYER1;
        if (m_board.isFull()) return GameResult::DRAW;

        m_currentActor = !m_currentActor;
    }
}

const Board& Game::getBoard() const {
    return m_board;
}

const std::shared_ptr<Actor>& Game::getActor1() const {
    return m_actors[0];
}

const std::shared_ptr<Actor>& Game::getActor2() const {
    return m_actors[1];
}

const std::shared_ptr<Actor>& Game::getCurrentActor() const {
    return m_actors[m_currentActor];
}

const std::shared_ptr<Actor>& Game::getLastActor() const {
    return m_actors[!m_currentActor];
}
