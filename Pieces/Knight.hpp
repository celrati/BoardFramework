#ifndef KNIGHT_PIECE
#define KNIGHT_PIECE

#include "../lib/ShortCutUtil.hpp"
#include "../Core/Piece.hpp"
#include <iostream>


class Knight : public Piece{
	public:
		Knight(string color){ this->color = color; }
		string getName() const{ return "Knight";	}
		int getScore() const{ return 3; }
		string getColor() const{ return color; }
		void printPiece(ostream & os) const{
			os<<"K"<<(getColor() == "BLACK")?"b":"w";
		}
};

#endif