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

// Test if you can create a board with no errors
TEST(BoardTests, testConstructor) {
	EXPECT_NO_THROW({
		Board* board = new Board();
	});
}

// Test if update board works on its own
TEST(BoardTests, testUpdateBoard) {
	Board* board = new Board();
	Piece* testPiece = board->getPiece(1, 0);
	board->updateBoard(1, 0, 4, 0);
	EXPECT_EQ(board->getPiece(4, 0), testPiece);
}

// Test if you can make working moves
TEST(BoardTests, testValidMove) {
	Game* game = new Game();
	Board* board = new Board();
	board->setGame(game);

	EXPECT_EQ(board->verifyMove(7, 1, 5, 0), 0);
}

// Test what happens when you try to move a piece that isn't yours
TEST(BoardTests, testInvalidPieceToMove) {
	Game* game = new Game();
	Board* board = new Board();
	board->setGame(game);

	EXPECT_EQ(board->verifyMove(3, 3, 0, 0), -1);
}

// Test what happens when you try to move a piece to a place it can't
TEST(BoardTests, testInvalidMoveNormal) {
	Game* game = new Game();
	Board* board = new Board();
	board->setGame(game);

	EXPECT_EQ(board->verifyMove(7, 0, 3, 0), -1);
}

TEST(BoardTests, testMovePieceOntoPiece) {
	Game* game = new Game();
	Board* board = new Board();
	board->setGame(game);

	EXPECT_EQ(board->verifyMove(7, 1, 6, 3), -1);
}

// Test basic display
TEST(DisplayTests, testDisplayBoard) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		board->setGame(game);
		Display* display = new Display(board);
		display->displayBoard();
	});
}

// Test combat for kings
TEST(DisplayTests, testDisplayCombatKings) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		board->setGame(game);
		Display* display = new Display(board);
		
		display->displayCombat(board->getPiece(7, 4), board->getPiece(0, 4));
	});
}

 // Test combat for queens
TEST(DisplayTests, testDisplayCombatQueens) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		board->setGame(game);
		Display* display = new Display(board);
		
		display->displayCombat(board->getPiece(7, 3), board->getPiece(0, 3));
	});
}

 // Test combat for queens
TEST(DisplayTests, testDisplayCombatRooks) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		board->setGame(game);
		Display* display = new Display(board);
		
		display->displayCombat(board->getPiece(7, 0), board->getPiece(0, 0));
	});
}

 // Test combat for queens
TEST(DisplayTests, testDisplayCombatKnights) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		board->setGame(game);
		Display* display = new Display(board);
		
		display->displayCombat(board->getPiece(7, 1), board->getPiece(0, 1));
	});
}

 // Test combat for queens
TEST(DisplayTests, testDisplayCombatBishops) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		board->setGame(game);
		Display* display = new Display(board);
		
		display->displayCombat(board->getPiece(7, 2), board->getPiece(0, 2));
	});
}

 // Test combat for queens
TEST(DisplayTests, testDisplayCombatPawns) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		board->setGame(game);
		Display* display = new Display(board);
		
		display->displayCombat(board->getPiece(6, 0), board->getPiece(1, 0));
	});
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}