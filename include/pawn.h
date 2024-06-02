#ifndef PAWN_H
#define PAWN_H

#include "../include/piece.h"
#include "../include/Board.h"
#include <vector>

using namespace std;

class Pawn : public Piece {
public:
    Pawn(Color color, int x, int y, Board* board) : Piece(color, x, y, PieceType::Pawn, board) {}

    bool move(int x1, int y1, int x2, int y2) override;
};

#endif
