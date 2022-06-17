#include "Control.h"

UI::Screen Control::_mainMenu = UI::Screen();	// Initialize static member

void Control::initMainMenu()
{
    using namespace UI::Primitive;
    UI::Screen screen = UI::Screen();  
    
    screen.elements.push_back(std::make_shared<UI::Element::FilledRectangle>(Position{7, 3}, 30, 5));
    auto filledRectangle = dynamic_cast<UI::Element::FilledRectangle* const>(screen.elements[0].get());
    filledRectangle->backgroundColor = ANSI::Color::BLACK;
    filledRectangle->foregroundColor = ANSI::Color::GREEN;

    filledRectangle->cornerLowerLeft = "╚";
    filledRectangle->cornerUpperRight = "╗";
    filledRectangle->cornerLowerRight = "╝";
    filledRectangle->cornerUpperLeft = "╔";
    filledRectangle->horizontalLine = "═";
    filledRectangle->verticalLine = "║";

    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Welcome to Connect Four!", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 5}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Menu", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"1 - Play", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 10}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"2 - Continue", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 11}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"3 - Help", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 12}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"4 - Quit", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 13}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Please enter an option: ", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 15}));
    screen.cursorPos = Position{34, 15};
    _mainMenu = screen;
}

UI::Screen Control::_playerTypeMenu = UI::Screen();	// Initialize static member

void Control::initPlayerTypeMenu()
{
    using namespace UI::Primitive;
    UI::Screen screen = UI::Screen();  
    
    screen.elements.push_back(std::make_shared<UI::Element::FilledRectangle>(Position{7, 3}, 30, 5));
    auto filledRectangle = dynamic_cast<UI::Element::FilledRectangle* const>(screen.elements[0].get());
    filledRectangle->backgroundColor = ANSI::Color::BLACK;
    filledRectangle->foregroundColor = ANSI::Color::GREEN;

    filledRectangle->cornerLowerLeft = "╚";
    filledRectangle->cornerUpperRight = "╗";
    filledRectangle->cornerLowerRight = "╝";
    filledRectangle->cornerUpperLeft = "╔";
    filledRectangle->horizontalLine = "═";
    filledRectangle->verticalLine = "║";

    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Welcome to Connect Four!", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 5}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Game Mode", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{10, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"1 - Player vs Player", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{10, 10}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"2 - Player vs Bot", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{10, 11}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"3 - Bot vs Bot", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{10, 12}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"4 - Back", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{10, 13}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Please enter an option: ", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{10, 15}));
    screen.cursorPos = Position{34, 15};
    _playerTypeMenu = screen;
}

void Control::initBotTypeMenu(uint8_t botNumber)
{
    using namespace UI::Primitive;
    UI::Screen screen = UI::Screen();  
    
    screen.elements.push_back(std::make_shared<UI::Element::FilledRectangle>(Position{7, 3}, 30, 5));
    auto filledRectangle = dynamic_cast<UI::Element::FilledRectangle* const>(screen.elements[0].get());
    filledRectangle->backgroundColor = ANSI::Color::BLACK;
    filledRectangle->foregroundColor = ANSI::Color::GREEN;

    filledRectangle->cornerLowerLeft = "╚";
    filledRectangle->cornerUpperRight = "╗";
    filledRectangle->cornerLowerRight = "╝";
    filledRectangle->cornerUpperLeft = "╔";
    filledRectangle->horizontalLine = "═";
    filledRectangle->verticalLine = "║";

    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Welcome to Connect Four!", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 5}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Bot #", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{10, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{std::to_string(botNumber), ANSI::Color::MAGENTA, ANSI::Color::BLACK}, Position{15, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{": Select Mode", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{16, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"1 - Column Bot", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{10, 10}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"2 - Horizontal Bot", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{10, 11}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"3 - Vertical Bot", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{10, 12}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"4 - Random Bot", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{10, 13}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"5 - Back", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{10, 14}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Please enter an option: ", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{10, 16}));
    screen.cursorPos = Position{34, 16};
    _botTypeMenu = screen;
}

void Control::runProgram()
{
    while(showMainMenu());
}

bool Control::showMainMenu()
{
    UI::Screen::setBackgroundColor(UI::Primitive::ANSI::Color::BLACK);
    initMainMenu();
    _mainMenu.displayScreen();
    int selection = 0;
    while ((selection = getNummericInput()) != 4)
    {
        
        switch (selection)
        {
        case 1:
            newGame();
            break;
        case 2:
            continueGame();
            break;
        case 3:
            showHelp();
            break;
        }
        _mainMenu.displayScreen();
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

UI::Screen Control::_gameWindow = UI::Screen();

void Control::initGameScreen()
{
    const uint16_t xOffset = 8;
    UI::Screen gameWindow = UI::Screen();
    gameWindow.elements.push_back(std::make_unique<UI::Element::Text>(UI::Primitive::FormattedText{"Player 1 to move!", UI::Primitive::ANSI::Color::RED, UI::Primitive::ANSI::Color::BLACK}, Position{xOffset+1, 2}));
    //gameWindow.elements.push_back(std::make_unique<UI::Element::Text>(UI::Primitive::FormattedText{"Hello World!", UI::Primitive::ANSI::Color::RED, UI::Primitive::ANSI::Color::BLACK}, Position{20, 11}));
    gameWindow.elements.push_back(std::make_unique<UI::Element::EvenGrid>(7,6,1,1,Position{xOffset+2,4}));
    gameWindow.elements.push_back(std::make_unique<UI::Element::Text>(UI::Primitive::FormattedText{"1 2 3 4 5 6 7", UI::Primitive::ANSI::Color::BRIGHT_GREEN, UI::Primitive::ANSI::Color::BLACK}, Position{xOffset+3, 17}));

    _gameWindow = gameWindow;
}

void Control::newGame()
{
    UI::Screen::setBackgroundColor(UI::Primitive::ANSI::Color::BLACK);
    initPlayerTypeMenu();
    _playerTypeMenu.displayScreen();
    uint32_t selection;
    while ((selection = getNummericInput()) != 4)
    {
        std::shared_ptr<Actor> player1;
        std::shared_ptr<Actor> player2;
        switch (selection)
        {
        case 1:
            player1 = std::make_shared<Player>(playerTurnInput);
            player2 = std::make_shared<Player>(playerTurnInput);
            break;
        case 2:
            player1 = std::make_shared<Player>(playerTurnInput);
            player2 = getBot(1);
            break;
        case 3:
            player1 = getBot(1);
            player2 = getBot(2);
            break; 
        default:
            _playerTypeMenu.displayScreen();
            continue;

        Game game(player1, player2, 7, 6, turnCallback);
        game.run();
        }
    }
}

void Control::continueGame()
{

}

void Control::showHelp()
{
    
}

void Control::turnCallback(const Game& game)
{
    
}

UI::Screen Control::_botTypeMenu = UI::Screen();

std::shared_ptr<Actor> Control::getBot(uint8_t botNumber)
{
    initBotTypeMenu(botNumber);
    _botTypeMenu.displayScreen();
    int selection;
    while ((selection = getNummericInput()) != 5)
    {
        switch (selection)
        {
        case 1:
            return std::make_shared<ColumnBot>();
        case 2:
            return std::make_shared<HorizontalBot>();
        case 3:
            return std::make_shared<VerticalBot>();
        case 4:
            return std::make_shared<RandomBot>();
        default:
            _mainMenu.displayScreen();
        }
    }
}

uint16_t Control::playerTurnInput(const Game& game)
{
    return 0;
}