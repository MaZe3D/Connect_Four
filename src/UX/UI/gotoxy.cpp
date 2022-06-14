#include "gotoXY.h"

//Unix/Linux/
void gotoXY(Position pos)
{
    std::cout << "\033[" << pos.y << ";" << pos.x << "H";
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