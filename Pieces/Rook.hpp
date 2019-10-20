#ifndef ROOK_PIECE
#define ROOK_PIECE

#include "../lib/ShortCutUtil.hpp"
#include "../Core/Piece.hpp"
#include <iostream>


class Rook: public Piece{
	public:
		Rook(string color){ this->color = color; }
		string getName() const{ return "Rook";	}
		int getScore() const{ return 5; }
		string getColor() const{ return color; }
		void printPiece(ostream & os) const{
			os<<"R"<<(getColor() == "BLACK")?"b":"w";
		}
};

#endif