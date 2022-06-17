#include "Control.h"

UI::Window Control::_mainMenu = UI::Window();	// Initialize static member

void Control::initMainMenu()
{
    using namespace UI::Primitive;
    UI::Window welcomeWindow = UI::Window();  
    
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::FilledRectangle>(Position{7, 3}, 30, 5));
    auto filledRectangle = dynamic_cast<UI::Element::FilledRectangle* const>(welcomeWindow.elements[0].get());
    filledRectangle->backgroundColor = ANSI::Color::BLACK;
    filledRectangle->foregroundColor = ANSI::Color::GREEN;

    filledRectangle->cornerLowerLeft = "╚";
    filledRectangle->cornerUpperRight = "╗";
    filledRectangle->cornerLowerRight = "╝";
    filledRectangle->cornerUpperLeft = "╔";
    filledRectangle->horizontalLine = "═";
    filledRectangle->verticalLine = "║";

    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Welcome to Connect Four!", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 5}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Menu", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 9}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"1. Play", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 10}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"2. Continue", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 11}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"3. Help", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 12}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"4. Quit", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 13}));
    welcomeWindow.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Please enter an option: ", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 15}));
    welcomeWindow.cursorPos = Position{34, 15};
    _mainMenu = welcomeWindow;
}

void Control::runProgram()
{
    while(showMainMenu());
}

bool Control::showMainMenu()
{
    UI::Window::setBackgroundColor(UI::Primitive::ANSI::Color::BLACK);
    initMainMenu();
    _mainMenu.displayWindow();
    int selection;
    while ((selection = getNummericInput()) != 4)
    {
        switch (selection)
        {
        case 1:
            //showPlayerSelection();

            break;
        
        default:
            break;
        }
    }

    return false;
}

uint32_t Control::getNummericInput()
{
    std::string input;
    std::cin >> input;
    try
    {
        return std::stoi(input);
    }
    catch(std::invalid_argument)
    {
        return 0;
    }
    catch(std::out_of_range)
    {
        return 0;
    }  
}

uint32_t Control::getUserInput(int min, int max)
{
    int input;
    do 
    {
        input = getNummericInput();
    } while (input < min || input > max);
    return input;
}