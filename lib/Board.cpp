#include "../include/Board.hpp"

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

// updates where a piece is on the board
void Board::updateBoard(int oldX, int oldY, int newX, int newY) {
	square[newX][newY] = square[oldX][oldY];
	square[oldX][oldY] = nullptr;
}

// checks if the player can move the piece at the coordinates
bool Board::verifyPieceToMove(int x, int y) const {
	Piece* piece = square[x][y];
	if (piece->getColor() != game.getTurn()) { return false; }
	return piece == nullptr;
}

// returns -1 if the move is not possible, return 0 if space is empty, return 1 if combat scenario should be entered
int Board::verifyMove(int x, int y) const {
	Piece* piece = square[x][y];
	if (piece == nullptr) { return 0; }
	else if (game.getTurn() == Color::WHITE && piece->getColor() == Color::BLACK || game.getTurn() == Color::BLACK && piece->getColor() == Color::WHITE) { return 1; }
	return -1;
}

// returns a pointer to a piece
const Piece* Board::getPiece(int x, int y) const {
	return square[x][y];
}

