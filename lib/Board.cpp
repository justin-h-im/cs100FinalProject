#include "../include/Board.h"
#include "../include/Game.h"
#include "../include/piece.h"
#include "../include/bishop.h"
#include "../include/king.h"
#include "../include/knight.h"
#include "../include/pawn.h"
#include "../include/queen.h"
#include "../include/rook.h"

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
	square[7][3] = new Queen(Color::WHITE, 7, 3);
	square[7][4] = new King(Color::WHITE, 7, 4);
	square[7][5] = new Bishop(Color::WHITE, 7, 5);
	square[7][6] = new Knight(Color::WHITE, 7, 6);
	square[7][7] = new Rook(Color::WHITE, 7, 7);
	for (int i = 0; i < 8; i++) {
		square[6][i] = new Pawn(Color::WHITE, 6, i);
	}
}

void Board::updateBoard(int oldX, int oldY, int newX, int newY) {
	square[newX][newY] = square[oldX][oldY];
	square[oldX][oldY] = nullptr;
}

void Board::setGame(Game* game) {
	this->game = game;
}

// Correcting verifyPieceToMove
bool Board::verifyPieceToMove(int x, int y) const {
    Piece* curr = square[x][y];
    if (curr == nullptr) { return false; }
    return curr->getColor() == game->getTurn();
}

int Board::verifyMove(int x, int y) const {
    Piece* curr = square[x][y];
    if (curr == nullptr) { return 0; }
    Color currentTurn = game->getTurn();
    if (currentTurn == Color::WHITE && curr->getColor() == Color::BLACK || currentTurn == Color::BLACK && curr->getColor() == Color::WHITE) { return 1; }
    return -1;
}

// Correcting getPiece
Piece* Board::getPiece(int x, int y) const {
    return square[x][y];
}

// allows a piece to be added to the board (for pawn promotion)
void Board::placePiece(int x, int y, Piece* piece) {
	if (square[x][y] == nullptr) {
		square[x][y] = piece;
	}
}