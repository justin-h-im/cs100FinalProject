#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
public:
    King(Color color, int x, int y) : Piece(color, x, y, PieceType::King), hasMoved(false) {}

    bool move(int x1, int y1, int x2, int y2, const Board& board) override;
    bool isMoveValid(int x1, int y1, int x2, int y2);
    bool hasMoved; // Track if the King has moved
};

#endif // KING_H
