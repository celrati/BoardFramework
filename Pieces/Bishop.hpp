#ifndef BISHOP_PIECE
#define BISHOP_PIECE

#include "../lib/ShortCutUtil.hpp"
#include "../Core/Piece.hpp"
#include <iostream>


class Bishop : public Piece{
	public:
		Bishop(string color){ this->color = color; }
		string getName() const{ return "Bishop";	}
		int getScore() const{ return 3; }
		string getColor() const{ return color; }
		void printPiece(ostream & os) const{
			os<<"B"<<(getColor() == "BLACK")?"b":"w";
		}
};


#endif