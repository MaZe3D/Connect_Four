#include <iostream>
#include "Logic/Board.h"

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
int main() {
    uint16_t i = -1;
    std::cout << sizeof(i) << std::endl;
    std::cout << sizeof(i +(int32_t)1) << std::endl;

    std::cout << "start" << std::endl;
    std::cout << "mid" << std::endl;
    //exit(0);
    //std::abort();
    //delete b;
    std::cout << "end" << std::endl;

	std::cout << "hello world" << std::endl;
    return 0;
}