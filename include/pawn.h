#pragma once

#include "../include/piece.h"
#include "../include/Board.h"

#include <vector>

using namespace std;

class Pawn : public Piece {
public:
    
    Pawn(Color color, int x, int y) : Piece(color, x, y, PieceType::Pawn) {}
    
    bool move(int x1, int y1, int x2, int y2, const Board& board) override;
    void promoteToQueen(int x, int y);

};
