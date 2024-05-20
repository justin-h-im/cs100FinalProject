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
		// determines if 
		bool verifyPieceToMove(int x, int y);
		bool verifyMove(const vector<int>&, const vector<int>&);
		Piece* getStatus(int x, int y);
};