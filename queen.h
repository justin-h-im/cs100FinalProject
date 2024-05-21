#pragma once

#include "piece.h"

class Queen : public Piece {
public:
    Queen(Color color, int x, int y) : Piece(color, x, y, PieceType::Queen) {}

    bool move(int x1, int y1, int x2, int y2) override;
};

