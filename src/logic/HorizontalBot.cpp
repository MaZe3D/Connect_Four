#include "HorizontalBot.h"

uint16_t HorizontalBot::makeMove(const Game& game) {
    for (uint16_t y = 0; y < game.getBoard().height; y++) {
        for (uint16_t x = 0; x < game.getBoard().width; x++) {
            if (game.getBoard().getCell(x, y) == Board::CellState::EMPTY) {
                return x;
            }
        }
    }
    return 0;
}