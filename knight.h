#pragma once

#include "piece.h"

class Knight : public Piece {
public:
    Knight(Color color, int x, int y) : Piece(color, x, y, PieceType::Knight) {}

    bool move(int x1, int y1, int x2, int y2) override;
};


