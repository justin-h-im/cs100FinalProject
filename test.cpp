#include "gtest/gtest.h"
#include "../include/ui.h"
#include "../include/Board.h"
#include "../include/Display.h"
#include "../include/piece.h"
#include "../include/pawn.h"
#include "../include/knight.h"
#include "../include/rook.h"
#include "../include/bishop.h"
#include "../include/queen.h"
#include "../include/king.h"

// Test pawn's initial one-step forward movement
TEST(PawnTests, testPawnForwardMovement) {
    Board* testBoard = new Board();  
    Piece* pawn = testBoard->getPiece(6, 0);  

    ASSERT_TRUE(pawn != nullptr && pawn->getType() == PieceType::Pawn);

    // Move one step forward
    EXPECT_TRUE(pawn->move(6, 0, 5, 0));
    testBoard->updateBoard(6, 0, 5, 0);
    EXPECT_EQ(testBoard->getPiece(5, 0), pawn);

    delete testBoard;
}

// Test pawn's initial double-step forward movement
TEST(PawnTests, testPawnDoubleStep) {
    Board* testBoard = new Board();
    Piece* pawn = testBoard->getPiece(6, 1);  

    ASSERT_TRUE(pawn != nullptr && pawn->getType() == PieceType::Pawn);

    // Move two steps forward from initial position
    EXPECT_TRUE(pawn->move(6, 1, 4, 1));
    testBoard->updateBoard(6, 1, 4, 1);
    EXPECT_EQ(testBoard->getPiece(4, 1), pawn);
}

// Test pawn's diagonal capture move
TEST(PawnTests, testPawnDiagonalCapture) {
    Board* testBoard = new Board();
    Piece* pawn = testBoard->getPiece(6, 4);  // Assuming a white pawn starts at (6,4)
    Piece* enemyPawn = new Pawn(Color::BLACK, 5, 5, testBoard);
    testBoard->placePiece(5, 5, enemyPawn);

    // Check if the pawn is not nullptr and is indeed a pawn before proceeding
    ASSERT_TRUE(pawn != nullptr && pawn->getType() == PieceType::Pawn);

    // Diagonal capture
    EXPECT_TRUE(pawn->move(6, 4, 5, 5));
    testBoard->updateBoard(6, 4, 5, 5);
    EXPECT_EQ(testBoard->getPiece(5, 5), pawn);
}

// Test pawn's invalid backward movement
TEST(PawnTests, testPawnInvalidBackwardMovement) {
    Board* testBoard = new Board();
    Piece* pawn = testBoard->getPiece(6, 2);  // Assuming a pawn has moved to (5,2)

    // Check if the pawn is not nullptr and is indeed a pawn before proceeding
    ASSERT_TRUE(pawn != nullptr && pawn->getType() == PieceType::Pawn);

    // Attempt to move backward
    EXPECT_FALSE(pawn->move(5, 2, 6, 2));
    EXPECT_EQ(testBoard->getPiece(5, 2), pawn);
}

// Test pawn's invalid two-step forward after moving
TEST(PawnTests, testPawnInvalidDoubleStepAfterMoving) {
    Board* testBoard = new Board();
    Piece* pawn = testBoard->getPiece(6, 1);  // Assuming a pawn is initially at (6,1)

    // Move one step forward first
    ASSERT_TRUE(pawn->move(6, 1, 5, 1));
    testBoard->updateBoard(6, 1, 5, 1);

    // Then try moving two steps
    EXPECT_FALSE(pawn->move(5, 1, 3, 1));
    EXPECT_EQ(testBoard->getPiece(5, 1), pawn);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}