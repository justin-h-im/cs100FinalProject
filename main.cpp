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
#include "include/ui.h"
#include "include/Board.h"
#include "include/Display.h"
#include "include/piece.h"
#include "include/pawn.h"
#include "include/knight.h"
#include "include/rook.h"
#include "include/bishop.h"
#include "include/queen.h"
#include "include/king.h"

using namespace std;

int main() {
		// Generates a new ui for the game instance.
    ui *UserInterface = new ui();
    // Output Start Menu.
    /* This function reads input from the terminal and decides:
    *1: Start the game. First player is white and second player is black by default. Enters the infinite game cycle while loop.
    *2: Quit the game. IDoes not enter the game cycle loop and returns 0.  */
    bool runGame = UserInterface->outputStartMenu();
    if (!runGame) {
        return 0;
    }
    UserInterface->outputTurnMenu();


    // while() {
    //     /* Print output menu. Get user coordinate selection
    //     * Send that selection to board class for verification.
    //     * If bad flag, print again.
    //     * If good flag, get user new position coords.
    //     * Send that selection to piece class for verification.
    //     * 
    //     * Get a next action from board.
    //     * 1. No piece there: print output menu but toggle for color.
    //     * 2. Piece there: combat scenario.
    //     * 3. Invalid turn: invalid new slot.
    //     * */

    //     /* If the king is dead during a combat scenario, the runGame flag is triggered to false.
    //     The game ends with a cout message.*/    
		// }

	// if (true) {
	// 	Board *board = new Board();
	// 	Display display(board);

	// 	display.displayBoard();
	// 	display.displayCombat(board->getPiece(0, 4), board->getPiece(7, 4));
	// }
  delete UserInterface;
  return 0;
}