#include "ConsoleUI.h"

std::string UI::Primitive::getANSIColorString(ANSI::Color foreground, ANSI::Color background)
{
    using namespace UI::Primitive::ANSI;
    if (background == Color::DEFAULT)
    {
        throw std::runtime_error("Background color cannot be DEFAULT");
    }
    std::string ansiCode = "[";

    ansiCode += std::to_string(static_cast<uint8_t>(foreground));
    ansiCode += ";";
    ansiCode += std::to_string((background == Color::RESET) ? 0 : (static_cast<uint8_t>(background)+10));
    ansiCode += "m";
    return ansiCode;
}

void UI::Primitive::printFormattedText(FormattedText formattedText)
{
    std::cout << ANSI::ESC << getANSIColorString(formattedText.foregroundColor, formattedText.backgroundColor) << formattedText.text << ANSI::ESC << getANSIColorString(ANSI::Color::RESET, ANSI::Color::RESET);
}

void UI::Primitive::printFormattedText(FormattedText formattedText, Position pos)
{
    gotoXY(pos);
    printFormattedText(formattedText);
}

void UI::Primitive::clearScreen()
{
    std::cout << ANSI::ESC << "[2J" << ANSI::ESC << "[1;1H";
}

void UI::Primitive::Shapes::printLine(Line line) //bresnham algorithm
{
    using namespace UI::Primitive::ANSI;
    Position start = line.start;
    Position end = line.end;
    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int x = start.x;
    int y = start.y;
    int stepx = (dx > 0) ? 1 : -1;
    int stepy = (dy > 0) ? 1 : -1;
    dx = abs(dx);
    dy = abs(dy);
    if (dx > dy)
    {
        int fraction = dy * 2 - dx;
        int distance = dy * 2;
        while (x != end.x)
        {
            gotoXY(x, y);
            printFormattedText(FormattedText{line.text, line.foregroundColor, line.backgroundColor});
            x += stepx;
            if (fraction >= 0)
            {
                y += stepy;
                fraction -= dx * 2;
            }
            fraction += distance;
        }
    }
    else
    {
        int fraction = dx * 2 - dy;
        int distance = dx * 2;
        while (y != end.y)
        {
            gotoXY(x, y);
            printFormattedText(FormattedText{line.text, line.foregroundColor, line.backgroundColor});
            y += stepy;
            if (fraction >= 0)
            {
                x += stepx;
                fraction -= dy * 2;
            }
            fraction += distance;
        }
    }
    gotoXY(x, y);
    std::cout << ANSI::ESC << getANSIColorString(line.foregroundColor, line.backgroundColor) << line.text;
}

void UI::Element::Rectangle::draw()
{
    width = width - 1;
    height = height - 1;

    using namespace UI::Primitive;
    gotoXY(position);
    std::cout << ANSI::ESC << getANSIColorString(foregroundColor, backgroundColor) << cornerUpperLeft;
    gotoXY(Position{static_cast<uint16_t>(position.x + width), position.y});
    std::cout << ANSI::ESC << getANSIColorString(foregroundColor, backgroundColor) << cornerUpperRight;
    gotoXY(Position{static_cast<uint16_t>(position.x + width), static_cast<uint16_t>(position.y + height)});
    std::cout << ANSI::ESC << getANSIColorString(foregroundColor, backgroundColor) << cornerLowerRight;
    gotoXY(Position{position.x, static_cast<uint16_t>(position.y + height)});
    std::cout << ANSI::ESC << getANSIColorString(foregroundColor, backgroundColor) << cornerLowerLeft;

    Shapes::printLine({horizontalLine, foregroundColor, backgroundColor, 
        Position{static_cast<uint16_t>(position.x + 1), position.y},
        Position{static_cast<uint16_t>(position.x + width - 1), position.y}});

    Shapes::printLine({verticalLine, foregroundColor, backgroundColor, 
        Position{static_cast<uint16_t>(position.x + width), static_cast<uint16_t>(position.y + 1)},
        Position{static_cast<uint16_t>(position.x + width), static_cast<uint16_t>(position.y + height - 1)}});

    Shapes::printLine({horizontalLine, foregroundColor, backgroundColor, 
        Position{static_cast<uint16_t>(position.x + 1), static_cast<uint16_t>(position.y + height)},
        Position{static_cast<uint16_t>(position.x + width - 1), static_cast<uint16_t>(position.y + height)}});

    Shapes::printLine({verticalLine, foregroundColor, backgroundColor, 
        Position{position.x, static_cast<uint16_t>(position.y + 1)},
        Position{position.x, static_cast<uint16_t>(position.y + height - 1)}});

    width = width + 1;
    height = height + 1;
}

UI::Element::Text::Text()
{
    formattedText.text = "";
    formattedText.foregroundColor = Primitive::ANSI::Color::DEFAULT;
    formattedText.backgroundColor = Primitive::ANSI::Color::RESET;
}

UI::Element::Text::Text(Primitive::FormattedText pFormattedText, Position pPosition)
{
    formattedText = pFormattedText;
    position = pPosition;
}

void UI::Element::Text::draw()
{
    using namespace UI::Primitive;
    gotoXY(position);
    printFormattedText(formattedText);
}

UI::Element::Rectangle::Rectangle(Position pPosition, uint16_t pWidth, uint16_t pHeight)
{
    position = pPosition;
    width = pWidth;
    height = pHeight;
}
UI::Element::EvenGrid::EvenGrid(uint16_t pColumns,uint16_t pRows,uint16_t pcellWidth,uint16_t pCellHeight, Position pPosition)
{
    columns = pColumns;
    rows = pRows;
    cellWidth = pcellWidth;
    cellHeight = pCellHeight;
    position = pPosition;
}

std::string UI::Element::EvenGrid::drawRow(std::string columnEdge, std::string verticalBody)
{
    std::string verticalCellBody;
    for(int j = 0; j < cellWidth; j++)
    {
        verticalCellBody += verticalBody;
    }

    std::string rowBody;
    int i = 1;
    while(i<columns)
    {
        rowBody += verticalCellBody + columnEdge;
        i++;
    }
    return rowBody + verticalCellBody;
}

void UI::Element::EvenGrid::draw()
{
    gotoXY(position);
    uint16_t yOffset = 0;
    std::cout << Primitive::ANSI::ESC << Primitive::getANSIColorString(foregroundColor , backgroundColor);
    std::cout << cornerUpperLeft << drawRow(edgeTop,horizontalLine) <<cornerUpperRight;
    yOffset++;
    gotoXY(Position{position.x, static_cast<uint16_t>(position.y+yOffset)});
    for(int k = 1; k < rows; k++)
    {
        for(int l = 0; l < cellHeight; l++)
        {
            std::cout << verticalLine << drawRow(verticalLine,fillChar) << verticalLine;
            yOffset++;
            gotoXY(Position{position.x, static_cast<uint16_t>(position.y+yOffset)});
        }
        std::cout << edgeLeft << drawRow(crossLine, horizontalLine) << edgeRight;
        yOffset++;
        gotoXY(Position{position.x, static_cast<uint16_t>(position.y+yOffset)});
    }
     for(int l = 0; l < cellHeight; l++)
    {
        std::cout << verticalLine << drawRow(verticalLine,fillChar) << verticalLine;
        yOffset++;
        gotoXY(Position{position.x, static_cast<uint16_t>(position.y+yOffset)});
    }
    std::cout << cornerLowerLeft << drawRow(edgeBottom,horizontalLine) << cornerLowerRight;
    yOffset++;
    gotoXY(Position{1, static_cast<uint16_t>(position.y+yOffset)});
}

void UI::Screen::displayScreen()
{
    if (elements.empty())
    {
        throw std::runtime_error("No elements to display");
    }

    Primitive::clearScreen();
    for(auto &element : elements)
    {
        element->draw();
    }
    gotoXY(cursorPos);
}

UI::Screen::Screen()
{
}

void UI::Element::FilledRectangle::draw()
{
    Rectangle::draw();
    using namespace UI::Primitive;
    for (int i = 1; i < height - 1; i++)
    {
        Shapes::printLine({fillChar, foregroundColor, backgroundColor, 
            Position{static_cast<uint16_t>(position.x + 1), static_cast<uint16_t>(position.y + i)},
            Position{static_cast<uint16_t>(position.x + width - 2), static_cast<uint16_t>(position.y + i)}});
    }
}

void UI::Primitive::setScreenSize(uint16_t pWidth, uint16_t pHeight)
{
    std::cout << ANSI::ESC << "[8;" << pWidth << ";" << pHeight << "t";
}

void UI::Screen::setScreenSize(uint16_t pWidth, uint16_t pHeight)
{
    Primitive::setScreenSize(pWidth, pHeight);
    _windowWidth = pWidth;
    _windowHeight = pHeight;
}

uint16_t UI::Screen::_windowWidth = 160;
uint16_t UI::Screen::_windowHeight = 30;

void UI::Screen::setBackgroundColor(UI::Primitive::ANSI::Color color)
{
    std::cout << Primitive::ANSI::ESC << Primitive::getANSIColorString(Primitive::ANSI::Color::DEFAULT, color) << "m";
    for(int i = 1; i <= _windowHeight; i++)
    {
        gotoXY(Position{1, static_cast<uint16_t>(i)});
        for(int j = 1; j <= _windowWidth; j++)
        {
            std::cout << " ";
        }
    }
}
