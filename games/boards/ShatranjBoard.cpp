#include "ChessBoard.hpp"
#include <fstream> // for reading the file
#include "../../pipe/OutputWriter.hpp"
#include "../rules/ShatranjRule.hpp"
#include "../../lib/Position.hpp"

ShatranjBoard::ShatranjBoard(int flag){

	this->notification_to_show = "Good Luck !";
	this->notification_to_show2 = "--------";
	initBoardColor();
	OutputWriter::writeToFileNotification("Shatranj -- GAME START !!!!");
	if(flag == BOARD_INIT){
		//freopen("ChessFiles/initBoard.oc", "r", stdin);
		std::ifstream infile("files/initBoard_shatranj.oc");
		for(int i = 0; i < SIZE_BOARD_CHESS ; i++){
			for(int j = 0; j < SIZE_BOARD_CHESS ; j++){
				string piece; infile>>piece;
				if(piece != "x"){			
					this->cases[i][j].setPiece(PieceFactory::newPiece(piece));		
				}
			}
		}				
	}
}
void ShatranjBoard::restartBoard(){
	this->notification_to_show = "Good Luck !";
	this->notification_to_show2 = "--------";
	initBoardColor();
	OutputWriter::writeToFileNotification("Shatranj -- GAME START !!!!");
		//freopen("ChessFiles/initBoard.oc", "r", stdin);
		std::ifstream infile("files/initBoard_shatranj.oc");
		for(int i = 0; i < SIZE_BOARD_CHESS ; i++){
			for(int j = 0; j < SIZE_BOARD_CHESS ; j++){
				string piece; infile>>piece;
				if(piece != "x"){		
					this->cases[i][j].freeCase();
					this->cases[i][j].setPiece(PieceFactory::newPiece(piece));		
				}
			}
		}				
}

ostream & operator<<(ostream & os, const ShatranjBoard & shatranjBoard){ 
	// to change the design later
// draw the Board with TEXT MODE -- 
	os<<"    a   b   c   d   e   f   g   h"<<endl;
	os<<"____________________________________"<<endl;
	for(int i = 0; i < SIZE_BOARD_CHESS ; i++){
		os<<SIZE_BOARD_CHESS - i<<" |";
		for(int j = 0; j < SIZE_BOARD_CHESS ; j++){
			os<<"|"<<shatranjBoard.cases[i][j]<<"|";
		}
		os<<"| "<<SIZE_BOARD_CHESS - i;
		os<<std::endl;
	}
	os<<"____________________________________"<<endl;
	os<<"    a   b   c   d   e   f   g   h  "<<endl<<endl;

	os<<" -- Chess v0.4 --"<<endl;
	return os;

}
void ShatranjBoard::initBoardColor(){
	for(int i = 0; i < SIZE_BOARD_CHESS ; i++){
		for(int j = 0 ; j < SIZE_BOARD_CHESS ; j++){
			if(i%2 == 0 && j%2 == 0) cases[i][j].setColor(WHITE);
			if(i%2 == 0 && j%2 != 0) cases[i][j].setColor(BLACK);
			if(i%2 != 0 && j%2 == 0) cases[i][j].setColor(BLACK);
			if(i%2 != 0 && j%2 != 0) cases[i][j].setColor(WHITE);
		}
	}
}
void ShatranjBoard::movePieceTo(Position start_pos, Position end_pos){

	int i_start = Position::getMatrixNumber(start_pos.getRowPos());
	int j_start = Position::getMatrixNumber(start_pos.getColPos());

	int i_end = Position::getMatrixNumber(end_pos.getRowPos());
	int j_end = Position::getMatrixNumber(end_pos.getColPos());


	if(!(cases[i_start][j_start].isEmpty())){
		cases[i_end][j_end].setPiece( cases[i_start][j_start].getPiece() );
		cases[i_start][j_start].freeCase();
	}
}
Case ShatranjBoard::getCase(int row, int col){

	return cases[row][col];
}

pair<int, int>  ShatranjBoard::getCase(string color_piece, string name_piece){
	for( int i = 0 ; i < SIZE_BOARD_CHESS ; i++){
		for( int j = 0; j <SIZE_BOARD_CHESS ; j++){
			Case ret = getCase(i,j);
			if(!ret.isEmpty()){
				if(ret.getPiece()->getColor() == color_piece &&
					ret.getPiece()->getName() == name_piece){
					pair<int, int> x_y = make_pair(i,j);
					return x_y;
				}
			}
		}
	}
}
void ShatranjBoard::setCase(int row, int col, Case c){
	this->cases[row][col] = c;
}

void ShatranjBoard::freeCase(int row, int col){
    this->cases[row][col].freeCase();
}

void ShatranjBoard::printBoard(){
cout<<"  +---------------------------------------+"<<endl;
    for(int i = 0; i < SIZE_BOARD_CHESS ; i++){
        cout<<SIZE_BOARD_CHESS - i<<" |";
        for(int j = 0; j < SIZE_BOARD_CHESS ; j++){
            if(cases[i][j].isEmpty() == 1){
                if(cases[i][j].getColor() == "BLACK"){
                    cout<<"####"<<"|";
                }else if(cases[i][j].getColor() == "WHITE"){
                    cout<<"    "<<"|";
                }   
            }else{
                if(cases[i][j].getPiece()->getColor() == "BLACK"){
                    if(cases[i][j].getPiece()->getName() == "Rook"){
                        cout<<" R1 "<<"|";
                    }else if(cases[i][j].getPiece()->getName() == "Knight"){
                        cout<<" K1 "<<"|";
                    }else if(cases[i][j].getPiece()->getName() == "Bishop"){
                        cout<<" B1 "<<"|";
                    }else if(cases[i][j].getPiece()->getName() == "Queen"){
                        cout<<" Q1 "<<"|";
                    }else if(cases[i][j].getPiece()->getName() == "King"){
                        cout<<" %1 "<<"|";
                    }else if(cases[i][j].getPiece()->getName() == "Pawn"){
                        cout<<" P1 "<<"|";
                    }
                }else{
                    if(cases[i][j].getPiece()->getName() == "Rook"){
                        cout<<" R0 "<<"|";
                    }else if(cases[i][j].getPiece()->getName() == "Knight"){
                        cout<<" K0 "<<"|";
                    }else if(cases[i][j].getPiece()->getName() == "Bishop"){
                        cout<<" B0 "<<"|";
                    }else if(cases[i][j].getPiece()->getName() == "Queen"){
                        cout<<" Q0 "<<"|";
                    }else if(cases[i][j].getPiece()->getName() == "King"){
                        cout<<" %0 "<<"|";
                    }else if(cases[i][j].getPiece()->getName() == "Pawn"){
                        cout<<" P0 "<<"|";
                    }
                }
            }
        }
        cout<<std::endl;
        if(i == 7 ) cout<<"  +---------------------------------------+"<<endl;
        else cout<<"  +----+----+----+----+----+----+----+----+"<<endl;
    }
    cout<<"     a    b    c    d    e    f    g    h"<<endl<<endl;

    cout<<endl;
    cout<<notification_to_show<<endl;
    cout<<notification_to_show2<<endl;
}
void ShatranjBoard::setNotification(string notif){
	this->notification_to_show = notif;
}
void ShatranjBoard::setNotification2(string notif){
	this->notification_to_show2 = notif;
}

string ShatranjBoard::getListPossibleMoves(string color_player){
	string ret = "";
	ShatranjRule rule;
	int i_i = 0;
	for(char i = '1'; i <= '8' ; i++){ // yes it's O(n^4) !
		for(char j = 'a' ; j <= 'h' ; j++){
			for(char k = '1' ; k <= '8'; k++){
				for(char l = 'a'; l <= 'h'; l++){

					int i_1 = Position::getMatrixNumber(i);
					int j_1 = Position::getMatrixNumber(j);
					int k_1 = Position::getMatrixNumber(k);
					int l_1 = Position::getMatrixNumber(l);

					if(!getCase(i_1,j_1).isEmpty()){
						if(getCase(i_1,j_1).getPiece()->getColor() == color_player){
							if(!getCase(k_1,l_1).isEmpty() && 
							getCase(k_1,l_1).getPiece()->getColor() == color_player){
							}else{
								if(rule.check(Position(j,i),Position(l,k),this)){
									ret += "move : ";
									ret += j;
									ret += i;
									ret += " to ";
									ret += l;
									ret += k;
									if(i_i % 3 == 0){
										ret += '\n';
									}else{
										ret += ' ';
										ret += '|';
										ret += ' ';
									}
									i_i++;
								}
							}
						}
					}
				}
			}
		}
	}
	ret += "\n ----------CONSOLE :-----------\n";
	return ret;
}



vector< pair<Position,Position>  > ShatranjBoard::getListPossibleMovesVector(string color_player){
	vector< pair<Position,Position> > ret;
	ShatranjRule rule;

	for(char i = '1'; i <= '8' ; i++){ // yes it's O(n^4) !
		for(char j = 'a' ; j <= 'h' ; j++){
			for(char k = '1' ; k <= '8'; k++){
				for(char l = 'a'; l <= 'h'; l++){

					int i_1 = Position::getMatrixNumber(i);
					int j_1 = Position::getMatrixNumber(j);
					int k_1 = Position::getMatrixNumber(k);
					int l_1 = Position::getMatrixNumber(l);

					if(!getCase(i_1,j_1).isEmpty()){
						if(getCase(i_1,j_1).getPiece()->getColor() == color_player){
							if(!getCase(k_1,l_1).isEmpty() && 
							getCase(k_1,l_1).getPiece()->getColor() == color_player){
							}else{
								if(rule.check(Position(j,i),Position(l,k),this)){
									Position p1(j,i);
									Position p2(l,k);
									pair<Position, Position> pp = make_pair(p1,p2);
									ret.push_back(pp);
								}
							}
						}
					}
				}
			}
		}
	}


	return ret;
}