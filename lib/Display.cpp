#include "../include/Display.h"
#include <iostream>
#include <iomanip>

using namespace std;


void Display::displayBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Piece* curr = board.getPiece(i, j);
			cout << "|";
			if (curr != nullptr) {
				if (curr->getColor() == Color::WHITE) {
					switch (curr->getType()) {
						case KING: 
						{
							cout << " ♚ ";
							break;
						}
						case QUEEN:
						{
							cout << " ♛ ";
							break;
						}
						case PAWN:
						{
							cout << " ♟ ";
							break;
						}
						case KNIGHT:
						{
							cout << " ♞ ";
							break;
						}
						case BISHOP:
						{
							cout << " ♝ ";
							break;
						}
						case ROOK:
						{
							cout << " ♜ ";
							break;
						}
					}
				}
				else {
					switch (curr->getType()) {
						case KING: 
						{
							cout << " ♔ ";
							break;
						}
						case QUEEN:
						{
							cout << " ♕ ";
							break;
						}
						case PAWN:
						{
							cout << " ♙ ";
							break;
						}
						case KNIGHT:
						{
							cout << " ♘ ";
							break;
						}
						case BISHOP:
						{
							cout << " ♗ ";
							break;
						}
						case ROOK:
						{
							cout << " ♖ ";
							break;
						}
					}
				}
			}
			else { cout << "   "; }
		}
		cout << "|\n";
		cout << std::setfill('-') << std::setw(40) << endl;
	}
}

void Display::displayCombat(Piece* attacker, Piece* defender) {
	if (attacker->getColor() == WHITE) {
		displayWhitePiece(attacker);
		displayBlackPiece(defender);
	}
	else {
		displayWhitePiece(attacker);
		displayBlackPiece(defender);
	}
}

void Display::displayWhitePiece(Piece* piece) {
	switch(piece->getType()) {
		case PAWN:
		{
			printWhitePawn();
			break;
		}
		case KNIGHT:
		{
			printWhiteKnight();
			break;
		}
		case BISHOP
		{
			printWhiteBishop();
			break;
		}
		case ROOK:
		{
			printWhiteRook();
			break;
		}
		case QUEEN:
		{
			printWhiteQueen();
			break;
		}
		case KING:
		{
			printWhiteKing();
			break;
		}
	}
}

void Display::displayBlackPiece(Piece* piece) {
	switch(piece->getType()) {
		case PAWN:
		{
			printBlackPawn();
			break;
		}
		case KNIGHT:
		{
			printBlackKnight();
			break;
		}
		case BISHOP
		{
			printBlackBishop();
			break;
		}
		case ROOK:
		{
			printBlackRook();
			break;
		}
		case QUEEN:
		{
			printBlackQueen();
			break;
		}
		case KING:
		{
			printBlackKing();
			break;
		}
	}
}

void Display::printWhitePawn() {
	cout << "             " << endl;
	cout << "     ■■■     " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "     ■■■     " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
	cout << "  ■■■■■■■■■  " << endl;
}

void Display::printWhiteKnight() {
	cout << "             " << endl;
	cout << "     ■■■     " << endl;
	cout << "  ■■■■■■■    " << endl;
	cout << "  ■■■■■■■    " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
	cout << "  ■■■■■■■■■  " << endl;
}

void Display::printWhiteBishop() {
	cout << "     ■■      " << endl;
	cout << "    ■■  ■    " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "     ■■■     " << endl;
	cout << "     ■■■     " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
}

void Display::printWhiteRook() {
	cout << "             " << endl;
	cout << "   ■ ■ ■ ■   " << endl;
	cout << "   ■■■■■■■   " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
	cout << "  ■■■■■■■■■  " << endl;
}

void Display::printWhiteQueen() {
	cout << "    ■ ■ ■    " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "     ■■■     " << endl;
	cout << "     ■■■     " << endl;
	cout << "     ■■■     " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
}

void Display::printWhiteKing() {
	cout << "      ■      " << endl;
	cout << "   ■■■■■■■    " << endl;
	cout << "    ■■■■■      " << endl;
	cout << "     ■■■     " << endl;
	cout << "     ■■■     " << endl;
	cout << "    ■■■■■    " << endl;
	cout << "   ■■■■■■■   " << endl;
}

void Display::printBlackPawn() {
	cout << "             " << endl;
	cout << "     |||     " << endl;
	cout << "    |||||    " << endl;
	cout << "     |||     " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
	cout << "  |||||||||  " << endl;
}

void Display::printBlackKnight() {
	cout << "             " << endl;
	cout << "     |||     " << endl;
	cout << "  |||||||    " << endl;
	cout << "  |||||||    " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
	cout << "  |||||||||  " << endl;
}

void Display::printBlackBishop() {
	cout << "     ||      " << endl;
	cout << "    ||  |   " << endl;
	cout << "    |||||    " << endl;
	cout << "     |||     " << endl;
	cout << "     |||     " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
}

void Display::printBlackRook() {
	cout << "             " << endl;
	cout << "   | | | |   " << endl;
	cout << "   |||||||   " << endl;
	cout << "    |||||    " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
	cout << "  |||||||||  " << endl;
}

void Display::printBlackQueen() {
	cout << "    | | |    " << endl;
	cout << "    |||||    " << endl;
	cout << "     |||     " << endl;
	cout << "     |||     " << endl;
	cout << "     |||     " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
}

void Display::printBlackKing() {
	cout << "      |      " << endl;
	cout << "   |||||||    " << endl;
	cout << "    |||||      " << endl;
	cout << "     |||     " << endl;
	cout << "     |||     " << endl;
	cout << "    |||||    " << endl;
	cout << "   |||||||   " << endl;
}