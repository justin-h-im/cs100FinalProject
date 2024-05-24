#pragma once

class Piece;
class Game;

// class is responsible for storing where pieces are on the board
class Board {
	private:
		// board is a 2d array storing pointers to the pieces (if there is no piece it stores nullptr)
		Game game;
		Piece* square[8][8];
	public:
		// sets up the board to the standard start for chess
		Board();
		// moves a piece
		void updateBoard(int oldX, int oldY, int newX, int newY);
		// determines there a player can move whatever is at the location
		bool verifyPieceToMove(int x, int y) const;
		// determines if the player is making a possible move
		int verifyMove(int x, int y) const;
		// Returns whatever piece is at that square
		Piece* getPiece(int x, int y) const;
};