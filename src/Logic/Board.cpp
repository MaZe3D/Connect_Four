#include "Board.h"
#include <cassert>

Board::Board(uint16_t width, uint16_t height)
    : height{height}, width{width}
{
    assert(height && width);
    m_cells = new CellState[height*width];
}

Board::~Board() {
    delete[] m_cells;
}

Board::CellState Board::getCell(uint16_t x, uint16_t y) {
    assert(x < width && y < height);
    return m_cells[y*height + x];
}

Board::TurnResult Board::dropCoin(uint16_t column, CellState state) {
    assert(column < width);
    assert(state != CellState::EMPTY);
    for (int i = 0; i < height; i++) {
        if (getCell(column, i) == CellState::EMPTY) {
            m_cells[i*height + column] = state;
            return checkWin(column, i) ? TurnResult::VALID_WIN : TurnResult::VALID;
        }
    }
    return TurnResult::INVALID;
}

bool Board::checkWin(uint16_t x, uint16_t y) {
    assert(x < width && y < height);

    // calculate borders for check
    uint16_t left   = (int32_t)x - 3 < 0         ? 0        : x - 3;
    uint16_t right  = (int32_t)x + 3 >= width-1  ? width-1  : x + 3;
    uint16_t bottom = (int32_t)y - 3 < 0         ? 0        : y - 3;
    uint16_t top    = (int32_t)y + 3 >= height-1 ? height-1 : y + 3;

}