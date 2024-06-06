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


// Expect true when the first input is 1.
TEST(UISuite, startMenuInput1) {
  std::cout << "For this test, user inputs 1. " << endl;
  ui *testUI = new ui();
  EXPECT_TRUE(testUI->outputStartMenu());
}

TEST(UISuite, startMenuInput2) {
  std::cout << "For this test, user inputs 2, then q, then 3." << endl;
  ui *testUI = new ui();
  EXPECT_NO_THROW(testUI->outputStartMenu());
}

// Expect false when the first input is 3.
TEST(UISuite, startMenuInput3) {
  std::cout << "For this test, user inputs 3." << endl;
  ui *testUI = new ui();
  EXPECT_FALSE(testUI->outputStartMenu());
}

// Expect true after inputting values that exist on the board.
// For this test, the values will be 6, 7, 5, 5.
TEST(UISuite, turnMenu) {
  std::cout << "For this test, user inputs 6, 7, 5, 5 for a successful turn." << endl;
  ui *testUI = new ui();
  EXPECT_TRUE(testUI->outputTurnMenu());
}

TEST(UISuite, outputEndScreen) {
  ui *testUI = new ui();
  EXPECT_NO_THROW(testUI->outputEndScreen());
}

TEST(UISuite, outputUserGuide) {
  std::cout << "For this test, user inputs q after the manual." << endl;
  ui *testUI = new ui();
  EXPECT_NO_THROW(testUI->outputUserGuide());
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