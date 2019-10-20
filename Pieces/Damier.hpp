#ifndef DAMIER_PIECE
#define DAMIER_PIECE

#include "../lib/ShortCutUtil.hpp"
#include "../Core/Piece.hpp"
#include <iostream>

class Damier: public Piece{
	public:
		Damier(string color){ this->color = color; }
		string getName() const{ return "Damier";	}
		int getScore() const{ return 10; }
		string getColor() const{ return color; }
		void printPiece(ostream & os) const{
			os<<"D"<<(getColor() == "BLACK")?"b":"w";
		}
};


#endif