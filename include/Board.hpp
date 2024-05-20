#include "Piece.hpp"

class Board {
	private:
		Piece* square[8][8];
	public:
		Board();
		void updateBoard(int oldX, int oldY, int newX, int newY);
		bool verifyPieceExists(int x, int y);
		bool verifyCoordinates(const vector<int>&, const vector<int>&);
		Piece* getStatus(int x, int y);
};