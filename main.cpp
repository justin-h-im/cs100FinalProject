// Author: Justin Im
/* This serves as the infinite loop that the chess game will
function on. The entire game operates in the command line.
This main function assumes the completion of the
following classes:
* Piece
* Board
* UI (which interacts with Board)
*/

// Necessary includes.
#include "../include/ui.h"
using namespace std;

int main() {
    // Generates a new ui for the game instance.
    ui *UserInterface = new ui();
    // Output Start Menu.
    /* This function reads input from the terminal and decides:
    *1: Start the game. First player is white and second player is black by default. Enters the infinite game cycle while loop.
    *2: Quit the game. IDoes not enter the game cycle loop and returns 0.  */
    bool runGame = UserInterface->outputStartMenu();
    while(UserInterface->outputTurnMenu()) {
        /* Print output menu. Get user coordinate selection
        * Send that selection to board class for verification.
        * If bad flag, print again.
        * If good flag, get user new position coords.
        * Send that selection to piece class for verification.
        * 
        * Get a next action from board.
        * 1. No piece there: print output menu but toggle for color.
        * 2. Piece there: combat scenario.
        * 3. Invalid turn: invalid new slot.
        * */

        /* If the king is dead during a combat scenario, the runGame flag is triggered to false.
        The game ends with a cout message.*/    
    }

    return 0;
}