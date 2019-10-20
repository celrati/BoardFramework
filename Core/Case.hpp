/**
*  Case code source Copyright 
*   2018 -- 2019 --
*/

#ifndef CASE_HPP
#define CASE_HPP

#include <iostream>
#include "Piece.hpp"
#include "../lib/Position.hpp"


class Case{
private:

	std::string color_case; // to put the color of the case
	
	Position position_case;

	int empty_case; //  true if empty  false if full

	Piece * piece_case; // pointer of Piece ..

public:	

	Case();
	Case(std::string color,Position position);
	// getters --
	std::string getColor() const;
	Position getPosition() const;

	int isEmpty() const;
	Piece * getPiece() const;
	

	void setFull(int ok); // 1 empty  0 full
	void setPiece(Piece * piece);

	void setColor(std::string color);
	void setPosition(const Position & position);

	void freeCase();
	friend ostream & operator<<(ostream & os, const Case & c);

};

#endif