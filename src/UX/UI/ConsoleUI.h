#pragma once
#include <stdint.h>
#include <iostream>
#include <string>
#include "gotoXY.h"
#include <list>
#include <memory>

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

        Text(Primitive::FormattedText pFormattedText, Position pPosition);
        Text();
    };

    class Rectangle : public UIElement
    {
    public:
        Position position;
        uint16_t width;
        uint16_t height;

        std::string cornerLowerLeft = "└";
        std::string cornerUpperRight = "┐";
        std::string cornerLowerRight = "┘";
        std::string cornerUpperLeft = "┌";
        std::string horizontalLine = "─";
        std::string verticalLine = "│";

        Primitive::ANSI::Color foregroundColor = Primitive::ANSI::Color::DEFAULT;
        Primitive::ANSI::Color backgroundColor = Primitive::ANSI::Color::RESET;

        Rectangle(Position position, uint16_t width, uint16_t height);

        virtual void draw() override;
    };

    class FilledRectangle : public Rectangle
    {
    public:
        FilledRectangle(Position pPosition, uint16_t pWidth, uint16_t pHeight) : Rectangle(pPosition, pWidth, pHeight){};
        virtual void draw() override;
        std::string fillChar = " ";
    private:
        void drawOutline();
    };

    class EvenGrid : UIElement
    {
    public:
        EvenGrid(uint16_t pColumns,uint16_t pRows,uint16_t pcellWidth,uint16_t pCellHeight, Position pPosition) : UIElement{},
            columns(pColumns),
            rows(pRows),
            cellWidth(pcellWidth),
            cellHeight(pCellHeight),
            position(pPosition)
            {}
        Position position;
        uint16_t columns;
        uint16_t rows;
        uint16_t cellWidth;
        uint16_t cellHeight;
        bool filled = false;

        std::string verticalLine = "│";
        std::string horizontalLine = "─";
        std::string crossLine = "┼";
        std::string cornerUpperLeft = "┌";
        std::string cornerUpperRight = "┐";
        std::string cornerLowerLeft = "└";
        std::string cornerLowerRight = "┘";
        std::string edgeTop = "┬";
        std::string edgeBottom = "┴";
        std::string edgeLeft = "├";
        std::string edgeRight = "┤";
        std::string fillChar = " ";

        Primitive::ANSI::Color foregroundColor = Primitive::ANSI::Color::DEFAULT;
        Primitive::ANSI::Color backgroundColor = Primitive::ANSI::Color::DEFAULT;

        std::string drawRow(std::string columnEdge, std::string verticalBody);
        virtual void draw() override;
    };

}

namespace UI
{
    class Window
    {
    public:
        std::list<std::unique_ptr<Element::UIElement>> elements;
        
        Window();

        void displayWindow();
    };
}
