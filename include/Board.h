#pragma once

class Piece;
class Game;

// class responsible for storing where pieces are on the board
class Board {
	private:
		// board is a 2d array storing pointers to the pieces (if there is no piece it stores nullptr) 
		Game game;
		Piece* square[8][8];
		// determines there a player can move whatever is at the location
		bool verifyPieceToMove(int y, int x) const;
	public:
		// sets up the board to the standard start for chess
		Board();
		~Board();
		// moves a piece
		void updateBoard(int oldY, int oldX, int newY, int newX);
		// determines if the player is making a possible move
		int verifyMove(int oldY, int oldX, int newY, int newX) const;
		// Returns whatever piece is at that square
		Piece* getPiece(int y, int x) const;
		// places a piece (for pawn promotion)
		void placePiece(int y, int x, Piece* piece);
		// sets the game
		void setGame(Game* game);
};