// Author: Justin Im
/* This class serves as an interface at which the Board and Piece
interact with the user. For example, the ui class reads input from
and performs the correct actions, and the ui class outputs back
to terminal to prompt for more user input. */

#include "ui.h"

// Necessary includes for printing to terminal.
#include <iostream>
#include <ostream>
using namespace std;

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


void ui::outputTurnMenu() {
    cout << "PLAYER " << "TURN" << endl;

    bool flag = 1;
    int x; int y;
    while (flag) {
        cout << "State the location of your vassal: " << endl;
        cin >> x;
        if (!cin.good() || x < 0 || x > 7) {
            cout << "Your vassal cannot flee the battlefield." << endl;
            continue;
        }
        else {
            cin >> y;
            if (!cin.good() || y < 0 || y > 7) {
                cout << "Your vassal cannot flee the battlefield." << endl;
                continue;
            }
        }

        // if game::validInput from cin is invalid, flag remains 1.
        // else, flag = 0
    }

    flag = 1;

    while (flag) {
        cout << "State the new location for your vassal: " << endl;
        // cin
        // check for 0-7 value. if false, flag remains 1. 
        // if piece::validNewLoc from cin is invalid, flag remains 1.
        // if game::isCombat is valid, flag goes to 0, and combat scenario is activated.
    }
    // FIXME: Enter seprate cout for combat scenario, pr manage combat scenario menu here?
}