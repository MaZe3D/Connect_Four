#include "Board.h"
#include <cassert>
#include <memory>

Board::Board(uint16_t width, uint16_t height)
    : width{width}, height{height}
{
    assert(width && height );
    m_cells = std::make_unique<CellState[]>((uint32_t)width*height);
    for (uint32_t i = 0; i < width*height; i++) m_cells[i] = CellState::EMPTY;
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

bool Board::checkWin(uint16_t centerX, uint16_t centerY) {
    assert(centerX < width && centerY < height);
    assert(getCell(centerX, centerY) != CellState::EMPTY);

    // calculate borders for check
    uint16_t left   = (int32_t)centerX - 3 < 0         ? 0        : centerX - 3;
    uint16_t right  = (int32_t)centerX + 3 >= width-1  ? width-1  : centerX + 3;
    uint16_t bottom = (int32_t)centerY - 3 < 0         ? 0        : centerY - 3;
    uint16_t top    = (int32_t)centerY + 3 >= height-1 ? height-1 : centerY + 3;

    CellState cellState = getCell(centerX, centerY);
    uint8_t count[4] {};
    for (int8_t offsetX = -3, offsetY = -3; offsetX <= 3; offsetX++, offsetY++) {
        bool b1 = centerX + offsetX <= right && centerX + offsetX >= left;
        bool b2 = centerY + offsetY <= top   && centerY + offsetY >= bottom;
        bool b3 = centerY - offsetY <= top   && centerY - offsetY >= bottom;
        uint16_t x = centerX + offsetX;
        uint16_t y = centerY + offsetY;
        uint16_t y2 = centerY - offsetY;
        if (b1) {
            if (getCell(x, centerY) == cellState) {
                count[0]++;
                if (count[0] == 4) {
                    return true;
                }
            } else {
                count[0] = 0;
            }
        }
        if (b2) {
            if (getCell(centerX, y) == cellState) {
                count[1]++;
                if (count[1] == 4) {
                    return true;
                }
            } else {
                count[1] = 0;
            }
        }
        if (b1 && b2) {
            if (getCell(x, y) == cellState) {
                count[2]++;
                if (count[2] == 4) {
                    return true;
                }
            } else {
                count[2] = 0;
            }
        }
        if (b1 && b3) {
            if (getCell(x, y2) == cellState) {
                count[3]++;
                if (count[3] == 4) {
                    return true;
                }
            } else {
                count[3] = 0;
            }
        }
    }

    return false;

}

bool Board::isFull() {
    for (uint16_t i = 0; i < width; ++i) {
        if (getCell(i, height-1) == Board::CellState::EMPTY) return false;
    }
    return true;
}
