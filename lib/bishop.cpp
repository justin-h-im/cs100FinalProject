#include "../include/bishop.h"
#include <cmath>

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

// [start coordinate] (x1, y1) 
//  move to 
// [destination coordinate] (x2, y2)
bool Bishop::move(int x1, int y1, int x2, int y2) {
  if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
      return false;
  }

  int dx = std::abs(x2 - x1);
  int dy = std::abs(y2 - y1);

  // bishops move diagonally, so absolute difference b/n x and y coordinates must be equal
  if (dx != dy) {
      return false;
  }

  /* determine (diagonal) direction of bishop movement */
  // if ( ), then 1 = right \\ else, -1 = left 
  int xStep = (x2 > x1) ? 1 : -1;
  // if ( ), then 1 = up \\ else, -1 = down
  int yStep = (y2 > y1) ? 1 : -1;

  /* move once, towards destination coordinate */
  int x = x1 + xStep;
  int y = y1 + yStep;

  // check if all squares b/n start and end are empty
  // does NOT check the actual destination coordinate (stops right before)
  while (x != x2 && y != y2) {
    // return false if any coordinate b/n start and end is NOT valid 
    // if getPiece at currLocation is NOT nullptr then there's a piece there
    // THEREFORE should return false
    if (board->getPiece(y, x) != nullptr) {
      return false;
    }
    // step towards destination coordinate
    x += xStep;
    y += yStep;
  }

  Piece* target = board->getPiece(x2, y2);
  // if empty OR spot has piece on it
  if (target == nullptr || target->getColor() != this->getColor()) {
    /* athena does this in board */
    // // move or capture
    // if (target != nullptr) {
    //     // capture the piece
    //     // replace with INITIATE FIGHT later
    //     delete target;  
    // }
    // board.setStatus(x2, y2, this); // destination coordinate now holds new piece
    // board.setStatus(x1, y1, nullptr); // start coordinate is now empty

    // update own coordinates
    this->x = x2;
    this->y = y2;

    return true; // has moved
  }

  return false;
}
