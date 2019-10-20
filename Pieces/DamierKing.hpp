#ifndef DAMIERKING_PIECE
#define DAMIERKING_PIECE

#include "../lib/ShortCutUtil.hpp"
#include "../Core/Piece.hpp"
#include <iostream>

class DamierKing: public Piece{
	public:
		DamierKing(string color){ this->color = color; }
		string getName() const{ return "DamierKing";	}
		int getScore() const{ return 9; }
		string getColor() const{ return color; }
		void printPiece(ostream & os) const{
			os<<"M"<<(getColor() == "BLACK")?"b":"w";
		}
};


#endif