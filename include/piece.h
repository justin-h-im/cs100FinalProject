#ifndef PIECE_H
#define PIECE_H

#include "../include/Board.h"

class Board;

enum class PieceType {
    Pawn, Knight, Bishop, Rook, Queen, King
};

enum class Color {
    WHITE, BLACK
};

class Piece {
protected:
    Color color;      
    PieceType type;
    int x;
    int y;
    int hp; 

public:
    Piece(Color color, int x, int y, PieceType type) : color(color), x(x), y(y), type(type), hp(0) {}
    virtual ~Piece() {}

    bool isInBounds(int x, int y){
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
    
    virtual bool move(int x1, int y1, int x2, int y2, const Board& board) = 0;   

    Color getColor() const { return color; }
    PieceType getType() const { return type; }
    void getPosition(int& outX, int& outY) const { outX = x; outY = y; }
    int getHp() const { return hp; }
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif