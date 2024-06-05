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

TEST(BoardTests, testUpdateBoard) {
	Board* test;
	Piece* testPiece = test->getPiece(1, 0);
	test->updateBoard(0, 0, 4, 0);
	EXPECT_EQ(test->getPiece(4, 0), testPiece);
	delete testPiece;
	delete test;

// Expect true when the first input is 1.
TEST(UISuite, startMenuInput1) {
  ui *testUI = new ui();
  EXPECT_TRUE(testUI->outputStartMenu());
}

// Expect false when the first input is 3.
TEST(UISuite, startMenuInput3) {
  ui *testUI = new ui();
  EXPECT_FALSE(testUI->outputStartMenu());
}

// Expect true after inputting values that exist on the board.
TEST(UISuite, turnMenu) {
    ui *testUI = new ui();
    EXPECT_NO_THROW(testUI->outputTurnMenu());
}

TEST(BoardTests, testUpdateBoard) {
	Board* test;
	Piece* testPiece = test->getPiece(1, 0);
	test->updateBoard(0, 0, 4, 0);
	EXPECT_EQ(test->getPiece(4, 0), testPiece);
	delete testPiece;
	delete test;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}