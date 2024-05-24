#pragma once

#include "../include/piece.h"

// class responsible for keeping track of the game's status
// this includes keeping track of which player's turn it is along with if a player has won based on king HP
class Game {
	private:
		Color turn = Color::WHITE;
		Piece* whiteKing;
		Piece* blackKing;
	public:
		Game();
		Color getTurn();
		void updateTurn();
		bool whiteWin();
		bool blackWin();
		void setWhiteKing(Piece*);
		void setBlackKing(Piece*);
};