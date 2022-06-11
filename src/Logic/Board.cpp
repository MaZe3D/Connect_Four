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
    return TurnResult::INVALID;
}