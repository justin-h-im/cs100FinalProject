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

TEST(BoardTests, testConstructor) {
	EXPECT_NO_THROW({
		Board* test;
	});
}

TEST(BoardTests, testUpdateBoard) {
	Board* test;
	Piece* testPiece = test->getPiece(1, 0);
	test->updateBoard(0, 0, 4, 0);
	// EXPECT_EQ(test->getPiece(4, 0), testPiece);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}