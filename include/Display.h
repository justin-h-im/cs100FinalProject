#include "./lib/Display.h"
class Display {
	private:
		Board board;
		void displayBlackPiece(Piece*);
		void displayWhitePiece(Piece*);
	public: 
		void displayBoard();
		void displayCombat(Piece*, Piece*);
};