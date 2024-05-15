#include "../include/Board.hpp"

#include <iostream>

using std::cout;
using std::endl;

// Constructor sets up the Board
Board::Board() {
	// set up black pieces
	square[0][0] = new Piece(BLACK, 0, 0, ROOK);
	square[0][1] = new Piece(BLACK, 0, 1, KNIGHT);
	square[0][2] = new Piece(BLACK, 0, 2, BISHOP);
	square[0][3] = new Piece(BLACK, 0, 3, QUEEN);
	square[0][4] = new Piece(BLACK, 0, 4, KING);
	square[0][5] = new Piece(BLACK, 0, 5, BISHOP);
	square[0][6] = new Piece(BLACK, 0, 6, KNIGHT);
	square[0][7] = new Piece(BLACK, 0, 7, ROOK);
	for (int i = 0; i < 8; i++) {
		square[1][i] = new Piece (BLACK, 1, i, PAWN);
	}

	// set up white pieces
	square[7][0] = new Piece(WHITE, 6, 0, ROOK);
	square[7][1] = new Piece(WHITE, 6, 1, KNIGHT);
	square[7][2] = new Piece(WHITE, 6, 2, BISHOP);
	square[6][3] = new Piece(WHITE, 6, 3, QUEEN);
	square[6][4] = new Piece(WHITE, 6, 4, KING);
	square[0][5] = new Piece(WHITE, 6, 5, BISHOP);
	square[0][6] = new Piece(WHITE, 6, 6, KNIGHT);
	square[0][7] = new Piece(WHITE, 6, 7, ROOK);
	for (int i = 0; i < 8; i++) {
		square[7][i] = new Piece (WHITE, 7, i, PAWN);
	}
}

void Board::displayBoard() {
	if (turn == WHITE) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				Piece* curr = square[i][j];
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
	}
	else {
		for (int i = 7; i >= 0; i--) {
			for (int j = 7; j >= 0; j--) {
				Piece* curr = square[i][j];
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
}

void Board::updateBoard(int oldX, int oldY, int newX, int newY) {
	square[newX][newY] = square[oldX][oldY];
	square[oldX][oldY] = nullptr;
}

// check if piece 
bool Board::verifyPieceExists(int x, int y) {
	return square[x][y] == nullptr;
}

// returns false if the piece has no possible moves
bool Board::verifyCoordinates(int x, int y) {
	Piece* curr = square[x][y];
	if (curr == nullptr || turn == WHITE && curr->getColor() == BLACk || turn == BLACK && curr->getColor() == WHITE) { return true; }
	return false;
}
