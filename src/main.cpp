#include <iostream>
#include "logic/Board.h"
#include "UX/UI/ConsoleUI.h"
#include "UX/UI/gotoxy.h"
#include <memory>

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
<<<<<<< HEAD
    UI::Element::EvenGrid g(7,6,4,4);
    g.draw();
    //UI::Primitive::clearScreen();
=======
    
>>>>>>> 4bc4f0f388ea5a11d2b57b528f850ba7e1aa6532
    printTurnResult(b.dropCoin(0, Board::CellState::PLAYER1));
    printTurnResult(b.dropCoin(0, Board::CellState::PLAYER1));
    printTurnResult(b.dropCoin(0, Board::CellState::PLAYER1));
    printTurnResult(b.dropCoin(0, Board::CellState::PLAYER2));
    printTurnResult(b.dropCoin(1, Board::CellState::PLAYER1));
    printTurnResult(b.dropCoin(1, Board::CellState::PLAYER1));
    printTurnResult(b.dropCoin(1, Board::CellState::PLAYER1));
    printTurnResult(b.dropCoin(2, Board::CellState::PLAYER1));
    printTurnResult(b.dropCoin(2, Board::CellState::PLAYER1));
    printTurnResult(b.dropCoin(3, Board::CellState::PLAYER1));
    return 0;
}
