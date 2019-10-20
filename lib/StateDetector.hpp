#ifndef STATE_DETECTOR_HPP
#define STATE_DETECTOR_HPP

/**
*  Interface of state detection it takes the board
*    as argument 
*  and check if there is a check checkmate stalemate
*/

#include <iostream>
#include "../Core/Board.hpp"
#include "../Core/Case.hpp"

using namespace std;

class StateDetector{ //class with static member
private:

	// for the Shatranj --
	static bool isPilThreaningKing(string color_king,Board * board);
	static bool isFarzinThreaningKing(string color_king,Board * board);
	static bool isRoukhThreaningKing(string color_king,Board * board);
	static bool isFarasThreaningKing(string color_king,Board * board);
	static bool isBaidaqThreaningKing(string color_king,Board * board);



	// for the chess
	static bool isPawnThreaningKing(string color_king,Board * board); // done
	static bool isBishopThreaningKing(string color_king,Board * board); //done
	static bool isKnightThreaningKing(string color_king,Board * board); //done also works for Queen
	static bool isRookThreaningKing(string color_king,Board * board); // done also works for Queen
	
	//static bool isQueenThreaningKing(string color_king,Board * board);  DONT NEED IT --

	static bool isKingSafe(string color_king, Board * board); // done
	static bool isKingSafe_shatranj(string color_king, Board * board); // done




	static bool canPiecesSaveTheKing(string color,Board * board);
	static bool canPiecesSaveTheKing_shatranj(string color,Board * board);


public:
	// check the ShortCutUtil.hpp --
	static int isCheck(Board * board);
	static int checkMate(Board * board);
	//static int isStaleMate(Board * board);


 		// for the Shatranj --
	static int isCheck_shatranj(Board * board);
	static int checkMate_shatranj(Board * board);
        
                //for the checkers --
        static int gameEnd(Board * board);
        
                //for DunsanyChess
        static int allPawnKilled(Board * board);
};

#endif