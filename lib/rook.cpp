#include "../include/rook.h"
#include "../include/king.h"

#include <cmath>
#include <algorithm> 

using namespace std;

bool Rook::move(int x1, int y1, int x2, int y2) {
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
        return false;
    }

    // Rooks move in straight lines, either horizontally or vertically
    if (x1 != x2 && y1 != y2) {
        // Check for castle move
        if (this->getColor() == Color::WHITE && x1 == 0 && y1 == 0 && x2 == 2 && y2 == 0) {
            return canCastle(*(this->king), 0, 0, 4, 0, *board);
        }
        if (this->getColor() == Color::WHITE && x1 == 7 && y1 == 0 && x2 == 6 && y2 == 0) {
            return canCastle(*(this->king), 0, 0, 4, 0, *board);
        }
        if (this->getColor() == Color::BLACK && x1 == 0 && y1 == 7 && x2 == 2 && y2 == 7) {
            return canCastle(*(this->king), 0, 0, 4, 0, *board);
        }
        if (this->getColor() == Color::BLACK && x1 == 7 && y1 == 7 && x2 == 6 && y2 == 7) {
            return canCastle(*(this->king), 0, 0, 4, 0, *board);
        }
        return false;
    }

    int xStep = (x2 > x1) ? 1 : (x2 < x1) ? -1 : 0;
    int yStep = (y2 > y1) ? 1 : (y2 < y1) ? -1 : 0;

    int x = x1 + xStep;
    int y = y1 + yStep;

    // Check if all squares between start and end are empty
    while (x != x2 || y != y2) {
        if (board->getPiece(x, y) != nullptr) {
            return false;
        }
        x += xStep;
        y += yStep;
    }

    Piece* target = board->getPiece(x2, y2);
    if (target == nullptr || target->getColor() != this->getColor()) {
        this->x = x2;
        this->y = y2;
        hasMoved = true;
        return true;
    }

    return false;
}

bool Rook::canCastle(const King& king, int rookX, int rookY, int kingX, int kingY, const Board& board) const {
    if (hasMoved || king.hasMoved) {
        return false;
    }

    if (kingY != rookY) {
        return false;
    }

    if ((kingX != 4) || (rookX != 0 && rookX != 7)) {
        return false;
    }

    int startX = min(kingX, rookX) + 1;
    int endX = max(kingX, rookX);

    for (int i = startX; i < endX; ++i) {
        if (board.getPiece(i, kingY) != nullptr) {
            return false;
        }
    }

    for (int i = kingX; i != (rookX > kingX ? kingX + 2 : kingX - 2); i += (rookX > kingX ? 1 : -1)) {
        if (isSquareUnderAttack(i, kingY, king.getColor(), board)) {
            return false;
        }
    }

    return true;
}

bool Rook::isSquareUnderAttack(int x, int y, Color color, const Board& board) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = board.getPiece(i, j);
            if (piece != nullptr && piece->getColor() != color) {
                if (piece->move(piece->getX(), piece->getY(), x, y)) {
                    return true;
                }
            }
        }
    }
    return false;
}
