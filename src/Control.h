#pragma once

#include <vector>
#include <string>
#include "UX/UI/ConsoleUI.h"
#include <stdint.h>
#include "logic/Game.h"
#include "logic/Player.h"
#include "logic/RandomBot.h"
#include "logic/HorizontalBot.h"
#include "logic/VerticalBot.h"
#include "logic/ColumnBot.h"
#include <memory>

class Control
{
public:
    Control();
    virtual ~Control();
    static void runProgram();
    static void printBoard(Board pBoard, Position gridPosition);

private:
    static bool showMainMenu();

    static uint32_t getNummericInput();
    static uint16_t playerTurnInput(const Game& game);
    static void turnCallback(const Game& game);

    static void newGame();
    static void continueGame();
    static void showHelp();
    static std::shared_ptr<Actor> getBot(uint8_t botNumber);
    
    static void initMainMenu();
    static void initPlayerTypeMenu();
    static void initBotTypeMenu(uint8_t botNumber);
    static void initGameScreen(Board pBoard, Board::CellState turn);

    static UI::Screen _mainMenu;
    static UI::Screen _playerTypeMenu;
    static UI::Screen _botTypeMenu;
    static UI::Screen _gameWindow;
};
