#pragma once

#include <inttypes.h>

class Board {
public:
    enum class CellState { EMPTY, PLAYER1, PLAYER2 };
    enum class TurnResult { INVALID, VALID, VALID_WIN };

    const uint16_t height;
    const uint16_t width;

    Board(uint16_t width, uint16_t height);
    ~Board();
    CellState getCell(uint16_t x, uint16_t y);
    TurnResult dropCoin(uint16_t column, CellState state);

private:
    CellState* m_cells;
    bool checkWin(uint16_t x, uint16_t y);
};