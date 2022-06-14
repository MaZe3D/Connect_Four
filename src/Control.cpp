#include "Control.h"

void Control::showWelcomeScreen()
{
    using namespace UI::Primitive;
    UI::Window welcomeWindow = UI::Window();  

    setScreenSize(30, 160);
    
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::FilledRectangle>(Position{7, 3}, 30, 5));
    dynamic_cast<UI::Element::FilledRectangle* const>(welcomeWindow.elements[0].get())->backgroundColor = ANSI::Color::BLACK;
    dynamic_cast<UI::Element::FilledRectangle* const>(welcomeWindow.elements[0].get())->foregroundColor = ANSI::Color::GREEN;

    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Welcome to Connect Four!", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 5}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Menu", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 9}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"1. Play", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 10}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"2. Continue", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 11}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"3. Help", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 12}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"4. Quit", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 13}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Please select an option!", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 15}));

    welcomeWindow.displayWindow();
}