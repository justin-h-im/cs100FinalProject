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
    // Set up black pieces
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

    // Set up white pieces
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

// returns -1 if a player attempts an invalid move, returns 1 if a piece initiates combat, returns 0 if a piece just moves
int Board::verifyMove(int oldY, int oldX, int newY, int newX) {
    if (!verifyPieceToMove(oldY, oldX)) {
        cout << "Flag A\n";
        game->updateTurn();
        return -1;
    }

    Piece* curr = square[oldY][oldX];

	cout << "moving from " << curr->getPieceTypeString(curr->getType()) <<  curr->getColorString(curr->getColor()) <<curr->getX() << ", " << curr->getY() << endl;

    if (!curr->move(oldY, oldX, newY, newX)) {
        cout << "Flag B\n";
        return -1; 
    }

    Color currentTurn = game->getTurn();
    if (curr == nullptr) { 
        cout << "Flag C\n";
        game->updateTurn();
		updateBoard(oldY, oldX, newY, newX);
        return 0;
    }
    else if (currentTurn == Color::WHITE && curr->getColor() == Color::BLACK || currentTurn == Color::BLACK && curr->getColor() == Color::WHITE) { 
        return 1;
    }
    else {
        cout << "Flag D\n";
        game->updateTurn();
        return -1;
    }
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