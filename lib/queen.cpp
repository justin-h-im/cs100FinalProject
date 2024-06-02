#include "../include/queen.h"
#include <cmath>

bool Queen::move(int x1, int y1, int x2, int y2) {
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
        return false;
    }

    // Find absolute value difference of start and end x and y coordinates
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);

    // Queen movement: combination of rook AND bishop
    if (dx != dy && x1 != x2 && y1 != y2) {
        return false;
    }

    int xStep = 0;
    int yStep = 0;
    
    // Determine direction of movement (calculate step movement)
    // Vertical movement (if horizontal coordinate is same)
    if (x1 == x2) { 
        yStep = (y2 > y1) ? 1 : -1;
    } 
    // Horizontal movement (if vertical coordinate is same)
    else if (y1 == y2) { 
        xStep = (x2 > x1) ? 1 : -1;
    } 
    // Diagonal movement (else)
    else { 
        xStep = (x2 > x1) ? 1 : -1;
        yStep = (y2 > y1) ? 1 : -1;
    }

    // Start moving towards destination coordinates
    int x = x1 + xStep;
    int y = y1 + yStep;

    // Check if all squares between the start and end are empty (stops right before destination coordinate)
    while (x != x2 || y != y2) {
        if (board->getPiece(x, y) != nullptr) {
            return false;
        }
        x += xStep;
        y += yStep;
    }

    Piece* target = board->getPiece(x2, y2);
    // Check if destination is empty or occupied by an opponent's piece
    if (target == nullptr || target->getColor() != this->getColor()) {
        // Update own coordinates
        this->x = x2;
        this->y = y2;
        return true; // Has moved
    }

    return false;
}
