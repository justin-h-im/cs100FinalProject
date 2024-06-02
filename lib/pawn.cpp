#include "../include/pawn.h"
#include "../include/promotion.h"
#include <cmath> 

bool Pawn::move(int x1, int y1, int x2, int y2) {
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
        return false;
    }

    int direction = (getColor() == Color::WHITE) ? 1 : -1;

    Piece* target = board->getPiece(x2, y2);

    if (x1 == x2 && (y2 - y1) == direction && target == nullptr) {
        if (y2 == (getColor() == Color::WHITE ? 7 : 0)) {
            Piece* tempThis = this;
            Promotion::promote(tempThis, *board);
        }
        this->x = x2;
        this->y = y2;
        return true;
    }

    if (x1 == x2 && (y2 - y1) == 2 * direction && y1 == (getColor() == Color::WHITE ? 1 : 6) && board->getPiece(y1 + direction, x1) == nullptr && target == nullptr) {
        this->x = x2;
        this->y = y2;
        return true;
    }

    if (abs(x2 - x1) == 1 && (y2 - y1) == direction && target != nullptr && target->getColor() != getColor()) {
        if (y2 == (getColor() == Color::WHITE ? 7 : 0)) {
            Piece* tempThis = this;
            Promotion::promote(tempThis, *board);
        }
        this->x = x2;
        this->y = y2;
        return true;
    }

    return false;
}
