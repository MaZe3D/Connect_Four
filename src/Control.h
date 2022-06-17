#pragma once

#include <vector>
#include <string>
#include "UX/UI/ConsoleUI.h"
#include <stdint.h>

class Control
{
public:
    Control();
    virtual ~Control();
    static void runProgram();
    static void printBoard(Board pBoard, Position gridPosition);

private:
    static uint16_t getMenuSelection(std::vector<std::string> menuItems);
    static bool showMainMenu();
    static void initMainMenu();
    static uint32_t getNummericInput();
    static uint32_t getUserInput(int min, int max);
    static UI::Screen _mainMenu;
    static void initGameScreen(Board pBoard, Board::CellState turn);
    static UI::Screen _gameWindow;   
};
