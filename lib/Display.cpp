#include "../include/Display.h"
#include <iostream>
#include <iomanip>

using namespace std;

Display::Display(Board* b) {
	board = b;
}

void Display::displayBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Piece* curr = board->getPiece(i, j);
			cout << "|";
			if (curr != nullptr) {
				if (curr->getColor() == Color::WHITE) {
					switch (curr->getType()) {
						case PieceType::King: 
						{
							cout << " ♚ ";
							break;
						}
						case PieceType::Queen:
						{
							cout << " ♛ ";
							break;
						}
						case PieceType::Pawn:
						{
							cout << " ♟ ";
							break;
						}
						case PieceType::Knight:
						{
							cout << " ♞ ";
							break;
						}
						case PieceType::Bishop:
						{
							cout << " ♝ ";
							break;
						}
						case PieceType::Rook:
						{
							cout << " ♜ ";
							break;
						}
					}
				}
				else {
					switch (curr->getType()) {
						case PieceType::King: 
						{
							cout << " ♔ ";
							break;
						}
						case PieceType::Queen:
						{
							cout << " ♕ ";
							break;
						}
						case PieceType::Pawn:
						{
							cout << " ♙ ";
							break;
						}
						case PieceType::Knight:
						{
							cout << " ♘ ";
							break;
						}
						case PieceType::Bishop:
						{
							cout << " ♗ ";
							break;
						}
						case PieceType::Rook:
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
	if (attacker->getColor() == Color::WHITE) {
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
		case PieceType::Pawn:
		{
			printWhitePawn();
			break;
		}
		case PieceType::Knight:
		{
			printWhiteKnight();
			break;
		}
		case PieceType::Bishop:
		{
			printWhiteBishop();
			break;
		}
		case PieceType::Rook:
		{
			printWhiteRook();
			break;
		}
		case PieceType::Queen:
		{
			printWhiteQueen();
			break;
		}
		case PieceType::King:
		{
			printWhiteKing();
			break;
		}
	}
}

void Display::displayBlackPiece(Piece* piece) {
	switch(piece->getType()) {
		case PieceType::Pawn:
		{
			printBlackPawn();
			break;
		}
		case PieceType::Knight:
		{
			printBlackKnight();
			break;
		}
		case PieceType::Bishop:
		{
			printBlackBishop();
			break;
		}
		case PieceType::Rook:
		{
			printBlackRook();
			break;
		}
		case PieceType::Queen:
		{
			printBlackQueen();
			break;
		}
		case PieceType::King:
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