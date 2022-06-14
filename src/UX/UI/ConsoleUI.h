#pragma once
#include <stdint.h>
#include <iostream>
#include <string>
#include "gotoXY.h"

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

    void clearScreen();
}

namespace UI::Primitive::Shapes
{
    struct Line : FormattedText
    {
        Position start;
        Position end;
    };

    void printLine(Line);
}

namespace UI::Element
{
    class UIElement
    {
    public:
        virtual void draw() = 0;
    };

    class Text : public UIElement
    {
    public:
        virtual void draw() override;
        Position position;
        Primitive::FormattedText formattedText;
    };

    class Ractangle : public UIElement
    {
    public:
        Position position;
        uint16_t width;
        uint16_t height;
        bool filled = false;

        std::string cornerUpperLeft = "└";
        std::string cornerUpperRight = "┐";
        std::string cornerLowerLeft = "┘";
        std::string cornerLowerRight = "┌";
        std::string horisontalLine = "-";
        std::string verticalLine = "|";

        Primitive::ANSI::Color foregroundColor = Primitive::ANSI::Color::DEFAULT;
        Primitive::ANSI::Color backgroundColor = Primitive::ANSI::Color::DEFAULT;

        virtual void draw() override;
    };

    class EvenGrid : UIElement
    {
    public:
        EvenGrid(uint16_t a,uint16_t b,uint16_t c,uint16_t d) : UIElement{},
            columns(a),
            rows(b),
            cellWidth(c),
            cellHeight(d)
            {}
        Position position;
        uint16_t columns;
        uint16_t rows;
        uint16_t cellWidth;
        uint16_t cellHeight;
        bool filled = false;

        std::string verticalLine = "|";
        std::string horizontalLine = "-";
        std::string crossLine = "+";
        std::string cornerUpperLeft = "┌";
        std::string cornerUpperRight = "┐";
        std::string cornerLowerLeft = "└";
        std::string cornerLowerRight = "┘";
        std::string edgeTop = "┬";
        std::string edgeBottom = "┴";
        std::string edgeLeft = "├";
        std::string edgeRight = "┤";

        Primitive::ANSI::Color foregroundColor = Primitive::ANSI::Color::DEFAULT;
        Primitive::ANSI::Color backgroundColor = Primitive::ANSI::Color::DEFAULT;

        std::string drawRow(std::string columnEdge, std::string verticalBody);
        virtual void draw() override;
        
    };
}

