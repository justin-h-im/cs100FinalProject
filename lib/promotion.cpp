#include "../include/promotion.h"
#include "../include/queen.h"
#include "../include/rook.h"
#include "../include/bishop.h"
#include "../include/knight.h"
#include <cstdlib>  // For random functions
#include <ctime>    // For seeding random number generator


void Promotion::promote(Piece*& pawn, Board& board) {
    srand(static_cast<unsigned int>(time(NULL))); // Seed the random number generator


    // Define possible promotions, including remaining a pawn
    std::vector<PieceType> promotions = {PieceType::Queen, PieceType::Rook, PieceType::Bishop, PieceType::Knight, PieceType::Pawn};


    // Randomly select a promotion
    int choice = rand() % promotions.size();


    int x = pawn->getX();
    int y = pawn->getY();
    Color color = pawn->getColor();


    // Remove the old pawn and replace it with the new piece if not remaining a pawn
    if (promotions[choice] != PieceType::Pawn) {
        delete pawn;  // Delete the existing pawn
        pawn = nullptr;  // Nullify the pointer after deleting


        switch (promotions[choice]) {
            case PieceType::Queen:
                pawn = new Queen(color, x, y);
                break;
            case PieceType::Rook:
                pawn = new Rook(color, x, y);
                break;
            case PieceType::Bishop:
                pawn = new Bishop(color, x, y);
                break;
            case PieceType::Knight:
                pawn = new Knight(color, x, y);
                break;
            default:
                break;
        }


        // Place the new piece on the board
        board.placePiece(x, y, pawn);
    }
}
