#ifndef RULE_HPP
#define RULE_HPP

#include "../lib/Position.hpp"
#include "Board.hpp"
#include "Game.hpp"
#include <iostream>

/**
*    one of my good interfaces
*	 be gentle with her --
*/

class Rule{ // interface to extends for each rule ChessRule  DameRule ... --
public:
	virtual bool check(Position pos_start, Position pos_end, Board * board) = 0; // return true if we can do this mouvements
	// else right the errors or the exception in error file --


	//virtual bool checkSpecial(Position pos_start, Position pos_end, Board * board, string color_player) = 0;
	virtual bool checkAll(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board) = 0;
	/**
	* you have to implements this methods
	* like for example 
	* we use it for the castling enpassant cases --
	*/
};

#endif