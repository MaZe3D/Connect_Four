#pragma once

#include <inttypes.h>
#include <memory>

class Board {
public:
    enum class CellState { EMPTY, PLAYER1, PLAYER2 };
    enum class TurnResult { INVALID, VALID, VALID_WIN };

    const uint16_t width;
    const uint16_t height;

    Board(uint16_t width, uint16_t height);
    CellState getCell(uint16_t x, uint16_t y) const;
    TurnResult dropCoin(uint16_t column, CellState playerState);
    bool isFull() const;

private:
    std::unique_ptr<CellState[]> m_cells;

    bool checkWin(uint16_t centerX, uint16_t centerY) const;
};
