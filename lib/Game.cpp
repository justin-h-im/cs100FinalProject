#include "../include/Game.hpp"

Game::Game() {}

Color Game::getTurn() {
	return turn;
}

void Game::updateTurn() {
	if (turn == Color::WHITE) { turn = Color::BLACK; }
	else { turn = Color::WHITE; }
}

bool Game::whiteWin() {
	return whiteKing->getHP() == 0;
}

bool Game::blackWin() {
	return blackKing->getHP() == 0;
}

void Game::setWhiteKing(Piece* wk) {
	whiteKing = wk;
}

void Game::setBlackKing(Piece* bk) {
	blackKing == bk;
}