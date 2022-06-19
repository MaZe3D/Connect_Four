#include "Control.h"

UI::Screen Control::_mainMenu = UI::Screen();	// Initialize static member

void Control::initMainMenu()
{
    using namespace UI::Primitive;
    UI::Screen screen = UI::Screen();
 
 
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"  _____                            _     ______", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 2}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{" / ____|                          | |   |  ____|", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 3}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |     ___  _ __  _ __   ___  ___| |_  | |__ ___  _   _ _ __", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 4}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |    / _ \\| '_ \\| '_ \\ / _ \\/ __| __| |  __/ _ \\| | | | '__|", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 5}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |___| (_) | | | | | | |  __/ (__| |_  | | | (_) | |_| | |", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 6}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{" \\_____\\___/|_| |_|_| |_|\\___|\\___|\\__| |_|  \\___/ \\__,_|_|", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 7}));   

    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Main Menu", ANSI::Color::BRIGHT_MAGENTA, ANSI::Color::BLACK}, Position{10, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"1 - Play", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 10}));
    //screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"2 - Continue", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 11}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"3 - Help", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 12}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"4 - Quit", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 13}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Please enter an option: ", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{10, 15}));
    screen.cursorPos = Position{34, 15};
    _mainMenu = screen;
}

UI::Screen Control::_playerTypeMenu = UI::Screen();	// Initialize static member

void Control::initPlayerTypeMenu()
{
    using namespace UI::Primitive;
    UI::Screen screen = UI::Screen();  

    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"  _____                            _     ______", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 2}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{" / ____|                          | |   |  ____|", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 3}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |     ___  _ __  _ __   ___  ___| |_  | |__ ___  _   _ _ __", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 4}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |    / _ \\| '_ \\| '_ \\ / _ \\/ __| __| |  __/ _ \\| | | | '__|", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 5}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |___| (_) | | | | | | |  __/ (__| |_  | | | (_) | |_| | |", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 6}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{" \\_____\\___/|_| |_|_| |_|\\___|\\___|\\__| |_|  \\___/ \\__,_|_|", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 7}));   


    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Game Mode", ANSI::Color::BRIGHT_MAGENTA, ANSI::Color::BLACK}, Position{10, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"1 - Player vs Player", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 10}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"2 - Player vs Bot", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 11}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"3 - Bot vs Bot", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 12}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"4 - Back", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 13}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Please enter an option: ", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{10, 15}));
    screen.cursorPos = Position{34, 15};
    _playerTypeMenu = screen;
}

void Control::initBotTypeMenu(uint8_t botNumber)
{
    using namespace UI::Primitive;
    UI::Screen screen = UI::Screen();  
    
        screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"  _____                            _     ______", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 2}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{" / ____|                          | |   |  ____|", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 3}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |     ___  _ __  _ __   ___  ___| |_  | |__ ___  _   _ _ __", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 4}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |    / _ \\| '_ \\| '_ \\ / _ \\/ __| __| |  __/ _ \\| | | | '__|", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 5}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |___| (_) | | | | | | |  __/ (__| |_  | | | (_) | |_| | |", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 6}));   
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{" \\_____\\___/|_| |_|_| |_|\\___|\\___|\\__| |_|  \\___/ \\__,_|_|", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{8, 7}));

    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Bot ", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{10, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"#" + std::to_string(botNumber), ANSI::Color::BRIGHT_MAGENTA, ANSI::Color::BLACK}, Position{14, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{": Select Mode", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{16, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"1 - Column Bot", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 10}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"2 - Horizontal Bot", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 11}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"3 - Vertical Bot", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 12}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"4 - Random Bot", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 13}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Please enter an option: ", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{10, 15}));
    screen.cursorPos = Position{34, 15};
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

UI::Screen Control::_gameScreen = UI::Screen();

void Control::createUIElementsBoard(const Game& game, Position gridPosition)
{

    Position currentCellPosition = gridPosition;
    for(int i = 0; i<game.getBoard().height; i++)
    {
        gotoXY(gridPosition);
        for(int j=game.getBoard().width-1; j>0; j--)
        {
            currentCellPosition = Position{ static_cast<uint16_t>(gridPosition.x+2+4*j), static_cast<uint16_t>(gridPosition.y+2+2*i)};

            if(game.getBoard().getCell(j,i) == Board::CellState::EMPTY)
            {
                gotoXY(currentCellPosition);
                UI::Primitive::printFormattedText(UI::Primitive::FormattedText{" ",UI::Primitive::ANSI::Color::DEFAULT,UI::Primitive::ANSI::Color::BLACK},currentCellPosition);
            }
            else if(game.getBoard().getCell(j,i) == Board::CellState::PLAYER1)
            {
                _gameScreen.elements.push_back(std::make_unique<UI::Element::Text>(UI::Primitive::FormattedText{" • ", UI::Primitive::ANSI::Color::BRIGHT_MAGENTA, UI::Primitive::ANSI::Color::BLACK}, Position{currentCellPosition}));
            }
            else if(game.getBoard().getCell(j,i) == Board::CellState::PLAYER2)
            {
                 _gameScreen.elements.push_back(std::make_unique<UI::Element::Text>(UI::Primitive::FormattedText{" • ", UI::Primitive::ANSI::Color::YELLOW, UI::Primitive::ANSI::Color::BLACK}, Position{currentCellPosition}));
            }
        }
    }
}

void Control::initGameScreen(const Game& game)
{
    const uint16_t xOffset = 8;
    UI::Screen gameScreen = UI::Screen();
    Position gridPosition = Position{xOffset + 2,4};
    //std::string turnChar = "1";

    //gameWindow.elements.push_back(std::make_unique<UI::Element::Text>(UI::Primitive::FormattedText{"Somebody please make a move", UI::Primitive::ANSI::Color::RED, UI::Primitive::ANSI::Color::BLACK}, Position{xOffset+1, 2}));
    //gameWindow.elements.push_back(std::make_unique<UI::Element::Text>(UI::Primitive::FormattedText{"Hello World!", UI::Primitive::ANSI::Color::RED, UI::Primitive::ANSI::Color::BLACK}, Position{20, 11}));
    gameScreen.elements.push_back(std::make_unique<UI::Element::EvenGrid>(game.getBoard().width,game.getBoard().height,3,1,gridPosition));
    auto grid = dynamic_cast<UI::Element::EvenGrid* const>(gameScreen.elements.back().get());
    grid->backgroundColor = UI::Primitive::ANSI::Color::BLACK;
    grid->foregroundColor = UI::Primitive::ANSI::Color::BRIGHT_CYAN;
    createUIElementsBoard(game, gridPosition);
    gameScreen.elements.push_back(std::make_unique<UI::Element::Text>(UI::Primitive::FormattedText{" 1   2   3   4   5   6   7", UI::Primitive::ANSI::Color::BRIGHT_GREEN, UI::Primitive::ANSI::Color::BLACK}, Position{xOffset+3, 17}));

    gameScreen.cursorPos = Position{xOffset+3, 19};
    _gameScreen = gameScreen;
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
        }
        Game game(player1, player2, 7, 6, turnCallback);
        initVictoryScreen(game.run());
        _victoryScreen.displayScreen();
        while(getNummericInput() != 0);
        break;
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
    initGameScreen(game);
    _gameScreen.displayScreen();
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
    uint16_t input;
    std::cin >> input;
    return input-1;
}

UI::Screen Control::_victoryScreen = UI::Screen();

void Control::initVictoryScreen(Game::GameResult gameResult)
{
    using namespace UI::Primitive;
    UI::Screen screen = UI::Screen();  
    
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"  _____          __  __ ______    ______      ________ _____", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 5}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{" / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 6}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 7}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 8}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 9}));
    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{" \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 10}));

    switch (gameResult)
    {  
    case Game::GameResult::PLAYER1:
        screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Victory for ", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{10, 12}));
        screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Player 1", ANSI::Color::BRIGHT_MAGENTA, ANSI::Color::BLACK}, Position{22, 12}));
        break;
    case Game::GameResult::PLAYER2:
        screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Victory for ", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{10, 12}));
        screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Player 2", ANSI::Color::YELLOW, ANSI::Color::BLACK}, Position{22, 12}));
        break;
    case Game::GameResult::DRAW:
        screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"The game is a draw!", ANSI::Color::CYAN, ANSI::Color::BLACK}, Position{10, 12}));
        break;
    }

    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Enter \'0\' to continue: ", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 14}));
    
    screen.cursorPos = Position{33, 14};
    _victoryScreen = screen;
}
