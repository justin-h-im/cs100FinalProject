#include "../include/bishop.h"
#include <cmath>

bool Bishop::move(int x1, int y1, int x2, int y2) {
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
        return false;
    }

    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);

    // Bishops move diagonally, so absolute difference between x and y coordinates must be equal
    if (dx != dy) {
        return false;
    }

    int xStep = (x2 > x1) ? 1 : -1;
    int yStep = (y2 > y1) ? 1 : -1;

    int x = x1 + xStep;
    int y = y1 + yStep;

    // Check if all squares between start and end are empty
    while (x != x2 && y != y2) {
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
        return true;
    }

    return false;
}
