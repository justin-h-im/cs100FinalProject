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
	square[0][0] = new Rook(Color::BLACK, 0, 0, this);
	square[0][1] = new Knight(Color::BLACK, 0, 1, this);
	square[0][2] = new Bishop(Color::BLACK, 0, 2, this);
	square[0][3] = new Queen(Color::BLACK, 0, 3, this);
	square[0][4] = new King(Color::BLACK, 0, 4, this);
	square[0][5] = new Bishop(Color::BLACK, 0, 5, this);
	square[0][6] = new Knight(Color::BLACK, 0, 6, this);
	square[0][7] = new Rook(Color::BLACK, 0, 7, this);
	for (int i = 0; i < 8; i++) {
		square[1][i] = new Pawn(Color::BLACK, 1, i, this);
	}

	// set up white pieces
	square[7][0] = new Rook(Color::WHITE, 7, 0, this);
	square[7][1] = new Knight(Color::WHITE, 7, 1, this);
	square[7][2] = new Bishop(Color::WHITE, 7, 2, this);
	square[7][3] = new Queen(Color::WHITE, 7, 3, this);
	square[7][4] = new King(Color::WHITE, 7, 4, this);
	square[7][5] = new Bishop(Color::WHITE, 7, 5, this);
	square[7][6] = new Knight(Color::WHITE, 7, 6, this);
	square[7][7] = new Rook(Color::WHITE, 7, 7, this);
	for (int i = 0; i < 8; i++) {
		square[6][i] = new Pawn(Color::WHITE, 6, i, this);
	}
}

Board::~Board() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			delete square[i][j];
		}
	}
}

void Board::updateBoard(int oldY, int oldX, int newY, int newX) {
	square[newY][newX] = square[oldY][oldX];
	square[oldY][oldX] = nullptr;
}

void Board::setGame(Game* game) {
	this->game = game;
}

// Correcting verifyPieceToMove
bool Board::verifyPieceToMove(int y, int x) const {
	Piece* curr = square[y][x];
	if (curr == nullptr) { return false; }
	return curr->getColor() == game->getTurn();
}

// returns -1 if a player attempts an invalid move, returns 1 if a piece initiates combat, returns 0 if a piece just moves
int Board::verifyMove(int oldY, int oldX, int newY, int newX) const {
	if (!verifyPieceToMove(oldY, oldX)) {
		game->updateTurn();
		return -1;
	}

	Piece* curr = square[oldY][oldX];
	if (!curr->move(oldX, oldY, newX, newY)) {
		cout << "Your troop cannot reach that location.\n";
		game->updateTurn();
		return -1; 
	}

	Color currentTurn = game->getTurn();
	if (curr == nullptr) { 
		game->updateTurn();
		game->updateBoard(oldY, oldX, newY, newX);
		return 0;
	}
	else if (currentTurn == Color::WHITE && curr->getColor() == Color::BLACK || currentTurn == Color::BLACK && curr->getColor() == Color::WHITE) { 
		return 1;
	}
	else {
		game->updateTurn();
		return -1;
	}
}

// Correcting getPiece
Piece* Board::getPiece(int y, int x) const {
	return square[y][x];
}

// allows a piece to be added to the board (for pawn promotion)
void Board::placePiece(int y, int x, Piece* piece) {
	if (square[y][x] == nullptr) {
		square[y][x] = piece;
	}
}