#include "ColumnBot.h"

uint16_t ColumnBot::makeMove(const Game &game) {
    for (uint16_t y = game.getBoard().height-2; true; y--) {
        for (uint16_t x = 0; x < game.getBoard().width; x++) {
            if (game.getBoard().getCell(x, y) != Board::CellState::EMPTY) {
		    if (game.getBoard().getCell(x, y+1) == Board::CellState::EMPTY) {
			    return x;
		    }
            }
        }
    }
}
