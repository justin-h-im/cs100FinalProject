#include "./lib/Display.h"
class Display {
	private:
		Board board;
		void displayBlackPiece(Piece*);
		void displayWhitePiece(Piece*);
		void printWhitePawn();
		void printWhiteKnight();
		void printWhiteBishop();
		void printWhiteRook();
		void printWhiteQueen();
		void printWhiteKing();
		void printBlackPawn();
		void printBlackKnight();
		void printBlackBishop();
		void printBlackRook();
		void printBlackQueen();
		void printBlackKing();
	public: 
		void displayBoard();
		void displayCombat(Piece*, Piece*);
};