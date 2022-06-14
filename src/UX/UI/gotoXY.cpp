#include "gotoXY.h"

//Unix/Linux/
void gotoXY(Position pos)
{
    if (pos.x > 0 && pos.y > 0)
    {
        std::cout << "\033[" << pos.y << ";" << pos.x << "H";
    }
    else
    {
        throw std::runtime_error("Invalid position");
    } 
}

void gotoXY(uint16_t x, uint16_t y)
{
    gotoXY(Position{x, y});
}

/* //Windows
gotoxy(Position pos)
{
    #include "Windows.h"
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = pos.x;
    coord.Y = pos.y;
    SetConsoleCursorPosition(hConsole, coord);
}
*/