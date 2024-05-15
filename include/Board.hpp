#include "Piece.hpp"

class Game {
	private:
		Piece* square[8][8];
		bool check;
		color turn;
	public:
		Game();
		Color getTurn();
		void displayBoard();
		void updateBoard(int oldX, int oldY, int newX, int newY);
		bool verifyPieceExists(int x, int y);
		bool verifyCoordinates(const vector<int>&, const vector<int>&);
		bool kingStatus();
};