#ifndef POS_HPP
#define POS_HPP

#include <iostream>
#include "ShortCutUtil.hpp"

class Position{
private:
	char row_pos;  // 1 2 3 ... 8
	char col_pos; // a b c ... h
public:
	Position();
	Position(char col_pos, char row_pos);
	char getRowPos() const;
	char getColPos() const;
	static int getMatrixNumber(char pos);   // 'a' -> 0
	//static Position  getAlgebraicPosition(const Position & position); // ex : (0,0) -> (8,a)
	friend bool operator==(const Position & pos1, const Position & pos2);
	//void printPositionAlg();
	void printPosition();
};



#endif