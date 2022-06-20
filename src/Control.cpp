#include "Control.h"
#include "logic/actors/Player.h"

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
    std::getline(std::cin, input);
    try
    {
        return std::stoi(input);
    }
    catch(const std::invalid_argument&)
    {
        return 0;
    }
    catch(const std::out_of_range&)
    {
        return 0;
    }
}

UI::Screen Control::_gameScreen = UI::Screen();

std::vector<std::shared_ptr<UI::Element::UIElement>> Control::createUIElementsBoard(const Game& game, Position gridPosition)
{
    std::vector<std::shared_ptr<UI::Element::UIElement>> elements;
    Position currentCellPosition = gridPosition;
    uint16_t i2 = 0;
    for(int i = game.getBoard().height-1; i>=0; i--)
    {
        for(int j=game.getBoard().width-1; j>=0; j--)
        {
            currentCellPosition = Position{ static_cast<uint16_t>(gridPosition.x+1+4*j), static_cast<uint16_t>(gridPosition.y+1+2*i2)};

            if(game.getBoard().getCell(j,i) == Board::CellState::EMPTY)
            {
                elements.push_back(std::make_shared<UI::Element::Text>(UI::Primitive::FormattedText{"   ", UI::Primitive::ANSI::Color::CYAN, UI::Primitive::ANSI::Color::BLACK}, Position{currentCellPosition}));
            }
            else if(game.getBoard().getCell(j,i) == Board::CellState::PLAYER1)
            {
                elements.push_back(std::make_shared<UI::Element::Text>(UI::Primitive::FormattedText{" ● ", UI::Primitive::ANSI::Color::BRIGHT_MAGENTA, UI::Primitive::ANSI::Color::BLACK}, Position{currentCellPosition}));
            }
            else if(game.getBoard().getCell(j,i) == Board::CellState::PLAYER2)
            {
                elements.push_back(std::make_shared<UI::Element::Text>(UI::Primitive::FormattedText{" ● ", UI::Primitive::ANSI::Color::YELLOW, UI::Primitive::ANSI::Color::BLACK}, Position{currentCellPosition}));
            }
        }
        i2++;
    }
    return elements;
}

void Control::initGameScreen(const Game& game)
{
    const uint16_t xOffset = 8;
    UI::Screen gameScreen = UI::Screen();
    Position gridPosition = Position{xOffset + 2,4};
    //std::string turnChar = "1";

    gameScreen.elements.push_back(std::make_unique<UI::Element::Text>(UI::Primitive::FormattedText{"Somebody please make a move", UI::Primitive::ANSI::Color::RED, UI::Primitive::ANSI::Color::BLACK}, Position{xOffset+1, 2}));
    gameScreen.elements.push_back(std::make_unique<UI::Element::EvenGrid>(game.getBoard().width,game.getBoard().height,3,1,gridPosition));
    auto grid = dynamic_cast<UI::Element::EvenGrid* const>(gameScreen.elements.back().get());
    grid->backgroundColor = UI::Primitive::ANSI::Color::BLACK;
    grid->foregroundColor = UI::Primitive::ANSI::Color::BRIGHT_CYAN;
    auto boardUIElements = createUIElementsBoard(game, gridPosition);
    gameScreen.elements.push_back(std::make_unique<UI::Element::Text>(UI::Primitive::FormattedText{" 1   2   3   4   5   6   7", UI::Primitive::ANSI::Color::BRIGHT_GREEN, UI::Primitive::ANSI::Color::BLACK}, Position{xOffset+3, 17}));
    gameScreen.elements.insert(gameScreen.elements.end(), boardUIElements.begin(), boardUIElements.end());
    if (std::dynamic_pointer_cast<Player>(game.getCurrentActor()) != nullptr) {
        gameScreen.elements.push_back(std::make_shared<UI::Element::Text>(UI::Primitive::FormattedText{"Please enter a row to drop your coin: ", UI::Primitive::ANSI::Color::GREEN, UI::Primitive::ANSI::Color::BLACK}, Position{xOffset, 20}));
        gameScreen.cursorPos = Position{xOffset+38, 20};
    }
    else {
        gameScreen.elements.push_back(std::make_shared<UI::Element::Text>(UI::Primitive::FormattedText{"Press <ENTER> for next step! ", UI::Primitive::ANSI::Color::GREEN, UI::Primitive::ANSI::Color::BLACK}, Position{xOffset, 20}));
        gameScreen.cursorPos = Position{xOffset+29, 20};
    }
    _gameScreen = gameScreen;
}

static size_t gameTurn = 0;
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
        gameTurn = 0;
        Game game(player1, player2, 7, 6, turnCallback);
        initVictoryScreen(game.run());
        _victoryScreen.displayScreen();
        getNummericInput();
        break;
    }
}

void Control::turnCallback(const Game& game)
{
    if (gameTurn++ != 0 && std::dynamic_pointer_cast<Player>(game.getLastActor()) == nullptr) {
        getNummericInput();
    }
    initGameScreen(game);
    _gameScreen.displayScreen();
}

uint16_t Control::playerTurnInput(const Game& game)
{
    uint32_t column = getNummericInput();

    // reset cursor position
    initGameScreen(game);
    _gameScreen.displayScreen();

    return column - 1;
}

void Control::continueGame()
{

}

void Control::showHelp()
{
    
}

UI::Screen Control::_botTypeMenu = UI::Screen();

std::shared_ptr<Actor> Control::getBot(uint8_t botNumber)
{
    initBotTypeMenu(botNumber);
    _botTypeMenu.displayScreen();
    while (true)
    {
        switch (getNummericInput())
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
            _botTypeMenu.displayScreen();
            continue;
        }
    }
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

    screen.elements.push_back(std::make_shared<UI::Element::Text>(FormattedText{"Press <ENTER> to continue: ", ANSI::Color::GREEN, ANSI::Color::BLACK}, Position{10, 14}));
    
    screen.cursorPos = Position{37, 14};
    _victoryScreen = screen;
}
