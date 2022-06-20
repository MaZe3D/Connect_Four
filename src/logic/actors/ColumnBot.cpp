#include "ColumnBot.h"
#include <cassert>

uint16_t ColumnBot::makeMove(const Game &game) {
    for (uint16_t y = game.getBoard().height; y != 0; y--) {
        for (uint16_t x = 0; x < game.getBoard().width; x++) {
            if (y-2 < 0 || game.getBoard().getCell(x, y-2) != Board::CellState::EMPTY) {
                if (game.getBoard().getCell(x, y-1) == Board::CellState::EMPTY) {
                    return x;
                }
            }
        }
    }
    assert(false && "ColumnBot::makeMove: no empty cell found -> invalid board state");
    return 0;
}
