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
using namespace std;

/* 
 *
 * 	ROOK Tests
 *
 */
TEST(RookTests, testRookVerticalMovement) {
    Board* testBoard = new Board();
   
    testBoard->updateBoard(6, 0, 3, 0);

    Piece* rook = testBoard->getPiece(7, 0);  
    ASSERT_TRUE(rook != nullptr && rook->getType() == PieceType::Rook);

    // Move right horizontally
    EXPECT_TRUE(rook->move(7, 0, 4, 0));
    testBoard->updateBoard(7, 0, 4, 0);
    EXPECT_EQ(testBoard->getPiece(4, 0), rook);
}

TEST(RookTests, testRookHorizontalMovement) {
    Board* testBoard = new Board();
    
    testBoard->updateBoard(0, 0, 3, 3); 

    Piece* rook = testBoard->getPiece(3, 3);  
    ASSERT_TRUE(rook != nullptr && rook->getType() == PieceType::Rook);

    // Move down vertically
    EXPECT_TRUE(rook->move(3, 3, 3, 7));
    testBoard->updateBoard(3, 3, 3, 7);
    EXPECT_EQ(testBoard->getPiece(3, 7), rook);
}

TEST(RookTests, testRookInvalidDiagonalMovement) {
    Board* testBoard = new Board();

    Piece* rook = testBoard->getPiece(0, 0); 
    ASSERT_TRUE(rook != nullptr && rook->getType() == PieceType::Rook);

    // Attempt diagonal move
    EXPECT_FALSE(rook->move(0, 0, 2, 2));
    EXPECT_EQ(testBoard->getPiece(0, 0), rook);

    delete testBoard;
}

TEST(RookTests, testRookBlockedMovement) {
    Board* testBoard = new Board();

    Piece* blockingPiece = new Pawn(Color::BLACK, 0, 1, testBoard);  
    testBoard->placePiece(0, 1, blockingPiece);

    Piece* rook = testBoard->getPiece(0, 0);  
    ASSERT_TRUE(rook != nullptr && rook->getType() == PieceType::Rook);

    // Attempt to move past a blocking piece
    EXPECT_FALSE(rook->move(0, 0, 0, 4));
    EXPECT_EQ(testBoard->getPiece(0, 0), rook);

    delete testBoard;
}

TEST(RookTests, testRookCastling) {
    Board* testBoard = new Board();

    testBoard->updateBoard(0, 1, 2, 1); 
    testBoard->updateBoard(0, 2, 2, 2); 
    testBoard->updateBoard(0, 3, 2, 3); 

    Piece* rook = testBoard->getPiece(0, 0);  
    ASSERT_TRUE(rook != nullptr && rook->getType() == PieceType::Rook);

    // Attempt diagonal move
    EXPECT_TRUE(rook->move(0, 0, 0, 4));
    testBoard->updateBoard(0, 0, 0, 4); 
    EXPECT_EQ(testBoard->getPiece(0, 4), rook);

    delete testBoard;
}

/* 
 *
 * 	UI Tests
 *
 */
TEST(UISuite, startGameFromMenu) {
  ui *testUI = new ui();
  std::ifstream ifs;
  ifs.open("test/startGameFromMenu.txt", std::ifstream::in);
  if (!ifs.is_open()) {
    cout << "Failure to open file." << endl;
    FAIL();
  }
  EXPECT_TRUE(testUI->outputStartMenu(ifs));
  ifs.close();
}

TEST(UISuite, openUserGuide) {
  ui *testUI = new ui();
  std::ifstream ifs;
  ifs.open("test/openUserGuide.txt", std::ifstream::in);
  if (!ifs.is_open()) {
    cout << "Failure to open file." << endl;
    FAIL();
  }
  EXPECT_FALSE(testUI->outputStartMenu(ifs));
  ifs.close();
}

TEST(UISuite, startMenuInput3) {
  ui *testUI = new ui();
  std::ifstream ifs;
  ifs.open("test/closeMenu.txt", std::ifstream::in);
  if (!ifs.is_open()) {
    cout << "Failure to open file." << endl;
    FAIL();
  }
  EXPECT_FALSE(testUI->outputStartMenu(ifs));
  ifs.close();
}


TEST(UISuite, simulateMove) {
  ui *testUI = new ui();
  std::ifstream ifs;
  ifs.open("test/simulateMove.txt", std::ifstream::in);
  if (!ifs.is_open()) {
    cout << "Failure to open file." << endl;
    FAIL();
  }
  EXPECT_TRUE(testUI->outputTurnMenu(ifs));
  EXPECT_TRUE(testUI->outputTurnMenu(ifs));
  ifs.close();
}

TEST(UISuite, endGameMidTurn) {
  ui *testUI = new ui();
  std::ifstream ifs;
  ifs.open("test/endGameMidTurn.txt", std::ifstream::in);
  if (!ifs.is_open()) {
    cout << "Failure to open file." << endl;
    FAIL();
  }
  EXPECT_TRUE(testUI->outputTurnMenu(ifs));
  EXPECT_TRUE(testUI->outputTurnMenu(ifs));
  EXPECT_FALSE(testUI->outputTurnMenu(ifs));
  ifs.close();
}

TEST(UISuite, outputEndScreen) {
  ui *testUI = new ui();
  EXPECT_NO_THROW(testUI->outputEndScreen());
}

/* 
 *
 * 	Queen Piece Tests
 *
 */

TEST(QueenTests, testQueenMovementDiagonal) {
    Board* test = new Board();
    Queen* queen = new Queen(Color::WHITE, 3, 4, test);
    test->placePiece(3, 4, queen);
    
    // valid diagonal move
    EXPECT_TRUE(queen->move(3, 4, 5, 6));
    test->updateBoard(3, 4, 5, 6);
    EXPECT_EQ(test->getPiece(5, 6), queen);
}

TEST(QueenTests, testQueenMovementHorizontal) {
    Board* test = new Board();
    Queen* queen = new Queen(Color::WHITE, 5, 6, test);
    test->placePiece(5, 6, queen);

    // valid horizontal move
    EXPECT_TRUE(queen->move(5, 6, 5, 2));
    test->updateBoard(5, 6, 5, 2);
    EXPECT_EQ(test->getPiece(5, 2), queen);
}

TEST(QueenTests, testQueenMovementVertical) {
    Board* test = new Board();
    Queen* queen = new Queen(Color::WHITE, 5, 2, test);
    test->placePiece(5, 2, queen);

    // valid vertical move
    EXPECT_TRUE(queen->move(5, 2, 3, 2));
    test->updateBoard(5, 2, 3, 2);
    EXPECT_EQ(test->getPiece(3, 2), queen);
}

TEST(QueenTests, testQueenMovementInvalid) {
    Board* test = new Board();
    Queen* queen = new Queen(Color::WHITE, 5, 6, test);
    test->placePiece(5, 6, queen);

    // invalid move
    EXPECT_FALSE(queen->move(5, 6, 7, 7));
    EXPECT_EQ(test->getPiece(5, 6), queen);
}

//===============================================
//								BISHOP TESTS
//===============================================

TEST(BishopTests, testBishopMovementDiagonal1) {
    Board* test = new Board();
    Bishop* bishop = new Bishop(Color::BLACK, 2, 4, test);
    test->placePiece(2, 4, bishop);
    
    // valid diagonal move 1
    EXPECT_TRUE(bishop->move(2, 4, 4, 6));
    test->updateBoard(2, 4, 4, 6);
    EXPECT_EQ(test->getPiece(4, 6), bishop);
}

TEST(BishopTests, testBishopMovementDiagonal2) {
    Board* test = new Board();
    Bishop* bishop = new Bishop(Color::BLACK, 4, 6, test);
    test->placePiece(4, 6, bishop);

    // valid diagonal move 2
    EXPECT_TRUE(bishop->move(4, 6, 2, 4));
    test->updateBoard(4, 6, 2, 4);
    EXPECT_EQ(test->getPiece(2, 4), bishop);
}

TEST(BishopTests, testBishopMovementInvalid) {
    Board* test = new Board();
    Bishop* bishop = new Bishop(Color::BLACK, 4, 6, test);
    test->placePiece(4, 6, bishop);

    // invalid move
    EXPECT_FALSE(bishop->move(4, 6, 2, 0));
    EXPECT_EQ(test->getPiece(4, 6), bishop);
}


//===============================================
//								KNIGHT TESTS
//===============================================


TEST(KnightTests, testKnightMovementL1) {
    Board* test = new Board();
    Knight* knight = new Knight(Color::BLACK, 5, 0, test);
    test->placePiece(5, 0, knight);
    
    // valid L-shape move 1
    EXPECT_TRUE(knight->move(5, 0, 3, 1));
    test->updateBoard(5, 0, 3, 1);
    EXPECT_EQ(test->getPiece(3, 1), knight);
}

TEST(KnightTests, testKnightMovementL2) {
    Board* test = new Board();
    Knight* knight = new Knight(Color::BLACK, 3, 1, test);
    test->placePiece(3, 1, knight);
    
    // valid L-shape move 2
    EXPECT_TRUE(knight->move(3, 1, 4, 3));
    test->updateBoard(3, 1, 4, 3);
    EXPECT_EQ(test->getPiece(4, 3), knight);
}

TEST(KnightTests, testKnightMovementInvalid) {
    Board* test = new Board();
    Knight* knight = new Knight(Color::BLACK, 4, 3, test);
    test->placePiece(4, 3, knight);

    // invalid move
    EXPECT_FALSE(knight->move(4, 3, 0, 0));
    EXPECT_EQ(test->getPiece(4, 3), knight);
}

/////////////////////////////////////////

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}