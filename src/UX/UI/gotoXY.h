#pragma once
#include "stdint.h"
#include <iostream>

struct Position
{
    uint16_t x = 0;
    uint16_t y = 0;
};

void gotoXY(Position pos);

void gotoXY(uint16_t x, uint16_t y);