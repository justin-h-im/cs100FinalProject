#include "../include/Game.hpp"

Game::Game() {}

Color Game::getTurn() {
	return turn;
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