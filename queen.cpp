#include "queen.h"

/*
  0 1 2 3 4 5 6 7
0 R N B Q K B N R 0
1 P P P P P P P P 1
2 - - - - - - - - 2
3 - - - - - - - - 3
4 - - - - - - - - 4
5 - - - - - - - - 5
6 p p p p p p p p 6
7 r n b q k b n r 7
  0 1 2 3 4 5 6 7
*/

extern Piece* board[8][8];

// [start coordinate] (x1, y1) 
//  move to 
// [destination coordinate] (x2, y2)
bool Queen::move(int x1, int y1, int x2, int y2) {
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
        return false;
    }

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // queen movement: rook AND bishop
    if (dx != dy && x1 != x2 && y1 != y2) {
        return false;
    }

    int xStep = 0;
    int yStep = 0;
    

    /* determine direction of movement */
    // vertical movement (if horizontal coordinate is same)
    if (x1 == x2) { 
        yStep = (y2 > y1) ? 1 : -1;
    } 
    
    // horizontal movement (if vertical coordinate is same)
    else if (y1 == y2) { 
        xStep = (x2 > x1) ? 1 : -1;
    } 
    
    // diagonal movement (else)
    else { 
        xStep = (x2 > x1) ? 1 : -1;
        yStep = (y2 > y1) ? 1 : -1;
    }
    
    int x = x1 + xStep;
    int y = y1 + yStep;

    // check if all squares between the start and end are empty
    while (x != x2 || y != y2) {
        if (board[y][x] != nullptr) {
            return false;
        }
        x += xStep;
        y += yStep;
    }

    Piece* target = board[y2][x2];
    // check if destination is either empty or occupied by an opponent's piece
    if (target == nullptr || target->getColor() != this->getColor()) {
        // move or capture
        if (target != nullptr) {
            // capture the piece
            // replace with INITIATE FIGHT later
            delete target;
        }
        board[y2][x2] = this; // destination coordinate now holds the new piece
        board[y1][x1] = nullptr; // start coordinate is now empty

        // update own coordinates
        this->x = x2;
        this->y = y2;

        return true; // has moved
    }

    return false;
}
