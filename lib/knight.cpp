#include "../include/knight.h"
#include <cstdlib>

bool Knight::move(int x1, int y1, int x2, int y2) {
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
        return false;
    }

    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);

    if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) {
        return false;
    }

    Piece* target = board->getPiece(x2, y2);

    if (target == nullptr || target->getColor() != this->getColor()) {
        this->x = x2;
        this->y = y2;
        return true; 
    }

    return false;
}
