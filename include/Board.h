#pragma once

class Piece;
class Game;

// class responsible for storing where pieces are on the board
class Board {
	private:
		// board is a 2d array storing pointers to the pieces (if there is no piece it stores nullptr)
		Piece* square[8][8];
		Game* game;
	public:
		// sets up the board to the standard start for chess
		Board();
		// sets the board's game to a pointer to a game
		void setGame(Game* game);
		// moves a piece
		void updateBoard(int oldX, int oldY, int newX, int newY);
		// determines there a player can move whatever is at the location
		bool verifyPieceToMove(int x, int y) const;
		// determines if the player is making a possible move
		int verifyMove(int x1, int y1, int x2, int y2);
		// Returns whatever piece is at that square
		Piece* getPiece(int x, int y) const;

		void placePiece(int x, int y, Piece* piece);

};