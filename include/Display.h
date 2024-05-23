#include "./lib/Display.h"
class Display {
	private:
		void displayWhitePiece(Piece* piece);
	public: 
		void displayBoard();
		void displayCombat(Piece*, Piece*);
};