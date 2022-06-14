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
    

private:
    static uint16_t getMenuSelection(std::vector<std::string> menuItems);
};
