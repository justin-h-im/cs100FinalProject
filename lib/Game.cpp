#include "../include/Game.hpp"

#include <iostream>

using std::cout;
using std::endl;

// Constructor sets up the game
Game::Game() {
	
}

void Game::displayBoard() {
	if (turn == WHITE) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				Piece curr = *square[i][j];
				switch(curr.getPiece()) {
					cout << "|"
					case(KING):
					{
						if (curr.getColor() == WHITE) { cout << " ♔ ";} 
						else { cout << " ♚ "; }
						break;
					}
					case(QUEEN):
					{
						if (curr.getColor() == WHITE) { cout << " ♕ "; }
						else { cout << " ♛ ";}
						break;
					}
					case(PAWN):
					{
						if (curr.getColor() == WHITE) { cout << " ♙ "; }
						else { cout << "♟"; }
						break;
					}
					case(KNIGHT):
					{
						if (curr.getColor() == WHITE) { cout << " ♘ "; }
						else { cout << " ♞ "; }
						break;
					}
					case(BISHOP):
					{
						if (curr.getColor() == WHITE) { cout << " ♗ "; }
						else { cout << " ♝ "; }
						break;
					}
					case(ROOK):
					{
						if (curr.getColor() == WHITE) { cout << " ♖ "; }
						else { cout << " ♜ ";}
						break;
					}
					cout << "|\n";
					cout << std::setfill('-') << std::setw(40) << endl;
				}
			}
		}
	}
	else {
		for (int i = 7; i >= 0; i--) {
			for (int j = 7; j >= 0; j--) {
				Piece curr = *square[i][j];
				switch(curr.getPiece()) {
					cout << "|"
					case(KING):
					{
						if (curr.getColor() == WHITE) { cout << " ♔ ";} 
						else { cout << " ♚ "; }
						break;
					}
					case(QUEEN):
					{
						if (curr.getColor() == WHITE) { cout << " ♕ "; }
						else { cout << " ♛ ";}
						break;
					}
					case(PAWN):
					{
						if (curr.getColor() == WHITE) { cout << " ♙ "; }
						else { cout << "♟"; }
						break;
					}
					case(KNIGHT):
					{
						if (curr.getColor() == WHITE) { cout << " ♘ "; }
						else { cout << " ♞ "; }
						break;
					}
					case(BISHOP):
					{
						if (curr.getColor() == WHITE) { cout << " ♗ "; }
						else { cout << " ♝ "; }
						break;
					}
					case(ROOK):
					{
						if (curr.getColor() == WHITE) { cout << " ♖ "; }
						else { cout << " ♜ ";}
						break;
					}
					cout << "|\n";
					cout << std::setfill('-') << std::setw(40) << endl;
				}
			}
		}
	}
}

