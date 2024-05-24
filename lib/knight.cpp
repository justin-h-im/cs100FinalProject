#include "knight.h"
#include <cmath>

// [start coordinate] (x1, y1) 
//  move to 
// [destination coordinate] (x2, y2)
bool Knight::move(int x1, int y1, int x2, int y2, const Board& board) {
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
        return false;
    }

    // calculate difference in coordinates
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);

    // check for valid L-shaped moves (2 by 1 or 1 by 2)
    if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) {
        return false;
    }

    Piece* target = board.getStatus(x2, y2);
    // check if destination is empty or occupied by opponent's piece
    if (target == nullptr || target->getColor() != this->getColor()) {
        /* athena does this in board */
        // // move or capture
        // if (target != nullptr) {
        //     // capture the piece
        //     // replace with INITIATE FIGHT later
        //     delete target;
        // }
        // board.setStatus(x2, y2, this); // destination coordinate now holds the new piece
        // board.setStatus(x1, y1, nullptr); // start coordinate is now empty

        // update own coordinates
        this->x = x2;
        this->y = y2;

        return true; // has moved
    }

    return false;
}
