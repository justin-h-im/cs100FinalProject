#ifndef PIECE_H
#define PIECE_H

#include "../include/Board.h"
#include "../include/enums.h"

class Board; // Forward declaration

class Piece {
protected:
    Color color;      
    PieceType type;
    int x;
    int y;
    int hp; 
    Board* board; // Add Board attribute

public:
    Piece(Color color, int x, int y, PieceType type, Board* board) : color(color), x(x), y(y), type(type), hp(0), board(board) {}
    virtual ~Piece() {}

    bool isInBounds(int x, int y) {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
    
    virtual bool move(int x1, int y1, int x2, int y2) = 0; // Remove Board& board parameter

    Color getColor() const { return color; }
    PieceType getType() const { return type; }
    void getPosition(int& outX, int& outY) const { outX = x; outY = y; }
    int getHp() const { return hp; }
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif
