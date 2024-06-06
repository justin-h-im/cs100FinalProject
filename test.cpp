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

//===============================================
//								 GAME TESTS
//===============================================

// Test if you can create a game with no errors
TEST(GameTests, testConstructor) {
	EXPECT_NO_THROW({
		Game* game = new Game();
	});
}

// Test get turn
TEST(GameTests, testGetTurn) {
	Game* game = new Game();
	EXPECT_EQ(game->getTurn(), Color::WHITE);
}

// Test update turn
TEST(GameTests, testUpdateTurn) {
	Game* game = new Game();
	game->updateTurn();
	EXPECT_EQ(game->getTurn(), Color::BLACK);
}

// Test set white king
TEST(GameTests, testSetWhiteKing) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		game->setWhiteKing(board->getPiece(7, 4));
	});
}

// Test set black king
TEST(GameTests, testSetBlackKing) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		game->setBlackKing(board->getPiece(0, 4));
	});
}

// // Test white win
// TEST(GameTests, testWhiteWin) {
// 	Game* game = new Game();
// 	Board* board = new Board();
// 	Piece* blackKing = board->getPiece(0, 4);
// 	game->setWhiteKing(blackKing);
// 	blackKing->takeDamage(blackKing->getMaxHp());
// 	EXPECT_EQ(game->whiteWin(), true);
// }

//===============================================
//								BOARD TESTS
//===============================================

// Test if you can create a board with no errors
TEST(BoardTests, testConstructor) {
	EXPECT_NO_THROW({
		Board* board = new Board();
	});
}

TEST(BoardTests, testSetGame) {
	EXPECT_NO_THROW({
		Game* game = new Game();
		Board* board = new Board();
		board->setGame(game);
	});
}
// ensure that get piece does not throw errors
TEST(BoardTests, testGetPiece) {
	EXPECT_NO_THROW({
		Board* board = new Board();
		board->getPiece(0, 0);
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

// Test what happens when a piece of the same color is moved onto a piece of the same color
TEST(BoardTests, testMovePieceOntoPiece) {
	Game* game = new Game();
	Board* board = new Board();
	board->setGame(game);

	EXPECT_EQ(board->verifyMove(7, 1, 6, 3), -1);
}

// TEST if place piece works as intended
TEST(BoardTests, testPlacePiece) {
	Board* board = new Board();
	Display* display = new Display(board);
	Piece* piece = new Queen(Color::WHITE, 3, 3, board);

	display->displayBoard();
	cout << endl;
	board->placePiece(3, 3, piece);
	display->displayBoard();
}

//===============================================
//								DISPLAY TESTS
//===============================================

// Test basic display
TEST(DisplayTests, testDisplayBoard) {
	EXPECT_NO_THROW({
		Board* board = new Board();
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