#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color color, int x, int y) : Piece(color, x, y, PieceType::Pawn) {}

    bool move(int newX, int newY) override {
        return true; // Placeholder return
    }
};

#endif