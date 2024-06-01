#ifndef PROMOTION_H
#define PROMOTION_H


#include "../include/piece.h"
#include "../include/Board.h"
#include <vector>


class Promotion {
public:
    Promotion() = default;

    static void promote(Piece*& pawn, Board& board);
    // FYI: By using a reference to a pointer, the function promote is allowed to modify the pointer itself
};


#endif
