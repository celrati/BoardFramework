#ifndef CHECKERS_RULE_HPP
#define CHECKERS_RULE_HPP

#include <math.h>
#include <iostream>
#include "../../Core/Board.hpp"
#include "../../lib/Position.hpp"
#include "../../Core/Rule.hpp"
#include "../../Core/Piece.hpp"

class CheckersRule: public Rule{
public:
	virtual bool check(Position pos_start, Position pos_end, Board * board);
	virtual bool checkAll(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board); 
        
        bool checkDamier(Position pos_start, Position pos_end, Case case_piece,Board * board);
        bool checkDamierKing(Position pos_start, Position pos_end, Case case_piece,Board * board, int mode);
        bool damierJump(Position pos_start, Position pos_end, Case case_piece,Board * board, int mode);
        bool canStillPlay(Position pos_start, Case case_piece,Board * board);
        
        void doIfPromoteDamier(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board);
};

#endif