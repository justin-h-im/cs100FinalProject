#pragma once

#include "../include/piece.h"
#include "../include/Board.h"
#include "../include/king.h"

#include <vector>

class Rook : public Piece {
public:
    Rook(Color color, int x, int y) 
        : Piece(color, x, y, PieceType::Rook, 40, 20, 75), hasMoved(false) {}

    bool move(int x1, int y1, int x2, int y2, const Board& board) override;
    bool canCastle(const King& king, int rookX, int rookY, int kingX, int kingY, const Board& board) const;
    bool isSquareUnderAttack(int x, int y, Color color, const Board& board) const;

    bool hasMoved; 
};

