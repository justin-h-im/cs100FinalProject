#include "../include/Board.h"

#include <iostream>

using std::cout;
using std::endl;

// Constructor sets up the Board
Board::Board() {
	// set up black pieces
	square[0][0] = new Rook(Color::BLACK, 0, 0);
	square[0][1] = new Knight(Color::BLACK, 0, 1);
	square[0][2] = new Bishop(Color::BLACK, 0, 2);
	square[0][3] = new Queen(Color::BLACK, 0, 3);
	square[0][4] = new King(Color::BLACK, 0, 4);
	square[0][5] = new Bishop(Color::BLACK, 0, 5);
	square[0][6] = new Knight(Color::BLACK, 0, 6);
	square[0][7] = new Rook(Color::BLACK, 0, 7);
	for (int i = 0; i < 8; i++) {
		square[1][i] = new Pawn(Color::BLACK, 1, i);
	}

	// set up white pieces
	square[7][0] = new Rook(Color::WHITE, 7, 0);
	square[7][1] = new Knight(Color::WHITE, 7, 1);
	square[7][2] = new Bishop(Color::WHITE, 7, 2);
	square[6][3] = new Queen(Color::WHITE, 7, 3);
	square[6][4] = new King(Color::WHITE, 7, 4);
	square[0][5] = new Bishop(Color::WHITE, 7, 5);
	square[0][6] = new Knight(Color::WHITE, 7, 6);
	square[0][7] = new Rook(Color::WHITE, 7, 7);
	for (int i = 0; i < 8; i++) {
		square[7][i] = new Pawn(Color::WHITE, 6, i);
	}
}

void Board::updateBoard(int oldX, int oldY, int newX, int newY) {
	square[newX][newY] = square[oldX][oldY];
	square[oldX][oldY] = nullptr;
}

// check if piece 
bool Board::verifyPieceToMove(int x, int y) const {
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
const Piece* Board::getPiece(int x, int y) const {
	return square[x][y];
}
