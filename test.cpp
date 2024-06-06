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

//===============================================
//								QUEEN TESTS
//===============================================


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