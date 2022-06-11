#pragma once

#include <inttypes.h>

class Board {
public:
    enum class CellState { EMPTY, PLAYER1, PLAYER2 };
    enum class TurnResult { INVALID, VALID, VALID_WIN };

    Board(uint16_t width, uint16_t height);
    ~Board();
    CellState getCell(uint16_t x, uint16_t y);
    TurnResult dropCoin(uint16_t column, CellState state);

private:
    const uint16_t m_height;
    const uint16_t m_width;
    CellState m_cells[];
};