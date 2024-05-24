#include "./include/Display.h"

void Board::displayBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Piece* curr = board.getPiece(i, j);
			if (curr != nullptr) {
				switch(curr->getPiece()) {
					cout << "|"
					case(KING):
					{
						if (curr.getColor() == WHITE) { cout << " ♔ ";} 
						else { cout << " ♚ "; }
						break;
					}
					case(QUEEN):
					{
						if (curr.getColor() == WHITE) { cout << " ♕ "; }
						else { cout << " ♛ ";}
						break;
					}
					case(PAWN):
					{
						if (curr.getColor() == WHITE) { cout << " ♙ "; }
						else { cout << "♟"; }
						break;
					}
					case(KNIGHT):
					{
						if (curr.getColor() == WHITE) { cout << " ♘ "; }
						else { cout << " ♞ "; }
						break;
					}
					case(BISHOP):
					{
						if (curr.getColor() == WHITE) { cout << " ♗ "; }
						else { cout << " ♝ "; }
						break;
					}
					case(ROOK):
					{
						if (curr.getColor() == WHITE) { cout << " ♖ "; }
						else { cout << " ♜ ";}
						break;
					}
				}
			}
			else { cout << "   "; }
		}
		cout << "|\n";
		cout << std::setfill('-') << std::setw(40) << endl;
	}
}

void Display::displayCombat(Piece* attacker, Piece* defender) {
	if (attacker->getColor() == WHITE) {
		displayWhitePiece(attacker);
		displayBlackPiece(defender);
	}
	else {
		displayWhitePiece(attacker);
		displayBlackPiece(defender);
	}
}

void Display::displayWhitePiece(Piece* piece) {
	switch(piece->getType()) {
		case PAWN:
			printWhitePawn();
			break;
		case KNIGHT:
			printWhiteKnight();
			break;
		case BISHOP
			printWhiteBishop();
			break;
		case ROOK:
			printWhiteRook();
			break;
		case QUEEN:
			printWhiteQueen();
			break;
		case KING:
			printWhiteKing();
			break;
	}
}

void Display::displayBlackPiece(Piece* piece) {
	switch(piece->getType()) {
	case PAWN:
		printBlackPawn();
		break;
	case KNIGHT:
		printBlackKnight();
		break;
	case BISHOP
		printBlackBishop();
		break;
	case ROOK:
		printBlackRook();
		break;
	case QUEEN:
		printBlackQueen();
		break;
	case KING:
		printBlackKing();
		break;
	}
}


void printWhitePawn() {
	cout << "             " << endl;
	cout << "     ■■■     " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "     ■■■     " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
	cout << "  ■■■■■■■■■  " << endl;
}

void printWhiteKnight() {
	cout << "             " << endl;
	cout << "     ■■■     " << endl;
	cout << "  ■■■■■■■    " << endl;
	cout << "  ■■■■■■■    " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
	cout << "  ■■■■■■■■■  " << endl;
}

void printWhiteBishop() {
	cout << "     ■■      " << endl;
	cout << "    ■■  ■    " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "     ■■■     " << endl;
	cout << "     ■■■     " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
}

void printWhiteRook() {
	cout << "             " << endl;
	cout << "   ■ ■ ■ ■   " << endl;
	cout << "   ■■■■■■■   " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
	cout << "  ■■■■■■■■■  " << endl;
}

void printWhiteQueen() {
	cout << "    ■ ■ ■    " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "     ■■■     " << endl;
	cout << "     ■■■     " << endl;
	cout << "     ■■■     " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
}

void printWhiteKing() {
	cout << "      ■      " << endl;
	cout << "   ■■■■■■■    " << endl;
	cout << "    ■■■■■      " << endl;
	cout << "     ■■■     " << endl;
	cout << "     ■■■     " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
}

void printBlackPawn() {
	cout << "             " << endl;
	cout << "     |||     " << endl;
	cout << "    |||||    " << endl;
	cout << "     |||     " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
	cout << "  |||||||||  " << endl;
}

void printBlackKnight() {
	cout << "             " << endl;
	cout << "     |||     " << endl;
	cout << "  |||||||    " << endl;
	cout << "  |||||||    " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
	cout << "  |||||||||  " << endl;
}

void printBlackBishop() {
	cout << "     ||      " << endl;
	cout << "    ||  |   " << endl;
	cout << "    |||||    " << endl;
	cout << "     |||     " << endl;
	cout << "     |||     " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
}

void printBlackRook() {
	cout << "             " << endl;
	cout << "   | | | |   " << endl;
	cout << "   |||||||   " << endl;
	cout << "    |||||    " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
	cout << "  |||||||||  " << endl;
}

void printBlackQueen() {
	cout << "    | | |    " << endl;
	cout << "    |||||    " << endl;
	cout << "     |||     " << endl;
	cout << "     |||     " << endl;
	cout << "     |||     " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
}

void printBlackKing() {
	cout << "      |      " << endl;
	cout << "   |||||||    " << endl;
	cout << "    |||||      " << endl;
	cout << "     |||     " << endl;
	cout << "     |||     " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
}