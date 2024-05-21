#include "../include/piece.h"

// class responsible for keeping track of the game's status
// this includes keeping track of which player's turn it is along with if a player has won based on king HP
class Game {
	private:
		bool check = false;
		Color turn = WHITE;
		Piece* whiteKing;
		Piece* blackKing;
	public:
		Game();
		Color getTurn();
		bool whiteWin();
		bool blackWin();
		void setWhiteKing(Piece*);
		void setBlackKing(Piece*);
};