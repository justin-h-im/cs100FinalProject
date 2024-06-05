#include "../include/rook.h"

#include <cmath>
#include <algorithm> 

using namespace std;

bool Rook::move(int x1, int y1, int x2, int y2) 
{

    if (x1 == x2 || y1 == y2)
    {

        int startX = min(x1, x2) + 1;
        int endX = max(x1, x2);
        int startY = min(y1, y2) + 1;
        int endY = max(y1, y2);

        if (x1 == x2) 
        {
            for (int i = startY; i < endY; ++i)
            {
                if (board->getPiece(x1, i) != nullptr) 
                {
                    return false;
                }
            }
        } 
        else 
        {
            for (int i = startX; i < endX; ++i) 
            {
                if (board->getPiece(i, y1) != nullptr) 
                {
                    return false;
                }
            }
        }

        return true;
    }

    return false;
}

bool Rook::canCastle(const King& king, int rookX, int rookY, int kingX, int kingY) const
 {

    if (hasMoved || king.hasMoved) 
    {
        return false;
    }

    if (kingY != rookY) 
    {
        return false;
    }

    if ((kingX != 4) || (rookX != 0 && rookX != 7))
    {
        return false;
    }

    int startX = min(kingX, rookX) + 1;
    int endX = max(kingX, rookX);

    for (int i = startX; i < endX; ++i)
    {
        if (board->getPiece(i, kingY) != nullptr)
        {
            return false;
        }
    }

    for (int i = kingX; i != (rookX > kingX ? kingX + 2 : kingX - 2); i += (rookX > kingX ? 1 : -1)) 
    {
        if (isSquareUnderAttack(i, kingY, king.getColor())) 
        {
            return false;
        }
    }

    return true;
}

bool Rook::isSquareUnderAttack(int x, int y, Color color) const 
{
    // Iterate over all pieces on the board
    for (int i = 0; i < 8; ++i) 
    {
        for (int j = 0; j < 8; ++j) 
        {
            Piece* piece = board->getPiece(i, j);

            if (piece != nullptr && piece->getColor() != color) 
            {
                if (piece->move(piece->getX(), piece->getY(), x, y))
                {
                    return true;
                }
            }
        }
    }

    return false;
}
