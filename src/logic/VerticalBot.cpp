#include "VerticalBot.h"

uint16_t VerticalBot::makeMove(const Game &game) {
    for (int x = 0; x < game.getBoard().width; x++) {
        if (game.getBoard().getCell(x, game.getBoard().height-1) == Board::CellState::EMPTY) {
            return x;
        }
    }
    return 0;
}
