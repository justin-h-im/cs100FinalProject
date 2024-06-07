#include "../include/queen.h"
#include <cmath>

// [start coordinate] (x1, y1) 
//  move to 
// [destination coordinate] (x2, y2)
bool Queen::move(int x1, int y1, int x2, int y2) {
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
        return false;
    }

    // find absolute value difference of start and end x and y coordinates
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);

    // queen movement: combination of rook AND bishop
    if (dx != dy && x1 != x2 && y1 != y2) {
        return false;
    }

    int xStep = 0;
    int yStep = 0;
    
    /* determine direction of movement (calculate step movement) */
    // vertical movement (if horizontal coordinate is same)
    if (y1 == y2) { 
        xStep = (x2 > x1) ? 1 : -1;
    } 
    
    // horizontal movement (if vertical coordinate is same)
    else if (x1 == x2) { 
        yStep = (y2 > y1) ? 1 : -1;
    } 
    
    // diagonal movement (else)
    else { 
        xStep = (x2 > x1) ? 1 : -1; // -
        yStep = (y2 > y1) ? 1 : -1; // +
    }

    // start moving towards destination coordinates
    int x = x1 + xStep;
    int y = y1 + yStep;

    // check if all squares between the start and end are empty
    // (stops right before destination coordinate!)
    while (x != x2 || y != y2) {
        if (board->getPiece(x, y) != nullptr) {
            return false;
        }
        x += xStep;
        y += yStep;
    }

    Piece* target = board->getPiece(x2, y2);
    // check if destination is empty or occupied by an opponent's piece
    if (target == nullptr || target->getColor() != this->getColor()) {
        /* athena does this in board */
        // move or capture
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
