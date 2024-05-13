// Author: Justin Im
/* This class serves as an interface at which the Board and Piece
interact with the user. For example, the ui class reads input from
and performs the correct actions, and the ui class outputs back
to terminal to prompt for more user input. */

#include "ui.h"

void ui::outputTurnMenu() {
    cout << "PLAYER " << /*Game::getColor()*/ << "TURN" << endl;

    bool flag = 1;
    while (flag) {
        cout << "Coordinates of a piece to be moved: " << endl;
        // cin
        // check for 0-7 value. if false, flag remains 1. 
        // if game::validInput from cin is invalid, flag remains 1.
        // else, flag = 0
    }

    flag = 1;

    while (flag) {
        cout << "Coordinates of the new piece's location: " << endl;
        // cin
        // check for 0-7 value. if false, flag remains 1. 
        // if piece::validNewLoc from cin is invalid, flag remains 1.
        // if game::isCombat is valid, flag goes to 0, and combat scenario is activated.
    }
    // FIXME: Enter seprate cout for combat scenario, pr manage combat scenario menu here?
}