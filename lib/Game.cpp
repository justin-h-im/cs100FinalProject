#include "../include/Game.h"

Game::Game() {}

Color Game::getTurn() const {
	return turn;
}

void Game::updateTurn() {
	if (turn == Color::WHITE) { turn = Color::BLACK; }
	else { turn = Color::WHITE; }
}

bool Game::whiteWin() {
	return (blackKing == nullptr);
}

bool Game::blackWin() {
	return (whiteKing == nullptr);
}

void Game::setWhiteKing(Piece* piece) {
	whiteKing = piece;
}

void Game::setBlackKing(Piece* piece) {
	blackKing = piece;
}