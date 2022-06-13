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
    ansiCode += std::to_string((background == Color::DEFAULT) ? 0 : (static_cast<uint8_t>(background)+10));
    ansiCode += "m";
    return ansiCode;
}

void UI::Primitive::printFormattedText(FormattedText formattedText)
{
    std::cout << ANSI::ESC << getANSIColorString(formattedText.foregroundColor, formattedText.backgroundColor) << formattedText.text << ANSI::ESC << getANSIColorString(ANSI::Color::RESET, ANSI::Color::RESET);
}