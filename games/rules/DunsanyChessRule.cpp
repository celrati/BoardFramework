#include "DunsanyChessRule.hpp"
#include "../../lib/StateDetector.hpp"
#include "../../pipe/OutputWriter.hpp"
#include "../../Core/Game.hpp"


bool DunsanyChessRule::check(Position pos_start, Position pos_end, Board * board){
	bool ret = true;

	int i_start = Position::getMatrixNumber(pos_start.getRowPos());
	int j_start = Position::getMatrixNumber(pos_start.getColPos());

	if(board->getCase(i_start,j_start).isEmpty()) return false;

	if(board->getCase(i_start,j_start).getPiece()->getName() == "Pawn"){
		return checkPawn(pos_start,pos_end,board->getCase(i_start,j_start),board);
	}
	if(board->getCase(i_start,j_start).getPiece()->getName() == "Knight"){
		return checkKnight(pos_start,pos_end,board->getCase(i_start,j_start),board);
	}
	if(board->getCase(i_start,j_start).getPiece()->getName() == "Rook"){
		return checkRook(pos_start,pos_end,board->getCase(i_start,j_start),board);
	}
	if(board->getCase(i_start,j_start).getPiece()->getName() == "Bishop"){
		return checkBishop(pos_start,pos_end,board->getCase(i_start,j_start),board);
	}
	if(board->getCase(i_start,j_start).getPiece()->getName() == "Queen"){
		return checkQueen(pos_start,pos_end,board->getCase(i_start,j_start),board);
	}
	if(board->getCase(i_start,j_start).getPiece()->getName() == "King"){
		return checkKing(pos_start,pos_end,board->getCase(i_start,j_start),board);
	}
	
	
	return false;

}
bool DunsanyChessRule::checkPawn(Position pos_start, Position pos_end,Case case_piece, Board * board){
	 // the rules for the pawn is 
	// 2mouve forwars or 1 after the second --
	int i_end = Position::getMatrixNumber(pos_end.getRowPos());
	int j_end = Position::getMatrixNumber(pos_end.getColPos());

	int i_start = Position::getMatrixNumber(pos_start.getRowPos());
	int j_start = Position::getMatrixNumber(pos_start.getColPos());

	string color_pawn = case_piece.getPiece()->getColor();
	if(color_pawn == WHITE){
		// the en passant

		if(i_end == i_start - 1  &&  j_end == j_start - 1  ){
			if(board->getCase(i_end,j_end).isEmpty()){
				if(!board->getCase(i_start,j_start -1 ).isEmpty()){
					if(board->getCase(i_start,j_start -1).getPiece()->getName() == "Pawn"){
						if(board->getCase(i_start,j_start - 1).getPiece()->getColor() != color_pawn){
							if(board->getCase(i_start,j_start - 1).getPiece()->haveDangerEnPassant){
								return true;
							}
						}
					}
				}
			}
		}

		if(i_end == i_start - 1  &&  j_end == j_start + 1  ){
			if(board->getCase(i_end,j_end).isEmpty()){
				if(!board->getCase(i_start,j_start +1 ).isEmpty()){
					if(board->getCase(i_start,j_start +1).getPiece()->getName() == "Pawn"){
						if(board->getCase(i_start,j_start + 1).getPiece()->getColor() != color_pawn){
							if(board->getCase(i_start,j_start + 1).getPiece()->haveDangerEnPassant){
								return true;
							}
						}
					}
				}
			}
		}

		if(pos_start.getRowPos() == '2'){ 	// here we can do 2 steps forward or 1

			if(pos_end.getRowPos() == pos_start.getRowPos() + 1 && 
				pos_end.getColPos() == pos_start.getColPos() ){
				if(board->getCase(i_end,j_end).isEmpty()) return true;
				return false;
			}
			if(pos_end.getRowPos() == pos_start.getRowPos() + 1 &&
				pos_end.getColPos() == pos_start.getColPos() - 1 ){
				if(board->getCase(i_end,j_end).isEmpty()) return false;
				if(board->getCase(i_end,j_end).getPiece()->getColor() == BLACK) return true;
				return false;
			}
			if(pos_end.getRowPos() == pos_start.getRowPos() + 1 &&
				pos_end.getColPos() == pos_start.getColPos() + 1){
				if(board->getCase(i_end,j_end).isEmpty()) return false;
				if(board->getCase(i_end,j_end).getPiece()->getColor() == BLACK) return true;
				return false;
			}
			if(pos_end.getRowPos() == pos_start.getRowPos() + 2 && 
				pos_end.getColPos() == pos_start.getColPos() ){


				if(!board->getCase(i_end,j_end).isEmpty()) return false;
				if(!board->getCase(i_end + 1,j_end).isEmpty()) return false;
				return true;
			}
			return false; //other cases --

		}else{	// here we can do just 1 step forward
			if(pos_end.getRowPos() == pos_start.getRowPos() + 1 && 
				pos_end.getColPos() == pos_start.getColPos() ){
				if(board->getCase(i_end,j_end).isEmpty()) return true;
				return false;
			}
			if(pos_end.getRowPos() == pos_start.getRowPos() + 1 &&
				pos_end.getColPos() == pos_start.getColPos() - 1 ){
				if(board->getCase(i_end,j_end).isEmpty()) return false;
				if(board->getCase(i_end,j_end).getPiece()->getColor() == BLACK) return true;
				return false;
			}
			if(pos_end.getRowPos() == pos_start.getRowPos() + 1 &&
				pos_end.getColPos() == pos_start.getColPos() + 1){
				if(board->getCase(i_end,j_end).isEmpty()) return false;
				if(board->getCase(i_end,j_end).getPiece()->getColor() == BLACK) return true;
				return false;
			}
			return false; //other cases --
		}

	}else{ // black color

		if(i_end == i_start + 1 &&  j_end == j_start + 1  ){
			if(board->getCase(i_end,j_end).isEmpty()){
				if(!board->getCase(i_start,j_start+1).isEmpty()){
					if(board->getCase(i_start,j_start+1).getPiece()->getName() == "Pawn"){
						if(board->getCase(i_start,j_start+1).getPiece()->getColor() != color_pawn){
							if(board->getCase(i_start,j_start+1).getPiece()->haveDangerEnPassant){
								return true;
							}
						}
					}
				}
			}
		}
		if(i_end == i_start + 1 &&  j_end == j_start - 1  ){
			if(board->getCase(i_end,j_end).isEmpty()){
				if(!board->getCase(i_start,j_start-1).isEmpty()){
					if(board->getCase(i_start,j_start-1).getPiece()->getName() == "Pawn"){
						if(board->getCase(i_start,j_start-1).getPiece()->getColor() != color_pawn){
							if(board->getCase(i_start,j_start-1).getPiece()->haveDangerEnPassant){
								
								return true;
							}
						}
					}
				}
			}
		}

		if(pos_start.getRowPos() == '7'){

			if(pos_end.getRowPos() == pos_start.getRowPos() - 1 && 
				pos_end.getColPos() == pos_start.getColPos() ){
				if(board->getCase(i_end,j_end).isEmpty()) return true;
				return false;
			}
			if(pos_end.getRowPos() == pos_start.getRowPos() - 1 &&
				pos_end.getColPos() == pos_start.getColPos() - 1 ){
				if(board->getCase(i_end,j_end).isEmpty()) return false;
				if(board->getCase(i_end,j_end).getPiece()->getColor() == WHITE) return true;
				return false;
			}
			if(pos_end.getRowPos() == pos_start.getRowPos() - 1 &&
				pos_end.getColPos() == pos_start.getColPos() + 1){
				if(board->getCase(i_end,j_end).isEmpty()) return false;
				if(board->getCase(i_end,j_end).getPiece()->getColor() == WHITE) return true;
				return false;
			}
			if(pos_end.getRowPos() == pos_start.getRowPos() - 2 && 
				pos_end.getColPos() == pos_start.getColPos() ){

				if(!board->getCase(i_end,j_end).isEmpty()) return false;
				if(!board->getCase(i_end-1,j_end).isEmpty()) return false;
				return true;
			}
			return false; //other cases --
		}else{
			if(pos_end.getRowPos() == pos_start.getRowPos() - 1 && 
				pos_end.getColPos() == pos_start.getColPos() ){
				if(board->getCase(i_end,j_end).isEmpty()) return true;
				return false;
			}
			if(pos_end.getRowPos() == pos_start.getRowPos() - 1 &&
				pos_end.getColPos() == pos_start.getColPos() - 1 ){
				if(board->getCase(i_end,j_end).isEmpty()) return false;
				if(board->getCase(i_end,j_end).getPiece()->getColor() == WHITE) return true;
				return false;
			}
			if(pos_end.getRowPos() == pos_start.getRowPos() - 1 &&
				pos_end.getColPos() == pos_start.getColPos() + 1){
				if(board->getCase(i_end,j_end).isEmpty()) return false;
				if(board->getCase(i_end,j_end).getPiece()->getColor() == WHITE) return true;
				return false;
			}
			return false; //other cases --
		}
	}

	return true;
}
bool DunsanyChessRule::checkKnight(Position pos_start, Position pos_end, Case case_piece,Board * board){

	int i_end = Position::getMatrixNumber(pos_end.getRowPos());
	int j_end = Position::getMatrixNumber(pos_end.getColPos());
	string color_knight = case_piece.getPiece()->getColor();

	if(board->getCase(i_end,j_end).isEmpty()){ // empty --
		if(pos_end.getRowPos() == pos_start.getRowPos() + 2 && 
			pos_end.getColPos() == pos_start.getColPos() + 1 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() + 2 && 
			pos_end.getColPos() == pos_start.getColPos() -1 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() + 1 && 
			pos_end.getColPos() == pos_start.getColPos() + 2 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() + 1 && 
			pos_end.getColPos() == pos_start.getColPos() - 2 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() - 1 && 
			pos_end.getColPos() == pos_start.getColPos() + 2 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() - 1 && 
			pos_end.getColPos() == pos_start.getColPos() - 2 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() - 2 && 
			pos_end.getColPos() == pos_start.getColPos() + 1 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() - 2 && 
			pos_end.getColPos() == pos_start.getColPos() - 1 ){
			return true;
		}

	}else{ // not empty --
		if(board->getCase(i_end,j_end).getPiece()->getColor() != color_knight){
		if(pos_end.getRowPos() == pos_start.getRowPos() + 2 && 
			pos_end.getColPos() == pos_start.getColPos() + 1 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() + 2 && 
			pos_end.getColPos() == pos_start.getColPos() -1 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() + 1 && 
			pos_end.getColPos() == pos_start.getColPos() + 2 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() + 1 && 
			pos_end.getColPos() == pos_start.getColPos() - 2 ){
			return true;
		}else if(pos_end.getRowPos() == pos_start.getRowPos() - 1 && 
			pos_end.getColPos() == pos_start.getColPos() + 2 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() - 1 && 
			pos_end.getColPos() == pos_start.getColPos() - 2 ){
			return true;
		}else if(pos_end.getRowPos() == pos_start.getRowPos() - 2 && 
			pos_end.getColPos() == pos_start.getColPos() + 1 ){
			return true;

		}else if(pos_end.getRowPos() == pos_start.getRowPos() - 2 && 
			pos_end.getColPos() == pos_start.getColPos() - 1 ){
			return true;
		}
		}
	}
	return false;
}
bool DunsanyChessRule::checkRook(Position pos_start, Position pos_end,Case case_piece, Board * board){
	int i_end = Position::getMatrixNumber(pos_end.getRowPos());
	int j_end = Position::getMatrixNumber(pos_end.getColPos());

	int i_start = Position::getMatrixNumber(pos_start.getRowPos());
	int j_start = Position::getMatrixNumber(pos_start.getColPos());

	string color_rook = case_piece.getPiece()->getColor();

	if(pos_end.getRowPos() != pos_start.getRowPos() &&   // vertical
			pos_end.getColPos() == pos_start.getColPos()){



			// check if we go up or down
			if(pos_end.getRowPos() > pos_start.getRowPos()){ 	// up
				// check wheter the col is emmpty between the two pos --
				for(int i = i_end + 1 ; i < i_start ; i++){
					if(!board->getCase(i,j_end).isEmpty()) return false;
				}
				if(board->getCase(i_end,j_end).isEmpty()) return true;
				if(board->getCase(i_end,j_end).getPiece()->getColor() != color_rook) return true;
				return false;

			}else{ 	// down

				// check wheter the col is emmpty between the two pos --
				for(int i = i_start + 1  ; i < i_end ; i++){
					//cout<<i<<endl;
					if(!board->getCase(i,j_end).isEmpty()) return false;
				}
				//cin>>i_start;
				if(board->getCase(i_end,j_end).isEmpty()) return true;
				if(board->getCase(i_end,j_end).getPiece()->getColor() != color_rook) return true;
				return false;
			}

	}else if(pos_end.getRowPos() == pos_start.getRowPos() && // horizontal
			pos_end.getColPos() != pos_start.getColPos()){

		if(pos_end.getColPos() > pos_start.getColPos() ){ // go right
			for( int j = j_start + 1 ; j < j_end ; j++ ){
				if(!board->getCase(i_end,j).isEmpty()) return false;
			}
			if(board->getCase(i_end,j_end).isEmpty()) return true;
			if(board->getCase(i_end,j_end).getPiece()->getColor() != color_rook) return true;
			return false;

		}else{ // go left
			for( int j = j_end + 1 ; j < j_start ; j++ ){
				if(!board->getCase(i_end,j).isEmpty()) return false;
			}
			if(board->getCase(i_end,j_end).isEmpty()) return true;
			if(board->getCase(i_end,j_end).getPiece()->getColor() != color_rook) return true;
			return false;

		}
		//cin>>j_start;

	}



	return false;
}
bool DunsanyChessRule::checkBishop(Position pos_start, Position pos_end, Case case_piece,Board * board){
	int i_end = Position::getMatrixNumber(pos_end.getRowPos());
	int j_end = Position::getMatrixNumber(pos_end.getColPos());

	int i_start = Position::getMatrixNumber(pos_start.getRowPos());
	int j_start = Position::getMatrixNumber(pos_start.getColPos());

	// check if the mouvement is diag
	string color_bishop = case_piece.getPiece()->getColor();

	int mouv_x = fabs(j_end - j_start);
	int mouv_y = fabs(i_end - i_start);

	if(mouv_y == mouv_x && mouv_y != 0){	// detect the diago 
		if(pos_end.getRowPos() > pos_start.getRowPos() &&
			pos_end.getColPos() > pos_start.getColPos() ){ // UP RIGHT

			int i = i_start - 1;
			for(int j = j_start + 1 ; j < j_end ; j++){
				if(!board->getCase(i,j).isEmpty()) return false;

				i--;
			}
			if(board->getCase(i_end,j_end).isEmpty()) return true;
			if(board->getCase(i_end,j_end).getPiece()->getColor() != color_bishop) return true;	
			return false;

		}
		if(pos_end.getRowPos() > pos_start.getRowPos() &&
			pos_end.getColPos() < pos_start.getColPos() ){ // UP LEFT

			int i = i_end + 1;
			for(int j = j_end + 1 ; j < j_start ; j++){
				if(!board->getCase(i,j).isEmpty()) return false;
				i++;
			}			
			if(board->getCase(i_end,j_end).isEmpty()) return true;
			if(board->getCase(i_end,j_end).getPiece()->getColor() != color_bishop) return true;
			return false;

		}
		if(pos_end.getRowPos() < pos_start.getRowPos() &&
			pos_end.getColPos() > pos_start.getColPos()){  // DOWN RIGHT

			int i = i_start +  1;
			for(int j = j_start + 1 ; j < j_end ; j++){
				if(!board->getCase(i,j).isEmpty()) return false;
				i++;
			}
			if(board->getCase(i_end,j_end).isEmpty()) return true;
			if(board->getCase(i_end,j_end).getPiece()->getColor() != color_bishop) return true;
			return false;
		}
		if(pos_end.getRowPos() < pos_start.getRowPos() &&
			pos_end.getColPos() < pos_start.getColPos()){  // DOWN LEFT

			int i = i_end - 1;
			for(int j = j_end + 1 ; j < j_start ; j++){
				if(!board->getCase(i,j).isEmpty()) return false;
				i--;
			}		
		
			if(board->getCase(i_end,j_end).isEmpty()) return true;
			if(board->getCase(i_end,j_end).getPiece()->getColor() != color_bishop) return true;
			return false;
		}
	}


	return false;
}	
bool DunsanyChessRule::checkQueen(Position pos_start, Position pos_end, Case case_piece,Board * board){
	// because the Queen can do both Bishop and Rook
	return (
		checkBishop(pos_start,pos_end,case_piece,board) 
							||
		checkRook(pos_start,pos_end,case_piece,board)
		);
}
bool DunsanyChessRule::checkKing(Position pos_start, Position pos_end, Case case_piece,Board * board){
	int i_end = Position::getMatrixNumber(pos_end.getRowPos());
	int j_end = Position::getMatrixNumber(pos_end.getColPos());

	int i_start = Position::getMatrixNumber(pos_start.getRowPos());
	int j_start = Position::getMatrixNumber(pos_start.getColPos());

	string color_king = case_piece.getPiece()->getColor();

	if(i_end == i_start && j_start == j_end) return false;

	if(fabs(i_end - i_start) <= 1 && fabs(j_end - j_start) <= 1){
		if(board->getCase(i_end,j_end).isEmpty()) return true;
		if(board->getCase(i_end,j_end).getPiece()->getColor() != color_king) return true;
	}

	return false;
}

bool DunsanyChessRule::castling(string ins, string type_castling, string color_player , Board * board){
	if(ins == "do" && StateDetector::isCheck(board) == NO_CHECK ){
		if(color_player == BLACK){
			if(type_castling == "o-o-o"){
				if(!board->getCase(0,4).isEmpty() && !board->getCase(0,0).isEmpty() ){
					if(board->getCase(0,4).getPiece()->getName() == "King" && 
						board->getCase(0,0).getPiece()->getName() == "Rook"){
						if(board->getCase(0,4).getPiece()->getColor() == color_player &&
							board->getCase(0,0).getPiece()->getColor() == color_player){
							if(board->getCase(0,1).isEmpty() && board->getCase(0,2).isEmpty() &&
								board->getCase(0,3).isEmpty() ){
								// now we have all the consitions to castle !!
								board->movePieceTo(Position('e','8'),Position('c','8'));
								board->movePieceTo(Position('a','8'),Position('d','8'));
								return true;
							}
						}
					}
				}
			}else if(type_castling == "o-o"){
				if(!board->getCase(0,4).isEmpty() && !board->getCase(0,7).isEmpty() ){
					if(board->getCase(0,4).getPiece()->getName() == "King" && 
						board->getCase(0,7).getPiece()->getName() == "Rook"){
						if(board->getCase(0,4).getPiece()->getColor() == color_player &&
							board->getCase(0,7).getPiece()->getColor() == color_player){
							if(board->getCase(0,5).isEmpty() && board->getCase(0,6).isEmpty()){
								// now we have all the consitions to castle !!
								board->movePieceTo(Position('e','8'),Position('g','8'));
								board->movePieceTo(Position('h','8'),Position('f','8'));
								return true;
							}
						}
					}
				}
			}
		}else{ // WHITE
			if(type_castling == "o-o-o"){
				if(!board->getCase(7,4).isEmpty() && !board->getCase(7,0).isEmpty() ){
					if(board->getCase(7,4).getPiece()->getName() == "King" && 
						board->getCase(7,0).getPiece()->getName() == "Rook"){
						if(board->getCase(7,4).getPiece()->getColor() == color_player &&
							board->getCase(7,0).getPiece()->getColor() == color_player){
							if(board->getCase(7,1).isEmpty() && board->getCase(7,2).isEmpty() &&
								board->getCase(7,3).isEmpty() ){
								// now we have all the consitions to castle !!
								board->movePieceTo(Position('e','1'),Position('c','1'));
								board->movePieceTo(Position('a','1'),Position('d','1'));
								return true;
							}
						}
					}
				}
			}else if(type_castling == "o-o"){
				if(!board->getCase(7,4).isEmpty() && !board->getCase(7,7).isEmpty() ){
					if(board->getCase(7,4).getPiece()->getName() == "King" && 
						board->getCase(7,7).getPiece()->getName() == "Rook"){
						if(board->getCase(7,4).getPiece()->getColor() == color_player &&
							board->getCase(7,7).getPiece()->getColor() == color_player){
							if(board->getCase(7,5).isEmpty() && board->getCase(7,6).isEmpty()){
								// now we have all the consitions to castle !!
								board->movePieceTo(Position('e','1'),Position('g','1'));
								board->movePieceTo(Position('h','1'),Position('f','1'));
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
void DunsanyChessRule::doIfEnPassant(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board){
	int col_start = Position::getMatrixNumber(pos_start[0]);
	int row_start = Position::getMatrixNumber(pos_start[1]);

	int col_end = Position::getMatrixNumber(pos_end[0]);
	int row_end = Position::getMatrixNumber(pos_end[1]);
		
	int i_end = row_end; int j_end = col_end;

	int i_start = row_start;int j_start = col_start;

	Case c_start = board->getCase(row_start,col_start);

	Case c_end = board->getCase(row_end,col_end);
		if(i_end == i_start - 1  &&  j_end == j_start - 1  ){
			if(board->getCase(i_end,j_end).isEmpty()){
				if(!board->getCase(i_start,j_start -1 ).isEmpty()){
					if(board->getCase(i_start,j_start -1).getPiece()->getName() == "Pawn"){
						if(board->getCase(i_start,j_start - 1).getPiece()->getColor() != colorPlayer){
							if(board->getCase(i_start,j_start - 1).getPiece()->haveDangerEnPassant){

								board->movePieceTo(Position(pos_start[0],pos_start[1]),
									Position(pos_start[0] - 1,pos_start[1]));
								board->movePieceTo(Position(pos_start[0] - 1,pos_start[1]),
									Position(pos_start[0],pos_start[1]));
							}
						}
					}
				}
			}
		}				
		if(i_end == i_start - 1  &&  j_end == j_start + 1  ){
			if(board->getCase(i_end,j_end).isEmpty()){
				if(!board->getCase(i_start,j_start +1 ).isEmpty()){
					if(board->getCase(i_start,j_start +1).getPiece()->getName() == "Pawn"){
						if(board->getCase(i_start,j_start + 1).getPiece()->getColor() != colorPlayer){
							if(board->getCase(i_start,j_start + 1).getPiece()->haveDangerEnPassant){
								board->movePieceTo(Position(pos_start[0],pos_start[1]),
									Position(pos_start[0] + 1,pos_start[1]));
								board->movePieceTo(Position(pos_start[0] + 1,pos_start[1]),
									Position(pos_start[0],pos_start[1]));
							}
						}
					}
				}
			}
		}
		if(i_end == i_start + 1 &&  j_end == j_start + 1  ){
			if(board->getCase(i_end,j_end).isEmpty()){
				if(!board->getCase(i_start,j_start+1).isEmpty()){
					if(board->getCase(i_start,j_start+1).getPiece()->getName() == "Pawn"){
						if(board->getCase(i_start,j_start+1).getPiece()->getColor() != colorPlayer){
							if(board->getCase(i_start,j_start+1).getPiece()->haveDangerEnPassant){
								board->movePieceTo(Position(pos_start[0],pos_start[1]),
									Position(pos_start[0] + 1,pos_start[1]));
								board->movePieceTo(Position(pos_start[0] + 1,pos_start[1]),
									Position(pos_start[0],pos_start[1]));
							}
						}
					}
				}
			}
		}
		if(i_end == i_start + 1 &&  j_end == j_start - 1  ){
			if(board->getCase(i_end,j_end).isEmpty()){
				if(!board->getCase(i_start,j_start-1).isEmpty()){
					if(board->getCase(i_start,j_start-1).getPiece()->getName() == "Pawn"){
						if(board->getCase(i_start,j_start-1).getPiece()->getColor() != colorPlayer){
							if(board->getCase(i_start,j_start-1).getPiece()->haveDangerEnPassant){
								board->movePieceTo(Position(pos_start[0],pos_start[1]),
									Position(pos_start[0] - 1,pos_start[1]));
								board->movePieceTo(Position(pos_start[0] - 1,pos_start[1]),
									Position(pos_start[0],pos_start[1]));
							}
						}
					}
				}
			}
		}
}
void DunsanyChessRule::doIfPromotePawn(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board){
	int col_start = Position::getMatrixNumber(pos_start[0]);
	int row_start = Position::getMatrixNumber(pos_start[1]);

	int col_end = Position::getMatrixNumber(pos_end[0]);
	int row_end = Position::getMatrixNumber(pos_end[1]);
		
	int i_end = row_end; int j_end = col_end;

	int i_start = row_start;int j_start = col_start;

	Case c_start = board->getCase(row_start,col_start);
	Case c_end = board->getCase(row_end,col_end);
		if(colorPlayer == WHITE && c_end.getPiece()->getName() == "Pawn"){
			if(i_end == 0 && i_start == 1 ){
				Case * c = new Case();
				c->setColor(WHITE);
				cout<<"congratulations the promotion which one you chose :"<<endl;
				cout<<"1 Knight"<<endl;
				cout<<"2 bishop"<<endl;
				cout<<"3 Rook"<<endl;
				cout<<"4 Queen ;)"<<endl;
				int ch_pr;
				do{
					cout<<"chose a number "<<endl;
					cin>>ch_pr;
					if(ch_pr >= 1 && ch_pr <= 4) break;
					continue;
				}while(1); 
				if(ch_pr == 1) c->setPiece(PieceFactory::newPiece("kw"));
				if(ch_pr == 2) c->setPiece(PieceFactory::newPiece("bw"));
				if(ch_pr == 3) c->setPiece(PieceFactory::newPiece("rw"));
				if(ch_pr == 4) c->setPiece(PieceFactory::newPiece("qw"));
				
				board->setCase(i_end,j_end,*c);
			}
		}else if(colorPlayer == BLACK && c_end.getPiece()->getName() == "Pawn" ){ // BLACK PLAYER
			if(i_end == 7 && i_start == 6 ){
				Case * c = new Case();
				c->setColor(BLACK);
				cout<<"congratulations the promotion which one you chose :"<<endl;
				cout<<"1 Knight"<<endl;
				cout<<"2 bishop"<<endl;
				cout<<"3 Rook"<<endl;
				cout<<"4 Queen ;)"<<endl;
				int ch_pr;
				do{
					cout<<"chose a number "<<endl;
					cin>>ch_pr;
					if(ch_pr >= 1 && ch_pr <= 4) break;
					continue;
				}while(1); 
				if(ch_pr == 1) c->setPiece(PieceFactory::newPiece("kb"));
				if(ch_pr == 2) c->setPiece(PieceFactory::newPiece("bb"));
				if(ch_pr == 3) c->setPiece(PieceFactory::newPiece("rb"));
				if(ch_pr == 4) c->setPiece(PieceFactory::newPiece("qb"));

				board->setCase(i_end,j_end,*c);				
			}
		}
}
void DunsanyChessRule::markEnPassant(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board){
	int col_start = Position::getMatrixNumber(pos_start[0]);
	int row_start = Position::getMatrixNumber(pos_start[1]);

	int col_end = Position::getMatrixNumber(pos_end[0]);
	int row_end = Position::getMatrixNumber(pos_end[1]);
		
	int i_end = row_end; int j_end = col_end;

	int i_start = row_start;int j_start = col_start;

	Case c_start = board->getCase(row_start,col_start);
	Case c_end = board->getCase(row_end,col_end);



	if(colorPlayer == WHITE ){
		if(c_end.getPiece()->getName() == "Pawn"){
			if(row_start == 6 && row_end == 4){
				board->getCase(row_end,col_end).getPiece()->haveDangerEnPassant = true;
			}else{
				board->getCase(row_end,col_end).getPiece()->haveDangerEnPassant = false;
			}
		}
	}else if(colorPlayer == BLACK){
		if(c_end.getPiece()->getName() == "Pawn"){
			if(row_start == 1 && row_end == 3){
				board->getCase(row_end,col_end).getPiece()->haveDangerEnPassant = true;
			}else{
				board->getCase(row_end,col_end).getPiece()->haveDangerEnPassant = false;
			}					
		}
	}

}

bool DunsanyChessRule::checkAll(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board){

		
	if(castling(pos_start,pos_end,colorPlayer,board)){
		// verify if we can castling --
		return true;
	}
	if(pos_start == "do") return false; // to avoid errors

	int col_start = Position::getMatrixNumber(pos_start[0]);
	int row_start = Position::getMatrixNumber(pos_start[1]);

	int col_end = Position::getMatrixNumber(pos_end[0]);
	int row_end = Position::getMatrixNumber(pos_end[1]);
		
	int i_end = row_end; int j_end = col_end;

	int i_start = row_start;int j_start = col_start;
        
	Case c_start = board->getCase(row_start,col_start);
	Case c_end = board->getCase(row_end,col_end);

		if(check(Position(pos_start[0],pos_start[1]),Position(pos_end[0],pos_end[1]),board)){ 
			// check function it verify if we respect the right move for the pieces 
			// you have to implement it for other games
			if(board->getCase(row_start,col_start).getPiece()->getColor() == colorPlayer){ // to check the color	
				/**
				* the en passant rule --
				*/
				doIfEnPassant(colorPlayer,pos_start,pos_end,game,board);
				// move the piece
				board->movePieceTo(Position(pos_start[0],pos_start[1]),Position(pos_end[0],pos_end[1]));
				// check the check !!
				
				// promote the pawn
				doIfPromotePawn(colorPlayer,pos_start,pos_end,game,board);


			if(colorPlayer == BLACK){
				if(StateDetector::isCheck(board) == CHECK_TO_BLACK){
					board->setCase(row_start,col_start,c_start);
					board->setCase(row_end,col_end,c_end);
					board->setNotification("PROTECT YOUR KING ");
					OutputWriter::writeToFileNotification("PROTECT YOUR KING ");
					return false;
				}
			}else{ // wHITE
				if(StateDetector::isCheck(board) == CHECK_TO_WHITE){
					board->setCase(row_start,col_start,c_start);
					board->setCase(row_end,col_end,c_end);
					board->setNotification("PROTECT YOUR KING ");
					OutputWriter::writeToFileNotification("PROTECT YOUR KING ");
					return false;
				}
			}
				// check the en passant --
			// here we activate the pawns with the ability of enPassant

			markEnPassant(colorPlayer,pos_start,pos_end,game,board);

				// save the moves to the list of moves 
			game->saveMove(pos_start[0],pos_start[1],pos_end[0],pos_end[1]);

			board->setNotification("Good Mouv");
			OutputWriter::writeToFileNotification("GOOD MOUV ! !");
				return true;
			}else{
				// errors or exception --
				board->setNotification("Wrong Mouv");
				OutputWriter::writeToFileNotification("WRONG MOUV NOT YOUR PIECE ! ");
				cout<<"not the right piece --"<<endl;
			}
			
		}else{
			// errors or exception --
			board->setNotification("WRONG MOUV RESPECT THE RULES !  ");
			OutputWriter::writeToFileNotification("WRONG MOUV RESPECT THE RULES !  ");
		}
	return false;
}