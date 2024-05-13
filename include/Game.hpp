#include "Piece.hpp"

class Game {
	private:
		Piece* square[8][8];
		bool check;
		color turn;
	public:
		Game();
		void displayBoard();
		bool kingStatus();
		
};