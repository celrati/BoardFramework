#include "StateDetector.hpp"
#include <utility>
#include "../games/rules/ChessRule.hpp"
#include "../games/rules/ShatranjRule.hpp"


bool StateDetector::isPawnThreaningKing(string color_king,Board * board){
	// check if kinfg with this color is threated by some pawn --
	int x = 2, y = 2;
	if(color_king == WHITE){
		
		pair<int, int> x_y = board->getCase(WHITE,"King"); 

		int x = x_y.first;
		int y = x_y.second;

	
		if(!board->getCase(x - 1 ,y + 1).isEmpty()){
			if(board->getCase(x - 1 ,y + 1).getPiece()->getName() == "Pawn"){
				if(board->getCase(x - 1 ,y + 1).getPiece()->getColor() != color_king){
					return true;
				}
			}
		}
		if(!board->getCase(x - 1 ,y - 1).isEmpty()){
			if(board->getCase(x - 1 ,y - 1).getPiece()->getName() == "Pawn"){
				if(board->getCase(x - 1 ,y - 1).getPiece()->getColor() != color_king){
					return true;
				}
			}			
		}

	}else{
		
		pair<int, int> x_y = board->getCase(BLACK,"King");

		int x = x_y.first;
		int y = x_y.second;

		if(!board->getCase(x + 1 ,y + 1).isEmpty()){

			
			if(board->getCase(x + 1 ,y + 1).getPiece()->getName() == "Pawn"){
				
				if(board->getCase(x + 1 ,y + 1).getPiece()->getColor() != color_king){
					return true;
				}
				
			}
			
		}
		
		if(!board->getCase(x + 1 ,y - 1).isEmpty()){
			if(board->getCase(x + 1 ,y - 1).getPiece()->getName() == "Pawn"){
				if(board->getCase(x + 1 ,y - 1).getPiece()->getColor() != color_king){
					return true;
				}
			}			
		}
		
	}

	return false;
}

bool StateDetector::isBishopThreaningKing(string color_king,Board * board){

		pair<int, int> x_y = board->getCase(color_king,"King"); 

		int x = x_y.first;
		int y = x_y.second;


		int a_x = x, a_y = y;  // UP RIGHT
		int b_x = x, b_y = y; // UP LEFT
		int c_x = x, c_y = y; // DOWN RIGHT
		int d_x = x, d_y = y; // DOWN LEFT

		int count_a = 0;
		int count_b = 0;
		int count_c = 0;
		int count_d = 0;

	
		for(int i = 0 ; i < 8 ; i++){ // just to loop
			a_x--; a_y++;
			b_x--; b_y--;
			c_x++; c_y++;
			d_x++; d_y--;

			if( a_x >= 0 && a_x < 8 && a_y >= 0 && a_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(a_x,a_y).isEmpty()){
					if(board->getCase(a_x,a_y).getPiece()->getColor() != color_king){
						if(board->getCase(a_x,a_y).getPiece()->getName() == "Bishop" ||
							board->getCase(a_x,a_y).getPiece()->getName() == "Queen"){

							if(count_a == 0) return true;
					}
				}
				count_a++;
			}
		}
		
			if( b_x >= 0 && b_x < 8 && b_y >= 0 && b_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(b_x,b_y).isEmpty()){
					if(board->getCase(b_x,b_y).getPiece()->getColor() != color_king){
						if(board->getCase(b_x,b_y).getPiece()->getName() == "Bishop" ||
							board->getCase(b_x,b_y).getPiece()->getName() == "Queen"){

							if(count_b == 0) return true;
					}
				}
				count_b++;
			}
		}
		
		
			if( c_x >= 0 && c_x < 8 && c_y >= 0 && c_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(c_x,c_y).isEmpty()){
					if(board->getCase(c_x,c_y).getPiece()->getColor() != color_king){
						if(board->getCase(c_x,c_y).getPiece()->getName() == "Bishop" ||
							board->getCase(c_x,c_y).getPiece()->getName() == "Queen"){

							if(count_c == 0) return true;
					}
				}
				count_c++;
			}
		}
		
			
			if( d_x >= 0 && d_x < 8 && d_y >= 0 && d_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(d_x,d_y).isEmpty()){
					if(board->getCase(d_x,d_y).getPiece()->getColor() != color_king){
						if(board->getCase(d_x,d_y).getPiece()->getName() == "Bishop" ||
							board->getCase(d_x,d_y).getPiece()->getName() == "Queen"){

							if(count_d == 0) return true;
					}
				}
				count_d++;
			}
		}



	}			

	
return false;
}
bool StateDetector::isKnightThreaningKing(string color_king,Board * board){

	pair<int, int> x_y = board->getCase(color_king,"King"); 

	int x = x_y.first;
	int y = x_y.second;

	int a_x = x-2, a_y = y + 1;
	int b_x = x-1, b_y = y + 2;
	int c_x = x-2, c_y = y - 1;
	int d_x = x-1, d_y = y - 2;	

	int i_x = x+2, i_y = y + 1;
	int j_x = x+1, j_y = y + 2;
	int k_x = x+2, k_y = y - 1;
	int l_x = x+1, l_y = y - 2;	

	if(a_x >= 0 && a_x < 8 && a_y >= 0 && a_y < 8){
		if(!board->getCase(a_x,a_y).isEmpty()){
			if(board->getCase(a_x,a_y).getPiece()->getColor() != color_king){
				if(board->getCase(a_x,a_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(b_x >= 0 && b_x < 8 && b_y >= 0 && b_y < 8){
		if(!board->getCase(b_x,b_y).isEmpty()){
			if(board->getCase(b_x,b_y).getPiece()->getColor() != color_king){
				if(board->getCase(b_x,b_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(c_x >= 0 && c_x < 8 && c_y >= 0 && c_y < 8){
		if(!board->getCase(c_x,c_y).isEmpty()){
			if(board->getCase(c_x,c_y).getPiece()->getColor() != color_king){
				if(board->getCase(c_x,c_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(d_x >= 0 && d_x < 8 && d_y >= 0 && d_y < 8){
		if(!board->getCase(d_x,d_y).isEmpty()){
			if(board->getCase(d_x,d_y).getPiece()->getColor() != color_king){
				if(board->getCase(d_x,d_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(i_x >= 0 && i_x < 8 && i_y >= 0 && i_y < 8){
		if(!board->getCase(i_x,i_y).isEmpty()){
			if(board->getCase(i_x,i_y).getPiece()->getColor() != color_king){
				if(board->getCase(i_x,i_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(j_x >= 0 && j_x < 8 && j_y >= 0 && j_y < 8){
		if(!board->getCase(j_x,j_y).isEmpty()){
			if(board->getCase(j_x,j_y).getPiece()->getColor() != color_king){
				if(board->getCase(j_x,j_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(k_x >= 0 && k_x < 8 && k_y >= 0 && k_y < 8){
		if(!board->getCase(k_x,k_y).isEmpty()){
			if(board->getCase(k_x,k_y).getPiece()->getColor() != color_king){
				if(board->getCase(k_x,k_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(l_x >= 0 && l_x < 8 && l_y >= 0 && l_y < 8){
		if(!board->getCase(l_x,l_y).isEmpty()){
			if(board->getCase(l_x,l_y).getPiece()->getColor() != color_king){
				if(board->getCase(l_x,l_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	return false;
}
bool StateDetector::isRookThreaningKing(string color_king,Board * board){

		pair<int, int> x_y = board->getCase(color_king,"King"); 

		int x = x_y.first;
		int y = x_y.second;


		int a_x = x, a_y = y;  // UP 
		int b_x = x, b_y = y; // DOWN
		int c_x = x, c_y = y; // RIGHT
		int d_x = x, d_y = y; // LEFT

		int count_a = 0;
		int count_b = 0;
		int count_c = 0;
		int count_d = 0;

	
		for(int i = 0 ; i < 8 ; i++){ // just to loop
			a_x--;
			b_x++;
			c_y++;
			d_y--;

			if( a_x >= 0 && a_x < 8 && a_y >= 0 && a_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(a_x,a_y).isEmpty()){
					if(board->getCase(a_x,a_y).getPiece()->getColor() != color_king){
						if(board->getCase(a_x,a_y).getPiece()->getName() == "Rook" ||
							board->getCase(a_x,a_y).getPiece()->getName() == "Queen"){

							if(count_a == 0) return true;
					}
				}
				count_a++;
			}
		}
		
			if( b_x >= 0 && b_x < 8 && b_y >= 0 && b_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(b_x,b_y).isEmpty()){
					if(board->getCase(b_x,b_y).getPiece()->getColor() != color_king){
						if(board->getCase(b_x,b_y).getPiece()->getName() == "Rook" ||
							board->getCase(b_x,b_y).getPiece()->getName() == "Queen"){

							if(count_b == 0) return true;
					}
				}
				count_b++;
			}
		}
		
		
			if( c_x >= 0 && c_x < 8 && c_y >= 0 && c_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(c_x,c_y).isEmpty()){
					if(board->getCase(c_x,c_y).getPiece()->getColor() != color_king){
						if(board->getCase(c_x,c_y).getPiece()->getName() == "Rook" ||
							board->getCase(c_x,c_y).getPiece()->getName() == "Queen"){

							if(count_c == 0) return true;
					}
				}
				count_c++;
			}
		}
		
			
			if( d_x >= 0 && d_x < 8 && d_y >= 0 && d_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(d_x,d_y).isEmpty()){
					if(board->getCase(d_x,d_y).getPiece()->getColor() != color_king){
						if(board->getCase(d_x,d_y).getPiece()->getName() == "Rook" ||
							board->getCase(d_x,d_y).getPiece()->getName() == "Queen"){

							if(count_d == 0) return true;
					}
				}
				count_d++;
			}
		}

	}			


	return false;
}




bool StateDetector::isKingSafe(string color_king, Board * board){
	return !isPawnThreaningKing(color_king,board)
		&&
		!isBishopThreaningKing(color_king,board)
		&&
		!isKnightThreaningKing(color_king,board)
		&&
		!isRookThreaningKing(color_king,board)
		;	
}
int StateDetector::isCheck(Board * board){
	if(!isKingSafe(WHITE,board)) return CHECK_TO_WHITE;
	if(!isKingSafe(BLACK,board)) return CHECK_TO_BLACK;	
	return  NO_CHECK;
}

bool StateDetector::canPiecesSaveTheKing(string color,Board * board){
	// find a pawn that can protect the king with the color- --
	ChessRule rule;

	for(char i = '1'; i <= '8' ; i++){ // yes it's O(n^4) !
		for(char j = 'a' ; j <= 'h' ; j++){
			for(char k = '1' ; k <= '8'; k++){
				for(char l = 'a'; l <= 'h'; l++){
					

					int i_1 = Position::getMatrixNumber(i);
					int j_1 = Position::getMatrixNumber(j);
					int k_1 = Position::getMatrixNumber(k);
					int l_1 = Position::getMatrixNumber(l);



					//cout<<"move ("<<i<<","<<j<<") to ("<<k<<","<<l<<") "<<endl;
					//cout<<!board->getCase(i_1,j_1).isEmpty()<<endl;

					
					if(!board->getCase(i_1,j_1).isEmpty()){

						if(board->getCase(i_1,j_1).getPiece()->getColor() == color){
					//cout<<"Ohayo"<<endl;

					
										
							if(!board->getCase(k_1,l_1).isEmpty() && 
							board->getCase(k_1,l_1).getPiece()->getColor() == color){
								//continue;
							}else{
								

								
								
								if(rule.check(Position(j,i),Position(l,k),board)){
									//cout<<"move ("<<i<<","<<j<<") to ("<<k<<","<<l<<") "<<endl;
									
									Piece * start_piece = (board->getCase(i_1,j_1).getPiece());

									Piece * end_piece = NULL;

									if(!board->getCase(k_1,l_1).isEmpty()){
										end_piece =  (board->getCase(k_1,l_1).getPiece());	
			
									}
									Case c_start = board->getCase(i_1,j_1);
									Case c_end = board->getCase(k_1,l_1);
									

									board->movePieceTo(Position(j,i),Position(l,k));
								
									
									if(isCheck(board) == NO_CHECK){

										if(end_piece != NULL){
											board->setCase(i_1,j_1,c_start);
											board->setCase(k_1,l_1,c_end);
											//board->movePieceTo(Position(l,k),Position(j,i));
											//board->getCase(k_1,l_1).setPiece(end_piece);			
										}else{
											board->movePieceTo(Position(l,k),Position(j,i));
											/*
											board->getCase(i_1,j_1).setPiece(start_piece);	
											board->getCase(k_1,l_1).freeCase();
											*/
										}
										return true;
									}else{
										if(end_piece != NULL){
											board->setCase(i_1,j_1,c_start);
											board->setCase(k_1,l_1,c_end);
											//board->getCase(i_1,j_1).setPiece(start_piece);	
											//board->getCase(k_1,l_1).setPiece(end_piece);			
										}else{
											board->movePieceTo(Position(l,k),Position(j,i));
											/*
											board->getCase(i_1,j_1).setPiece(start_piece);	
											board->getCase(k_1,l_1).freeCase();
											*/
										}
									}
									
									
								}
								
							}
							
							
						}		
					}
					
					
					
				}
			}
		}
	}

	//int a ;
	//cin>>a;
	return false;
}

int StateDetector::checkMate(Board * board){

	if(isCheck(board) == CHECK_TO_BLACK){
		if(canPiecesSaveTheKing(BLACK,board)){
			return NO_CHECK_MATE;
		}
		return CHECK_MATE_TO_BLACK;
	}
	if(isCheck(board) == CHECK_TO_WHITE){
		if(canPiecesSaveTheKing(WHITE,board)){
			return NO_CHECK_MATE;
		}
		return CHECK_MATE_TO_WHITE;		
	}
	return NO_CHECK_MATE;
}

////////
bool StateDetector::isBaidaqThreaningKing(string color_king,Board * board){
	// check if kinfg with this color is threated by some pawn --
	int x = 2, y = 2;
	if(color_king == WHITE){
		
		pair<int, int> x_y = board->getCase(WHITE,"King"); 

		int x = x_y.first;
		int y = x_y.second;

	
		if(!board->getCase(x - 1 ,y + 1).isEmpty()){
			if(board->getCase(x - 1 ,y + 1).getPiece()->getName() == "Pawn"){
				if(board->getCase(x - 1 ,y + 1).getPiece()->getColor() != color_king){
					return true;
				}
			}
		}
		if(!board->getCase(x - 1 ,y - 1).isEmpty()){
			if(board->getCase(x - 1 ,y - 1).getPiece()->getName() == "Pawn"){
				if(board->getCase(x - 1 ,y - 1).getPiece()->getColor() != color_king){
					return true;
				}
			}			
		}

	}else{
		
		pair<int, int> x_y = board->getCase(BLACK,"King");

		int x = x_y.first;
		int y = x_y.second;

		if(!board->getCase(x + 1 ,y + 1).isEmpty()){

			
			if(board->getCase(x + 1 ,y + 1).getPiece()->getName() == "Pawn"){
				
				if(board->getCase(x + 1 ,y + 1).getPiece()->getColor() != color_king){
					return true;
				}
				
			}
			
		}
		
		if(!board->getCase(x + 1 ,y - 1).isEmpty()){
			if(board->getCase(x + 1 ,y - 1).getPiece()->getName() == "Pawn"){
				if(board->getCase(x + 1 ,y - 1).getPiece()->getColor() != color_king){
					return true;
				}
			}			
		}
		
	}

	return false;
}
bool StateDetector::isPilThreaningKing(string color_king,Board * board){

		pair<int, int> x_y = board->getCase(color_king,"King"); 

		int x = x_y.first;
		int y = x_y.second;


		int a_x = x, a_y = y;  // UP RIGHT
		int b_x = x, b_y = y; // UP LEFT
		int c_x = x, c_y = y; // DOWN RIGHT
		int d_x = x, d_y = y; // DOWN LEFT

		int count_a = 0;
		int count_b = 0;
		int count_c = 0;
		int count_d = 0;

	
		
			a_x -= 2; a_y += 2;
			b_x -= 2; b_y -= 2;
			c_x += 2; c_y += 2;
			d_x += 2; d_y -= 2;

			if( a_x >= 0 && a_x < 8 && a_y >= 0 && a_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(a_x,a_y).isEmpty()){
					if(board->getCase(a_x,a_y).getPiece()->getColor() != color_king){
						if(board->getCase(a_x,a_y).getPiece()->getName() == "Bishop"){

							if(count_a == 0) return true;
					}
				}
				count_a++;
			}
		}
		
			if( b_x >= 0 && b_x < 8 && b_y >= 0 && b_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(b_x,b_y).isEmpty()){
					if(board->getCase(b_x,b_y).getPiece()->getColor() != color_king){
						if(board->getCase(b_x,b_y).getPiece()->getName() == "Bishop"){

							if(count_b == 0) return true;
					}
				}
				count_b++;
			}
		}
		
		
			if( c_x >= 0 && c_x < 8 && c_y >= 0 && c_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(c_x,c_y).isEmpty()){
					if(board->getCase(c_x,c_y).getPiece()->getColor() != color_king){
						if(board->getCase(c_x,c_y).getPiece()->getName() == "Bishop" ){

							if(count_c == 0) return true;
					}
				}
				count_c++;
			}
		}
		
			
			if( d_x >= 0 && d_x < 8 && d_y >= 0 && d_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(d_x,d_y).isEmpty()){
					if(board->getCase(d_x,d_y).getPiece()->getColor() != color_king){
						if(board->getCase(d_x,d_y).getPiece()->getName() == "Bishop"){

							if(count_d == 0) return true;
					}
				}
				count_d++;
			}
		}



				

	
return false;
}
bool StateDetector::isFarasThreaningKing(string color_king,Board * board){

	pair<int, int> x_y = board->getCase(color_king,"King"); 

	int x = x_y.first;
	int y = x_y.second;

	int a_x = x-2, a_y = y + 1;
	int b_x = x-1, b_y = y + 2;
	int c_x = x-2, c_y = y - 1;
	int d_x = x-1, d_y = y - 2;	

	int i_x = x+2, i_y = y + 1;
	int j_x = x+1, j_y = y + 2;
	int k_x = x+2, k_y = y - 1;
	int l_x = x+1, l_y = y - 2;	

	if(a_x >= 0 && a_x < 8 && a_y >= 0 && a_y < 8){
		if(!board->getCase(a_x,a_y).isEmpty()){
			if(board->getCase(a_x,a_y).getPiece()->getColor() != color_king){
				if(board->getCase(a_x,a_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(b_x >= 0 && b_x < 8 && b_y >= 0 && b_y < 8){
		if(!board->getCase(b_x,b_y).isEmpty()){
			if(board->getCase(b_x,b_y).getPiece()->getColor() != color_king){
				if(board->getCase(b_x,b_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(c_x >= 0 && c_x < 8 && c_y >= 0 && c_y < 8){
		if(!board->getCase(c_x,c_y).isEmpty()){
			if(board->getCase(c_x,c_y).getPiece()->getColor() != color_king){
				if(board->getCase(c_x,c_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(d_x >= 0 && d_x < 8 && d_y >= 0 && d_y < 8){
		if(!board->getCase(d_x,d_y).isEmpty()){
			if(board->getCase(d_x,d_y).getPiece()->getColor() != color_king){
				if(board->getCase(d_x,d_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(i_x >= 0 && i_x < 8 && i_y >= 0 && i_y < 8){
		if(!board->getCase(i_x,i_y).isEmpty()){
			if(board->getCase(i_x,i_y).getPiece()->getColor() != color_king){
				if(board->getCase(i_x,i_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(j_x >= 0 && j_x < 8 && j_y >= 0 && j_y < 8){
		if(!board->getCase(j_x,j_y).isEmpty()){
			if(board->getCase(j_x,j_y).getPiece()->getColor() != color_king){
				if(board->getCase(j_x,j_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(k_x >= 0 && k_x < 8 && k_y >= 0 && k_y < 8){
		if(!board->getCase(k_x,k_y).isEmpty()){
			if(board->getCase(k_x,k_y).getPiece()->getColor() != color_king){
				if(board->getCase(k_x,k_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	if(l_x >= 0 && l_x < 8 && l_y >= 0 && l_y < 8){
		if(!board->getCase(l_x,l_y).isEmpty()){
			if(board->getCase(l_x,l_y).getPiece()->getColor() != color_king){
				if(board->getCase(l_x,l_y).getPiece()->getName() == "Knight"){
					return true; }}}}

	return false;
}
bool StateDetector::isRoukhThreaningKing(string color_king,Board * board){

		pair<int, int> x_y = board->getCase(color_king,"King"); 

		int x = x_y.first;
		int y = x_y.second;


		int a_x = x, a_y = y;  // UP 
		int b_x = x, b_y = y; // DOWN
		int c_x = x, c_y = y; // RIGHT
		int d_x = x, d_y = y; // LEFT

		int count_a = 0;
		int count_b = 0;
		int count_c = 0;
		int count_d = 0;

	
		for(int i = 0 ; i < 8 ; i++){ // just to loop
			a_x--;
			b_x++;
			c_y++;
			d_y--;

			if( a_x >= 0 && a_x < 8 && a_y >= 0 && a_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(a_x,a_y).isEmpty()){
					if(board->getCase(a_x,a_y).getPiece()->getColor() != color_king){
						if(board->getCase(a_x,a_y).getPiece()->getName() == "Rook" ){

							if(count_a == 0) return true;
					}
				}
				count_a++;
			}
		}
		
			if( b_x >= 0 && b_x < 8 && b_y >= 0 && b_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(b_x,b_y).isEmpty()){
					if(board->getCase(b_x,b_y).getPiece()->getColor() != color_king){
						if(board->getCase(b_x,b_y).getPiece()->getName() == "Rook" ){

							if(count_b == 0) return true;
					}
				}
				count_b++;
			}
		}
		
		
			if( c_x >= 0 && c_x < 8 && c_y >= 0 && c_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(c_x,c_y).isEmpty()){
					if(board->getCase(c_x,c_y).getPiece()->getColor() != color_king){
						if(board->getCase(c_x,c_y).getPiece()->getName() == "Rook"){

							if(count_c == 0) return true;
					}
				}
				count_c++;
			}
		}
		
			
			if( d_x >= 0 && d_x < 8 && d_y >= 0 && d_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(d_x,d_y).isEmpty()){
					if(board->getCase(d_x,d_y).getPiece()->getColor() != color_king){
						if(board->getCase(d_x,d_y).getPiece()->getName() == "Rook"){

							if(count_d == 0) return true;
					}
				}
				count_d++;
			}
		}

	}			


	return false;
}

bool StateDetector::isFarzinThreaningKing(string color_king,Board * board){
		pair<int, int> x_y = board->getCase(color_king,"King"); 

		int x = x_y.first;
		int y = x_y.second;


		int a_x = x, a_y = y;  // UP RIGHT
		int b_x = x, b_y = y; // UP LEFT
		int c_x = x, c_y = y; // DOWN RIGHT
		int d_x = x, d_y = y; // DOWN LEFT

		int count_a = 0;
		int count_b = 0;
		int count_c = 0;
		int count_d = 0;

	
		
			a_x -= 1; a_y += 1;
			b_x -= 1; b_y -= 1;
			c_x += 1; c_y += 1;
			d_x += 1; d_y -= 1;

			if( a_x >= 0 && a_x < 8 && a_y >= 0 && a_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(a_x,a_y).isEmpty()){
					if(board->getCase(a_x,a_y).getPiece()->getColor() != color_king){
						if(board->getCase(a_x,a_y).getPiece()->getName() == "Bishop"){

							if(count_a == 0) return true;
					}
				}
				count_a++;
			}
		}
		
			if( b_x >= 0 && b_x < 8 && b_y >= 0 && b_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(b_x,b_y).isEmpty()){
					if(board->getCase(b_x,b_y).getPiece()->getColor() != color_king){
						if(board->getCase(b_x,b_y).getPiece()->getName() == "Bishop"){

							if(count_b == 0) return true;
					}
				}
				count_b++;
			}
		}
		
		
			if( c_x >= 0 && c_x < 8 && c_y >= 0 && c_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(c_x,c_y).isEmpty()){
					if(board->getCase(c_x,c_y).getPiece()->getColor() != color_king){
						if(board->getCase(c_x,c_y).getPiece()->getName() == "Bishop" ){

							if(count_c == 0) return true;
					}
				}
				count_c++;
			}
		}
		
			
			if( d_x >= 0 && d_x < 8 && d_y >= 0 && d_y < 8){ // just to avoid the famous SEGMENTATION ERROR
				if(!board->getCase(d_x,d_y).isEmpty()){
					if(board->getCase(d_x,d_y).getPiece()->getColor() != color_king){
						if(board->getCase(d_x,d_y).getPiece()->getName() == "Bishop"){

							if(count_d == 0) return true;
					}
				}
				count_d++;
			}
		}



				

	
return false;
}
bool StateDetector::isKingSafe_shatranj(string color_king, Board * board){
	return !isBaidaqThreaningKing(color_king,board)
		&&
		!isPilThreaningKing(color_king,board)
		&&
		!isFarzinThreaningKing(color_king,board)
		&&
		!isRoukhThreaningKing(color_king,board)
		&&
		!isFarasThreaningKing(color_king,board)
		;	
}
int StateDetector::isCheck_shatranj(Board * board){
	if(!isKingSafe_shatranj(WHITE,board)) return CHECK_TO_WHITE;
	if(!isKingSafe_shatranj(BLACK,board)) return CHECK_TO_BLACK;	
	return  NO_CHECK;
}
bool StateDetector::canPiecesSaveTheKing_shatranj(string color,Board * board){
	// find a pawn that can protect the king with the color- --
	ShatranjRule rule;

	for(char i = '1'; i <= '8' ; i++){ // yes it's O(n^4) !
		for(char j = 'a' ; j <= 'h' ; j++){
			for(char k = '1' ; k <= '8'; k++){
				for(char l = 'a'; l <= 'h'; l++){
					

					int i_1 = Position::getMatrixNumber(i);
					int j_1 = Position::getMatrixNumber(j);
					int k_1 = Position::getMatrixNumber(k);
					int l_1 = Position::getMatrixNumber(l);



					//cout<<"move ("<<i<<","<<j<<") to ("<<k<<","<<l<<") "<<endl;
					//cout<<!board->getCase(i_1,j_1).isEmpty()<<endl;

					
					if(!board->getCase(i_1,j_1).isEmpty()){

						if(board->getCase(i_1,j_1).getPiece()->getColor() == color){
					//cout<<"Ohayo"<<endl;

					
										
							if(!board->getCase(k_1,l_1).isEmpty() && 
							board->getCase(k_1,l_1).getPiece()->getColor() == color){
								//continue;
							}else{
								

								
								
								if(rule.check(Position(j,i),Position(l,k),board)){
									//cout<<"move ("<<i<<","<<j<<") to ("<<k<<","<<l<<") "<<endl;
									
									Piece * start_piece = (board->getCase(i_1,j_1).getPiece());

									Piece * end_piece = NULL;

									if(!board->getCase(k_1,l_1).isEmpty()){
										end_piece =  (board->getCase(k_1,l_1).getPiece());	
			
									}
									Case c_start = board->getCase(i_1,j_1);
									Case c_end = board->getCase(k_1,l_1);
									

									board->movePieceTo(Position(j,i),Position(l,k));
								
									
									if(isCheck(board) == NO_CHECK){

										if(end_piece != NULL){
											board->setCase(i_1,j_1,c_start);
											board->setCase(k_1,l_1,c_end);
											//board->movePieceTo(Position(l,k),Position(j,i));
											//board->getCase(k_1,l_1).setPiece(end_piece);			
										}else{
											board->movePieceTo(Position(l,k),Position(j,i));
											/*
											board->getCase(i_1,j_1).setPiece(start_piece);	
											board->getCase(k_1,l_1).freeCase();
											*/
										}
										return true;
									}else{
										if(end_piece != NULL){
											board->setCase(i_1,j_1,c_start);
											board->setCase(k_1,l_1,c_end);
											//board->getCase(i_1,j_1).setPiece(start_piece);	
											//board->getCase(k_1,l_1).setPiece(end_piece);			
										}else{
											board->movePieceTo(Position(l,k),Position(j,i));
											/*
											board->getCase(i_1,j_1).setPiece(start_piece);	
											board->getCase(k_1,l_1).freeCase();
											*/
										}
									}
									
									
								}
								
							}
							
							
						}		
					}
					
					
					
				}
			}
		}
	}

	//int a ;
	//cin>>a;
	return false;
}
int StateDetector::checkMate_shatranj(Board * board){

	if(isCheck_shatranj(board) == CHECK_TO_BLACK){
		if(canPiecesSaveTheKing_shatranj(BLACK,board)){
			return NO_CHECK_MATE;
		}
		return CHECK_MATE_TO_BLACK;
	}
	if(isCheck_shatranj(board) == CHECK_TO_WHITE){
		if(canPiecesSaveTheKing_shatranj(WHITE,board)){
			return NO_CHECK_MATE;
		}
		return CHECK_MATE_TO_WHITE;		
	}
	return NO_CHECK_MATE;
}

int StateDetector::gameEnd(Board * board){
    int white = 0;
    int black = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(!board->getCase(i, j).isEmpty()){
                if(board->getCase(i, j).getPiece()->getColor() == WHITE) white++;
                else if(board->getCase(i, j).getPiece()->getColor() == BLACK) black++;
            }
        }
    }
    if(white == 0 && black > 0) return BLACK_WIN;
    else if(white > 0 && black == 0) return WHITE_WIN;
    else return 0;
}

int StateDetector::allPawnKilled(Board * board){
    int white = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(!board->getCase(i, j).isEmpty()){
                if(board->getCase(i, j).getPiece()->getColor() == WHITE){
                    if(board->getCase(i, j).getPiece()->getName() == "Pawn") white++;
                }
            }
        }
    }
    if(white == 0) return BLACK_WIN;
    else return 0;
}