#pragma once

#include "./Piece.hpp"

// class responsible for storing where pieces are on the board
class Board {
	private:
		// board is a 2d array storing pointers to the pieces (if there is no piece it stores nullptr)
		Piece* square[8][8];
	public:
		// sets up the board to the standard start for chess
		Board();
		// moves a piece
		void updateBoard(int oldX, int oldY, int newX, int newY);
		// determines there a player can move whatever is at the location
		bool verifyPieceToMove(int x, int y);
		// determines if the player is making a possible move
		bool verifyMove(const vector<int>&, const vector<int>&);
		// Returns whatever piece is at that square
		Piece* getStatus(int x, int y);
};