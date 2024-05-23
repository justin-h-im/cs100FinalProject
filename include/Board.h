#pragma once

#include "../include/piece.h"

#include <vector>


// class responsible for storing where pieces are on the board
class Board {
	private:
		// board is a 2d array storing pointers to the pieces (if there is no piece it stores nullptr)
		Piece* square[8][8];

		int kingX; // X position of the king
    	int kingY; // Y position of the king

		

	public:
		// sets up the board to the standard start for chess
		Board();
		// moves a piece
		void updateBoard(int oldX, int oldY, int newX, int newY);
		// determines there a player can move whatever is at the location
		bool verifyPieceToMove(int x, int y);
		// Returns whatever piece is at that square
		Piece* getStatus(int x, int y);
};