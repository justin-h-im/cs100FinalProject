#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

#include <vector>

using namespace std;

class Pawn : public Piece {
public:
    
    Pawn(Color color, int x, int y) : Piece(color, x, y, PieceType::Pawn) {}

    bool isInBounds(int x, int y);
    bool move(int x1, int y1, int x2, int y2, const Board& board) override;
    void promoteToQueen(int x, int y);

};

#endif 
