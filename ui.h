// Author: Justin Im
/* This class serves as an interface at which the Board and Piece
interact with the user. For example, the ui class reads input from
and performs the correct actions, and the ui class outputs back
to terminal to prompt for more user input. */

#pragma once
#include <iostream>
// #include "board.h"
// #include "piece.h"

class ui {
    private:



    public:
        // Outputs start menu from before the game starts. 
        void outputMenu();
        // Outputs the menu that occurs during the game cycle.
        /* Should have interface for turns, such as selecting
        a piece, and asking for the move location. Since it is 
        one touch chess, the player should not be allowed to revert
        and choose a different piece. */
        void outputTurnMenu();

        // Basically calls printBoard from the game class. 
        void printGame();
};