
#include "../../lib/StateDetector.hpp"
#include "../../pipe/OutputWriter.hpp"
#include "../../Core/Game.hpp"
#include "ShatranjRule.hpp"


bool ShatranjRule::check(Position pos_start, Position pos_end, Board * board){
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
bool ShatranjRule::checkPawn(Position pos_start, Position pos_end,Case case_piece, Board * board){
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

	
		// here we can do just 1 step forward
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

	return true;
}
bool ShatranjRule::checkKnight(Position pos_start, Position pos_end, Case case_piece,Board * board){

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
bool ShatranjRule::checkRook(Position pos_start, Position pos_end,Case case_piece, Board * board){
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
bool ShatranjRule::checkBishop(Position pos_start, Position pos_end, Case case_piece,Board * board){
	int i_end = Position::getMatrixNumber(pos_end.getRowPos());
	int j_end = Position::getMatrixNumber(pos_end.getColPos());

	int i_start = Position::getMatrixNumber(pos_start.getRowPos());
	int j_start = Position::getMatrixNumber(pos_start.getColPos());

	// check if the mouvement is diag
	string color_bishop = case_piece.getPiece()->getColor();

	int mouv_x = fabs(j_end - j_start);
	int mouv_y = fabs(i_end - i_start);

	if(mouv_y == mouv_x && mouv_y == 2 ){	// detect the diago 
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
bool ShatranjRule::checkQueen(Position pos_start, Position pos_end, Case case_piece,Board * board){
	// because the Queen can do both Bishop and Rook
	int i_end = Position::getMatrixNumber(pos_end.getRowPos());
	int j_end = Position::getMatrixNumber(pos_end.getColPos());

	int i_start = Position::getMatrixNumber(pos_start.getRowPos());
	int j_start = Position::getMatrixNumber(pos_start.getColPos());

	// check if the mouvement is diag
	string color_bishop = case_piece.getPiece()->getColor();

	int mouv_x = fabs(j_end - j_start);
	int mouv_y = fabs(i_end - i_start);

	if(mouv_y == mouv_x && mouv_y == 1 ){	// detect the diago 
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
bool ShatranjRule::checkKing(Position pos_start, Position pos_end, Case case_piece,Board * board){
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


bool ShatranjRule::checkAll(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board){


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
				//doIfEnPassant(colorPlayer,pos_start,pos_end,game,board);
				// move the piece
				board->movePieceTo(Position(pos_start[0],pos_start[1]),Position(pos_end[0],pos_end[1]));
				// check the check !!
				
				// promote the pawn
				//doIfPromotePawn(colorPlayer,pos_start,pos_end,game,board);


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

			//markEnPassant(colorPlayer,pos_start,pos_end,game,board);

				// save the moves to the list of moves 
			game->saveMove(pos_start[0],pos_start[1],pos_end[0],pos_end[1]);

			board->setNotification("Good Move");
			OutputWriter::writeToFileNotification("GOOD MOVE ! !");
				return true;
			}else{
				// errors or exception --
				board->setNotification("Wrong Move");
				OutputWriter::writeToFileNotification("WRONG MOVE NOT YOUR PIECE ! ");
				cout<<"not the right piece --"<<endl;
			}
			
		}else{
			// errors or exception --
			board->setNotification("WRONG MOVE RESPECT THE RULES ! ");
			OutputWriter::writeToFileNotification("WRONG MOVE RESPECT THE RULES !  ");
		}
	return false;
}