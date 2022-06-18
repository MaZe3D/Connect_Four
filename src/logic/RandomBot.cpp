#include "RandomBot.h"
#include <random>

uint16_t RandomBot::makeMove(const Game &game) {
    uint16_t x = rand() % game.getBoard().width;
    if (game.getBoard().getCell(x, game.getBoard().height-1) == Board::CellState::EMPTY) return x;
    return makeMove(game);
}
