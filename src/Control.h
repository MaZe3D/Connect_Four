#pragma once

#include <vector>
#include <string>
#include "UX/UI/ConsoleUI.h"
#include <stdint.h>
#include "logic/Game.h"
#include "logic/actors/Player.h"
#include "logic/actors/RandomBot.h"
#include "logic/actors/HorizontalBot.h"
#include "logic/actors/VerticalBot.h"
#include "logic/actors/ColumnBot.h"
#include <memory>

class Control
{
public:
    Control();
    virtual ~Control();
    static void runProgram();
    static std::vector<std::shared_ptr<UI::Element::UIElement>> createUIElementsBoard(const Game& game, Position gridPosition);

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
    static void initGameScreen(const Game& game);
    static void initVictoryScreen(Game::GameResult gameResult);

    static UI::Screen _mainMenu;
    static UI::Screen _playerTypeMenu;
    static UI::Screen _botTypeMenu;
    static UI::Screen _gameScreen;
    static UI::Screen _victoryScreen;
};
