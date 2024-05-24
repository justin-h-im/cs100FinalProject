#include "..]pawn.h"

#include <cmath> 

/*
  0 1 2 3 4 5 6 7
0 R N B Q K B N R 0
1 P P P P P P P P 1
2 - - - - - - - - 2
3 - - - - - - - - 3
4 - - - - - - - - 4
5 - - - - - - - - 5
6 p p p p p p p p 6
7 r n b q k b n r 7
  0 1 2 3 4 5 6 7
*/

bool Pawn::isInBounds(int x, int y) 
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool Pawn::move(int x1, int y1, int x2, int y2, const Board& board) 
{
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) 
    {
        return false;
    }
    // Check if the destination is out of bounds or if there is no actual movement

    int direction = (getColor() == Color::WHITE) ? 1 : -1;
    // Set the direction based on pawn color, WHITE = 1(moves up), BLACK -1(moves down)

    Piece* target = board.getStatus(x2, y2);

    if (x1 == x2 && (y2 - y1) == direction && target == nullptr) 
    {
        if (y2 == (getColor() == Color::WHITE ? 7 : 0)) 
        {
            promoteToQueen(x2, y2);
        }

        return true;
    }
    // Normal move forward by one square

    if (x1 == x2 && (y2 - y1) == 2 * direction && y1 == (getColor() == Color::WHITE ? 1 : 6) && board.getStatus(y1 + direction, x1) == nullptr && target == nullptr) 
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
