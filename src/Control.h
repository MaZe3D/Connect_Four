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
    static void showWelcomeScreen();
    static void initGameScreen();
    static UI::Window _gameWindow;
    

private:
    static uint16_t getMenuSelection(std::vector<std::string> menuItems);
   
};
