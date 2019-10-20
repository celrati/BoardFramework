#ifndef BOAR_HPP
#define BOAR_HPP

#include "Case.hpp"
#include <iostream>
#include <utility>  // to use the pair
#include <vector>

/**
* Abstract class Board to use --
*    you have to implement all the methods 
*/

using namespace std;


class Board{

protected:

	Board(){}  

public:



	virtual void initBoardColor() = 0;
	virtual Case getCase(int row,int col) = 0;
	virtual pair<int,int> getCase(string color_piece , string name_piece) = 0; 
	virtual void movePieceTo(Position start_pos, Position end_pos) = 0;
	virtual void setCase(int row, int col, Case c) = 0;
	virtual void printBoard() = 0;
	virtual void setNotification(string notif) = 0;
	virtual void setNotification2(string notif) = 0;
	virtual string getListPossibleMoves(string color_player) = 0;
	virtual vector< pair<Position,Position>  > getListPossibleMovesVector(string color_player) = 0;
	virtual void restartBoard() = 0;
	virtual void freeCase(int row, int col) = 0;

	
	
};


#endif