
#include "Board.h"

Board::Board(uint16_t width, uint16_t height)
    : m_height{height}, m_width{width} {

}

Board::TurnResult Board::dropCoin(uint16_t column, CellState state) {
    return TurnResult::INVALID;
}