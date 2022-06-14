#include <iostream>
#include "logic/Board.h"
#include "UX/UI/ConsoleUI.h"
#include "UX/UI/gotoXY.h"
#include <memory>
#include "Control.h"

void printTurnResult(Board::TurnResult tr) {
    if (tr == Board::TurnResult::VALID_WIN) {
        std::cout << "This is a win" << std::endl;
    } else if (tr == Board::TurnResult::VALID) {
        std::cout << "This is a valid move" << std::endl;
    } else {
        std::cout << "This is an illegal move" << std::endl;
    }
}

Board b(10, 20);

int main() 
{
    Control::showWelcomeScreen();
}
