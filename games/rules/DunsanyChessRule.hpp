#ifndef DCHESS_RULE_HPP
#define DCHESS_RULE_HPP

#include <math.h>
#include <iostream>
#include "../../Core/Board.hpp"
#include "../../lib/Position.hpp"
#include "../../Core/Rule.hpp"
#include "../../Core/Piece.hpp"

class DunsanyChessRule: public Rule{
public:
	virtual bool check(Position pos_start, Position pos_end, Board * board);

	bool checkPawn(Position pos_start, Position pos_end, Case case_piece,Board * board);
	bool checkKnight(Position pos_start, Position pos_end, Case case_piece,Board * board);
	bool checkRook(Position pos_start, Position pos_end, Case case_piece,Board * board);
	bool checkBishop(Position pos_start, Position pos_end, Case case_piece,Board * board);
	bool checkQueen(Position pos_start, Position pos_end, Case case_piece,Board * board); //God save the Queen
	bool checkKing(Position pos_start, Position pos_end, Case case_piece,Board * board); 

	bool castling(string ins, string type_castling, string color_player, Board * board);

	virtual bool checkAll(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board); 

	void doIfEnPassant(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board);
	void doIfPromotePawn(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board);

	void markEnPassant(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board);


};

#endif