#ifndef PIE_HPP
#define PIE_HPP

#include "../lib/ShortCutUtil.hpp"


using namespace std;


class Piece {

	protected:

		string color;


	public:

		bool haveDangerEnPassant; 
		virtual string getColor() const = 0;
		virtual string getName() const = 0;
		virtual int getScore() const = 0;
		virtual void printPiece(ostream & os) const{
			os<<"X";
		}


};






#endif