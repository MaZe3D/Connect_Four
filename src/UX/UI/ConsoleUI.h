#pragma once
#include <stdint.h>
#include <iostream>
#include <string>
#include "gotoxy.h"

namespace UI::Primitive::ANSI
{
    constexpr char ESC {'\x1b'};
    enum class Color : uint8_t
    {
        RESET = 0,
        BLACK = 30,
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        MAGENTA = 35,
        CYAN = 36,
        WHITE = 37,
        DEFAULT = 39,
        BRIGHT_BLACK = 90,
        BRIGHT_RED = 91,
        BRIGHT_GREEN = 92,
        BRIGHT_YELLOW = 93,
        BRIGHT_BLUE = 94,
        BRIGHT_MAGENTA = 95,
        BRIGHT_CYAN = 96,
        BRIGHT_WHITE = 97,
    };
}

namespace UI::Primitive
{
    struct FormattedText
    {
        std::string text;
        UI::Primitive::ANSI::Color foregroundColor;
        UI::Primitive::ANSI::Color backgroundColor;
    };

    std::string getANSIColorString(ANSI::Color foreground, ANSI::Color background);
    
    void printFormattedText(FormattedText text);
    void printFormattedText(FormattedText text, Position pos);
}