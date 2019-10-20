#ifndef QUEEN_PIECE
#define QUEEN_PIECE

#include "../lib/ShortCutUtil.hpp"
#include "../Core/Piece.hpp"
#include <iostream>

class Queen: public Piece{
	public:
		Queen(string color){ this->color = color; }
		string getName() const{ return "Queen";	}
		int getScore() const{ return 9; }
		string getColor() const{ return color; }
		void printPiece(ostream & os) const{
			os<<"Q"<<(getColor() == "BLACK")?"b":"w";
		}
};


#endif