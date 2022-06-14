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
    uint16_t dx = end.x - start.x;
    uint16_t dy = end.y - start.y;
    uint16_t x = start.x;
    uint16_t y = start.y;
    uint16_t stepx = (dx > 0) ? 1 : -1;
    uint16_t stepy = (dy > 0) ? 1 : -1;
    dx = abs(dx);
    dy = abs(dy);
    if (dx > dy)
    {
        int fraction = dy * 2 - dx;
        int distance = dy * 2;
        while (x != end.x)
        {
            gotoXY(Position{x, y});
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
            gotoXY(Position{x, y});
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
    gotoXY(Position{x, y});
    std::cout << ANSI::ESC << getANSIColorString(line.foregroundColor, line.backgroundColor) << line.text;
}

void UI::Element::Ractangle::draw()
{
    using namespace UI::Primitive;
    std::cout << ANSI::ESC << getANSIColorString(foregroundColor, backgroundColor) << cornerUpperLeft;
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
    std::cout << cornerUpperLeft << drawRow(edgeTop,horizontalLine) <<cornerUpperRight << std::endl;
    for(int k = 1; k < rows; k++)
    {
        for(int l = 0; l < cellHeight; l++)
        {
            std::cout << verticalLine << drawRow(verticalLine," ") << verticalLine << std::endl;
        }
        std::cout << edgeLeft << drawRow(crossLine, horizontalLine) << edgeRight << std::endl;
    }
     for(int l = 0; l < cellHeight; l++)
    {
        std::cout << verticalLine << drawRow(verticalLine," ") << verticalLine << std::endl;
    }
    std::cout << cornerLowerLeft << drawRow(edgeBottom,horizontalLine) << cornerLowerRight << std::endl;
}
