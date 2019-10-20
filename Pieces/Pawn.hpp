#ifndef PAWN_PIECE
#define PAWN_PIECE

#include "../lib/ShortCutUtil.hpp"
#include "../Core/Piece.hpp"
#include <iostream>

using namespace std;


class Pawn : public Piece{
	public:
		Pawn(string color){ this->color = color; }
		string getName() const{ return "Pawn";	}
		int getScore() const{ return 1; }
		string getColor() const{ return this->color; }
		void printPiece(ostream & os) const{
			os<<"P"<<(getColor() == "BLACK")?"b":"w";
		}
		
};


#endif