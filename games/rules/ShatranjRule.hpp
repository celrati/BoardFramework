#ifndef SHATRANJ_RULE_HPP
#define SHATRANJ_RULE_HPP

#include <math.h>
#include <iostream>
#include "../../Core/Board.hpp"
#include "../../lib/Position.hpp"
#include "../../Core/Rule.hpp"
#include "../../Core/Piece.hpp"

class ShatranjRule: public Rule{
public:
	virtual bool check(Position pos_start, Position pos_end, Board * board);

	bool checkPawn(Position pos_start, Position pos_end, Case case_piece,Board * board);
	bool checkKnight(Position pos_start, Position pos_end, Case case_piece,Board * board);
	bool checkRook(Position pos_start, Position pos_end, Case case_piece,Board * board);
	bool checkBishop(Position pos_start, Position pos_end, Case case_piece,Board * board);
	bool checkQueen(Position pos_start, Position pos_end, Case case_piece,Board * board); //God save the Queen
	bool checkKing(Position pos_start, Position pos_end, Case case_piece,Board * board); 

	virtual bool checkAll(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board); 

};

#endif