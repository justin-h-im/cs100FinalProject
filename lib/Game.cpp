#include "Piece.h"
#include "Board.h"
#include "Game.h"

Game() {}

Color Game::getTurn() const {
	return turn;
}

void Game::updateTurn() {
	if (turn == Color::WHITE) { turn = BLACK; }
	else { turn = WHITE; }
}

bool Game::whiteWin() {
	return (blackKing->getHp() == 0);
}

bool Game::blackWin() {
	return (whiteKing->getHp() == 0);
}

void Game::setWhiteKing(Piece* piece) {
	whiteKing = piece;
}

void Game::setBlackKing(Piece* piece) {
	blackKing = piece;
}