// Author: Justin Im
/* This class serves as an interface at which the Board and Piece
interact with the user. For example, the ui class reads input from
and performs the correct actions, and the ui class outputs back
to terminal to prompt for more user input. */

#include "../include/ui.h"

// Necessary includes for printing to terminal.

using namespace std;

// Constructor
ui::ui() {
    board = new Board();
    game = new Game();
    board->setGame(game);
    game->setBlackKing(board->getPiece(0, 4));
    game->setWhiteKing(board->getPiece(7, 4));
    display = new Display(board);
}

ui::~ui() {
    delete board;
    delete display;
    delete game;
}

bool ui::outputStartMenu() {
    int userInput = 0;
    cout << "Welcome to Combat Chess." << endl;
    while (1) {
        cout << "Make your selection." << endl;
        cout << "1: Start game." << endl;
        cout << "2: Rule book." << endl;
        cout << "3: Quit." << endl;
        cin >> userInput;
        if (!cin.good()) {
            continue;
        }
        // FIXME: Implement a switch statement.
        else if (userInput == 1) {
            cout << "Game Starto!" << endl;
            return true;
        }
        else if (userInput == 2) {
            outputUserGuide();
        }
        else {
            break;
        }
    }
    cout << "Farewell." << endl;
    return false;
}

bool ui::outputTurnMenu() {
    // Prints color turn.
    string turn = "WHITE";
    if (game->getTurn() == Color::BLACK) {
        turn = "BLACK";
    }
    cout << "PLAYER " << turn << " TURN" << endl;
    int oldX = 0; int oldY = 0;

    display->displayBoard();

    // Prints user for valid x and y locations for the piece that they want to move. 
    cout << "State the location of your vassal: " << endl;
    while (1) {
        cout << "Proclaim the location, in the X direction: " << endl;
        cin >> oldX;
        if (cin.good() && oldX == -1) {
            cout << "Do you want to end the game? Y/N" << endl;
            char option;
            cin >> option;
            if (option == 'Y' || option == 'y') {
                cout << "Farewell." << endl;
                return false;
            }
            continue;
        }
        if (!cin.good() || oldX < 0 || oldX > 7) {
            cout << "Your vassal cannot be outside the battlefield. They await new orders." << endl;
        }
        else {
            break;
        }
    }
    while (1) {
        cout << "Decree the location, in the Y direction. " << endl;
        cin >> oldY;
        if (cin.good() && oldY == -1) {
            cout << "Do you want to end the game? Y/N" << endl;
            char option;
            cin >> option;
            if (option == 'Y' || option == 'y') {
                cout << "Farewell." << endl; 
                return false;
            }
            continue;
        }
        if (!cin.good() || oldY < 0 || oldY > 7) {
            cout << "Your vassal cannot be outside the battlefield. They await new orders." << endl;
        }
        else {
            break;
        }
    }
    int newX = 0; int newY = 0;
    // Repeatedly prompts the user for the location that they want to move th epiece to.
    cout << "State the new location for your vassal: " << endl;
    while (1) {
        if (cin.good() && newX == -1) {
            cout << "Do you want to end the game? Y/N" << endl;
            char option;
            cin >> option;
            if (option == 'Y' || option == 'y') {
                cout << "Farewell;" << endl;
                return false;
            }
            continue;
        }
        cout << "Herald the new location in the X direction." << endl;
        cin >> newX;
        if (!cin.good() || newX < 0 || newX > 7) {
            cout << "Your vassal does not understand your command." << endl;
        }
        else {
            break;
        }
    }
    while(1) {
        cout << "Promulgate the new location in the Y direction." << endl;
        cin >> newY;
        if (cin.good() && newY == -1 ) {
            cout << "Do you want to end the game? Y/N" << endl;
            char option;
            cin >> option;
            if (option == 'Y' || option == 'y') {
                cout << "Farewell." << endl;
                return false;
            }
            continue;
        }
        if (!cin.good() || newY < 0 || newY > 7) {
            cout << "Your vassal does not understand your command." << endl;
        }
        else {
            break;
        }
    }
    
    int result = board->verifyMove(oldY, oldX, newY, newX);
    if (result == -1) {
        cout << "Thou are fit to be a court jester, not a lord." << endl;
        return true;
    }
    else if (result == 0) {
        cout << "Sucessful move, my liege." << endl;
        return true;
    }
    // If there is a piece at the new location, activate combat scenario
    else {
        // 
        Piece* attacker = board->getPiece(oldY, oldX);
        Piece* defender = board->getPiece(newY, newX);
        display->displayCombat(attacker, defender);
        Combat combat(attacker, defender, display, game);
        combat.startCombat();
        /* Check for game ending within combat scenario (king death) and respond to death accordingly. */
        // check if black king or white king is dead (currHP == 0)
        if (game->blackWin() || game->whiteWin()) {
            outputEndScreen();
        }
        return true;
    }
    
    return true;
}

void ui::outputUserGuide() {
    ifstream userGuide("include/CombatChessUserGuide.txt");
    if (userGuide.is_open()) {
        cout << userGuide.rdbuf();
    }
    else {
        cout << "The guide has failed to open! Please return to menu and try again." << endl;
    }

    string quitChar;
    cout << "Press 'q' to quit." << endl;
    while (1) {
        cin >> quitChar;
        if (!cin.good() || quitChar != "q") {
            continue;
        }
        if (quitChar == "q") {
            return;
        }
    }
}

void ui::outputEndScreen() {
    if (game->blackWin()) {
        cout << "Black wins!" << endl;
    }
    else if (game->whiteWin()) {
        cout << "White wins!" << endl;
    }
    else {
        cout << "Both kings remain!" << endl;
    }
}