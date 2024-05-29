#include "../include/pawn.h"

#include <cmath> 

bool Pawn::move(int x1, int y1, int x2, int y2, const Board& board) 
// change x1 and y1 and x2 and y2 after
{
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) 
    {
        return false;
    }
    // Check if the destination is out of bounds or if there is no actual movement

    int direction = (getColor() == Color::WHITE) ? 1 : -1;
    // Set the direction based on pawn color, WHITE = 1(moves up), BLACK -1(moves down)

    Piece* target = board.getPiece(x2, y2);

    if (x1 == x2 && (y2 - y1) == direction && target == nullptr) 
    {
        if (y2 == (getColor() == Color::WHITE ? 7 : 0)) 
        {
            promoteToQueen(x2, y2);
        }

        return true;
    }
    // Normal move forward by one square

    if (x1 == x2 && (y2 - y1) == 2 * direction && y1 == (getColor() == Color::WHITE ? 1 : 6) && board.getPiece(y1 + direction, x1) == nullptr && target == nullptr) 
    {
        return true;
    }
    // Initial move from starting position by two squares

    if (abs(x2 - x1) == 1 && (y2 - y1) == direction && target != nullptr && target->getColor() != getColor()) 
    {
        if (y2 == (getColor() == Color::WHITE ? 7 : 0)) 
        {
            promoteToQueen(x2, y2);
        }

        return true;
    }
    // Capture move in diagonal direction

    return false;
}

void Pawn::promoteToQueen(int x, int y) 
{
    // delete board[y][x];
    // board[y][x] = new Queen(getColor(), x, y); // Assuming Queen constructor is defined.
    return;
}