// Author: Justin Im
/* This class serves as an interface at which the Board and Piece
interact with the user. For example, the ui class reads input from
and performs the correct actions, and the ui class outputs back
to terminal to prompt for more user input. */

/* Cycle should be as follows:
* main: infinite while loop calling outputMenu().
* Player chooses to make a turn.
* Another infinite loop that calls outputTurnMenu().*/



#pragma once

// #include "board.h"
// #include "piece.h"

class ui {
    private:



    public:
        // Constructor
        ui() {}
        // Destructor
        ~ui() {}



        /* Outputs start menu from before the game starts. If the return statement is true, then the game begins. 
         Otherwise, the game ends. */
        bool outputStartMenu();

        // Outputs the menu that occurs during the game cycle.
        /* Should have interface for turns, such as selecting
        a piece, and asking for the move location. Since it is 
        one touch chess, the player should not be allowed to revert
        and choose a different piece. */
        void outputTurnMenu();



        /* Gets the user input, and then sends it to board. If board states that there is no piece, then we exit out of the function
         and then start again from the output. */

        // Basically calls printBoard from the game class. 
        void printGame();
};