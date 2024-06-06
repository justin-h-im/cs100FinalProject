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
		Board* board = new Board();
	});
}

TEST(BoardTests, testUpdateBoard) {
	Board* board = new Board();
	Piece* testPiece = board->getPiece(1, 0);
	board->updateBoard(1, 0, 4, 0);
	EXPECT_EQ(board->getPiece(4, 0), testPiece);
}

TEST(DisplayTests, testDisplayBoard) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		board->setGame(game);
		Display* display = new Display(board);
		display->displayBoard();
	});
}

TEST(DisplayTests, ) {
	
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}