#include "Case.hpp"

Case::Case(){ // just for init
	this->color_case = WHITE;
	this->piece_case = NULL;
	this->empty_case = 1;
}
Case::Case(std::string color, Position position){
	this->color_case = color;
	this->position_case = position;
	this->empty_case = 1;
	this->piece_case = NULL;
}
std::string Case::getColor() const{
	return this->color_case;
}
Position Case::getPosition() const{
	return this->position_case;
}
int Case::isEmpty() const{
	return this->empty_case;
}
Piece * Case::getPiece() const{
	return this->piece_case;
}
void Case::setFull(int ok){
	this->empty_case = ok;
}
void Case::setColor(std::string color){
	this->color_case = color;
}
void Case::setPosition(const Position & position){
	this->position_case = position;
}
void Case::setPiece(Piece * piece){
	this->piece_case = piece;
	this->empty_case = 0;
}
void Case::freeCase(){
	
	this->piece_case = NULL;
	this->empty_case = 1;
}
ostream & operator<<(ostream & os, const Case & c){

	if(!c.isEmpty()){
		c.piece_case->printPiece(os);
	}else{
		if(c.getColor() == WHITE) os<<"00";
		else if(c.getColor() == BLACK) os<<"11";
	}
	
	return os;
}