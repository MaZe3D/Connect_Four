#pragma once
#include "stdint.h"
#include <iostream>

struct Position
{
    uint16_t x = 0;
    uint16_t y = 0;
};


void gotoxy(Position pos);