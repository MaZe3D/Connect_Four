#include <iostream>
#include "Logic/Board.h"

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