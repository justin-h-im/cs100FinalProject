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

void Board::updateBoard(int oldX, int oldY, int newX, int newY) {
	square[newX][newY] = square[oldX][oldY];
	square[oldX][oldY] = nullptr;
}

// check if piece 
bool Board::verifyPieceToMove(int x, int y) {
	Piece* curr = square[x][y];
	if (curr->getColor() != game.getTurn()) { return false; }
	return curr == nullptr;
}

// returns -1 if the 
int Board::verifyMove(int x, int y) {
	Piece* curr = square[x][y];
	if (curr == nullptr) { return 0; }
	else if (turn == WHITE && curr->getColor() == BLACK || turn == BLACK && curr->getColor() == WHITE) { return 1; }
	return -1;
}

// returns a pointer to a piece
Piece* Board::getStatus(int x, int y) {
	return square[x][y];
}

