#include "ColumnBot.h"

uint16_t ColumnBot::makeMove(const Game &game) {
    uint16_t highestColumn = 0;
    uint16_t highestColumnHeight = 0;
    for (uint16_t x = 0; x < game.getBoard().width; x++) {
        for (uint16_t y = 0; y < game.getBoard().height; y++) {
            if (game.getBoard().getCell(x, y) != Board::CellState::EMPTY) {
                if (y > highestColumnHeight && y < game.getBoard().height - 1) {
                    if (y == game.getBoard().height-2) return x;
                    highestColumn = x;
                    highestColumnHeight = y;
                    break;
                }
            }
        }
    }
    return highestColumn;
}
