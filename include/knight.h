#pragma once

#include "../include/piece.h"

class Knight : public Piece {
public:
    Knight(Color color, int x, int y) 
        : Piece(color, x, y, PieceType::Knight, 25, 15, 70) {}

    bool move(int x1, int y1, int x2, int y2, const Board& board) override;
};


