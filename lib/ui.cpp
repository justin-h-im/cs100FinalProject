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
            // FIXME: Implement RuleBook. 
            continue;
        }
        else {
            break;
        }
    }
    cout << "Farewell." << endl;
    return false;
}


bool ui::outputTurnMenu() {
    // FIXME:: Implment turn toggling. 
    string turn = "WHITE";
    if (game->getTurn() == Color::BLACK) {
        turn = "BLACK";
    }

    cout << "PLAYER " << turn << "TURN" << endl;
    int xCoord = 0; int yCoord = 0;

    cout << "State the location of your vassal: " << endl;

    while (1) {
        cin >> xCoord;
        if (!cin.good() || xCoord < 0 || xCoord > 7) {
            cout << "Your vassal cannot be outside the battlefield." << endl;
        }
    }

    while (1) {
        cin >> yCoord;
        if (!cin.good() || yCoord < 0 || yCoord > 7) {
            cout << "Your vassal cannot be outside the battlefield." << endl;
        }
    }
 
    // If board->verifyPieceToMove(x, y) is false, toggle game turn and return to main. 
    if (!board->verifyPieceToMove(xCoord, yCoord)) {
        cout << "Your mistaken hand has cost you your turn." << endl;
        game->updateTurn();
        return true;
    }

    int newXCoord = 0; int newYCoord = 0;
    cout << "State the new location for your vassal: " << endl;

    while (1) {
        cin >> newXCoord;
        if (!cin.good() || newXCoord < 0 || newXCoord > 7) {
            cout << "Your vassal does not understand your command." << endl;
        }
    }

    while(1) {
        cin >> newYCoord;
        if (!cin.good() || newYCoord < 0 || newYCoord > 7) {
            cout << "Your vassal does not understand your command." << endl;
        }
    }

    // Toggle Game turn and return to main if this returns false.
    if (!board->verifyMove(newXCoord, newYCoord)) {
        cout << "Your careless command has cost you your turn." << endl;
        game->updateTurn();
        return true;
    }
    // If there is not a piece at the new location, just move the piece. Then toggle the turn and return to main.
    Piece* possiblePiece = board->getPiece(newXCoord, newYCoord);
    if (possiblePiece == nullptr) {
        board->updateBoard(xCoord, yCoord, newXCoord, newYCoord);
        cout << "Successful move, your highness." << endl;
        game->updateTurn();
        return true;
    }
    // If there is an allied piece at the new location, turn is switched and the game continues. 
    else if (possiblePiece->getColor() == game->getTurn()) {
        cout << "Your subject exists at that slot. Your actions have caused confusion on the battlefield, costing you your turn." << endl;
        game->updateTurn();
        return true;
    }
    // If there is a piece at the new location, activate combat scenario
    else {
        /* Check for game ending within combat scenario (king death) and respond to death accordingly. */
        if (game->blackWin() || game->whiteWin()) {
            outputEndScreen();
        }
        return false;
    }

    game->updateTurn();
    return true;
}

void outputUserGuide() {
    ifstream userGuide("Combat Chess User Guide");
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

    }
    else {
        
    }
}