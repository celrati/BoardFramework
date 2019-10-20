#ifndef KING_PIECE
#define KING_PIECE

#include "../lib/ShortCutUtil.hpp"
#include "../Core/Piece.hpp"
#include <iostream>


class King: public Piece{
	public:
		King(string color){ this->color = color; }
		string getName() const{ return "King";	}
		int getScore() const{ return 10; }
		string getColor() const{ return color; }
		void printPiece(ostream & os) const{
			os<<"%"<<(getColor() == "BLACK")?"b":"w";
		}
};

#endif