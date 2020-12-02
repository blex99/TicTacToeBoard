/**
 * Unit Tests for TicTacToeBoard
 **/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, toggleGetPlacePieceTest)
{
	TicTacToeBoard ttt;
	
	// the turn has been switched to O's
	ASSERT_TRUE(O == ttt.toggleTurn());

	// place piece
	ASSERT_TRUE(ttt.placePiece(1, 1) == O); // now X's turn

	ASSERT_TRUE(ttt.placePiece(1, 1) == O); // there's an O already there!

	ASSERT_TRUE(ttt.placePiece(-1, 0) == Invalid); // out of range
	ASSERT_TRUE(ttt.placePiece(3, 0) == Invalid);
	ASSERT_TRUE(ttt.placePiece(0, -1) == Invalid);
	ASSERT_TRUE(ttt.placePiece(0, 3) == Invalid);

	ASSERT_TRUE(ttt.placePiece(1, 2) == X); // now O's turn

	// get piece
	ASSERT_TRUE(ttt.getPiece(1, 2) == X); 
	ASSERT_TRUE(ttt.getPiece(1, 1) == O); 
	ASSERT_TRUE(ttt.getPiece(0, 0) == Blank); 
	ASSERT_TRUE(ttt.getPiece(-1, 0) == Invalid); // out of range
}


TEST(TicTacToeBoardTest, winnerTest)
{
	TicTacToeBoard ttt[3];

	// testing game not over
	// X   
	// X O 
	//   O 
	ttt[0].placePiece(0, 0);
	ttt[0].placePiece(1, 1);
	ttt[0].placePiece(1, 0);
	ttt[0].placePiece(2, 1);
	ASSERT_TRUE(ttt[0].getWinner() == Invalid);

	// testing col win X
	// X  
	// X O 
	// X O
	ttt[0].placePiece(0, 0);
	ttt[0].placePiece(1, 1);
	ttt[0].placePiece(1, 0);
	ttt[0].placePiece(2, 1);
	ttt[0].placePiece(2, 0);
	ASSERT_TRUE(ttt[0].getWinner() == X);

	// testing row win O
	// O O O
	// X X
	// X
	ttt[1].placePiece(1, 1);
	ttt[1].placePiece(0, 0);
	ttt[1].placePiece(1, 0);
	ttt[1].placePiece(0, 1);
	ttt[1].placePiece(2, 0);
	ttt[1].placePiece(0, 2);
	ASSERT_TRUE(ttt[1].getWinner() == O);

	// testing board is filled and there's a tie
	// x o x
	// o o x
	// x x o
	ttt[2].placePiece(0, 0);
	ttt[2].placePiece(0, 1);

	ttt[2].placePiece(0, 2);
	ttt[2].placePiece(1, 0);

	ttt[2].placePiece(1, 2);
	ttt[2].placePiece(1, 1);

	ttt[2].placePiece(2, 0);
	ttt[2].placePiece(2, 2);

	ttt[2].placePiece(2, 1);

	ASSERT_TRUE(ttt[2].getWinner() == Blank);
}



















