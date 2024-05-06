#ifndef PIECE_H
#define PIECE_H

enum class PieceType {
    Pawn, Knight, Bishop, Rook, Queen, King
};

enum class Color {
    White, Black
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

    virtual bool move(int newX, int newY) = 0;
    Color getColor() const { return color; }
    PieceType getType() const { return type; }
    void getPosition(int& outX, int& outY) const { outX = x; outY = y; }
};

#endif