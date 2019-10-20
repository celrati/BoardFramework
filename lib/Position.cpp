#include "Position.hpp"

Position::Position(){}
Position::Position(char col_pos, char row_pos){
	this->row_pos = row_pos;
	this->col_pos = col_pos;
}
char Position::getRowPos() const{
	return this->row_pos;
}
char Position::getColPos() const{
	return this->col_pos;
}
bool operator==(const Position & pos1, const Position & pos2){
	return (pos1.getColPos() == pos2.getColPos() && 
		pos1.getRowPos() == pos2.getRowPos());
}

void Position::printPosition(){
	std::cout<<"pos : "<<col_pos<<" , "<<row_pos<<" "<<std::endl;
}
int Position::getMatrixNumber(char pos){
	char a  = 'a';
	char b  = '8';

	for(int i = 0; i < 10 ; i++, a++, b--){
		if( pos == a || pos == b) return i;
	}
}