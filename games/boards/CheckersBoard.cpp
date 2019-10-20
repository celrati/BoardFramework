#include "CheckersBoard.hpp"
#include <fstream> // for reading the file
#include "../../pipe/OutputWriter.hpp"
#include "../rules/CheckersRule.hpp"
#include "../../lib/Position.hpp"

CheckersBoard::CheckersBoard(int flag){
    this->notification_to_show = "Good Luck !";
    this->notification_to_show2 = "--------";
    initBoardColor();
    OutputWriter::writeToFileNotification("GAME START !!!!");
    if(flag == BOARD_INIT){
        std::ifstream infile("files/initBoardC.oc");
        for(int i = 0; i < SIZE_BOARD_DAME ; i++){
            for(int j = 0; j < SIZE_BOARD_DAME ; j++){
                string piece; 
                infile>>piece;
                if(piece != "x"){
                    this->cases[i][j].setPiece(PieceFactory::newPiece(piece));
                }
            }
        }				
    }
}

void CheckersBoard::restartBoard(){
    this->notification_to_show = "Good Luck !";
    this->notification_to_show2 = "--------";
    initBoardColor();
    OutputWriter::writeToFileNotification("GAME START !!!!");
        std::ifstream infile("files/initBoardC.oc");
        for(int i = 0; i < SIZE_BOARD_DAME ; i++){
            for(int j = 0; j < SIZE_BOARD_DAME ; j++){
                string piece; infile>>piece;
                if(piece != "x"){		
                    this->cases[i][j].freeCase();
                    this->cases[i][j].setPiece(PieceFactory::newPiece(piece));		
                }
            }
        }				
}

ostream & operator<<(ostream & os, const CheckersBoard & checkersBoard){ 
    os<<"  +-------------------------------+"<<endl;
    for(int i = 0; i < SIZE_BOARD_DAME ; i++){
        os<<SIZE_BOARD_DAME - i<<" |";
        for(int j = 0; j < SIZE_BOARD_DAME ; j++){
            if(checkersBoard.cases[i][j].isEmpty()){
                if(checkersBoard.cases[i][j].getColor() == "BLACK"){
                    os<<"###"<<"|";
                }else if(checkersBoard.cases[i][j].getColor() == "WHITE"){
                    os<<"   "<<"|";
                }   
            }else{
                if(checkersBoard.cases[i][j].getPiece()->getColor() == "BLACK"){
                    if(checkersBoard.cases[i][j].getPiece()->getName() == "Damier"){
                        os<<" @ "<<"|";
                    }else{
                        os<<" K "<<"|";
                    }
                }else{
                    if(checkersBoard.cases[i][j].getPiece()->getName() == "Damier"){
                        os<<" O "<<"|";
                    }else{
                        os<<" Q "<<"|";
                    }
                }
            }
        }
        os<<std::endl;
        if(i == 7 ) os<<"  +-------------------------------+"<<endl;
        else os<<"  +---+---+---+---+---+---+---+---+"<<endl;
    }
    os<<"    a   b   c   d   e   f   g   h"<<endl<<endl;

    os<<" -- Checker v0.1 --"<<endl;
    return os;

}

void CheckersBoard::initBoardColor(){
    for(int i = 0; i < SIZE_BOARD_DAME ; i++){
        for(int j = 0 ; j < SIZE_BOARD_DAME ; j++){
            if(i%2 == 0 && j%2 == 0) cases[i][j].setColor(BLACK);
            if(i%2 == 0 && j%2 != 0) cases[i][j].setColor(WHITE);
            if(i%2 != 0 && j%2 == 0) cases[i][j].setColor(WHITE);
            if(i%2 != 0 && j%2 != 0) cases[i][j].setColor(BLACK);
        }
    }
}

void CheckersBoard::movePieceTo(Position start_pos, Position end_pos){
    int i_start = Position::getMatrixNumber(start_pos.getRowPos());
    int j_start = Position::getMatrixNumber(start_pos.getColPos());

    int i_end = Position::getMatrixNumber(end_pos.getRowPos());
    int j_end = Position::getMatrixNumber(end_pos.getColPos());

    if(!(cases[i_start][j_start].isEmpty())){
        cases[i_end][j_end].setPiece( cases[i_start][j_start].getPiece() );
        cases[i_start][j_start].freeCase();
    }
}

Case CheckersBoard::getCase(int row, int col){
    return cases[row][col];
}

pair<int, int>  CheckersBoard::getCase(string color_piece, string name_piece){
    for( int i = 0 ; i < SIZE_BOARD_DAME ; i++){
        for( int j = 0; j <SIZE_BOARD_DAME ; j++){
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

void CheckersBoard::setCase(int row, int col, Case c){
    this->cases[row][col] = c;
}

void CheckersBoard::freeCase(int row, int col){
    this->cases[row][col].freeCase();
}

void CheckersBoard::printBoard(){
    cout<<"  +-------------------------------+"<<endl;
    for(int i = 0; i < SIZE_BOARD_DAME ; i++){
        cout<<SIZE_BOARD_DAME - i<<" |";
        for(int j = 0; j < SIZE_BOARD_DAME ; j++){
            if(cases[i][j].isEmpty() == 1){
                if(cases[i][j].getColor() == "BLACK"){
                    cout<<"###"<<"|";
                }else if(cases[i][j].getColor() == "WHITE"){
                    cout<<"   "<<"|";
                }   
            }else{
                if(cases[i][j].getPiece()->getColor() == "BLACK"){
                    if(cases[i][j].getPiece()->getName() == "Damier"){
                        cout<<" @ "<<"|";
                    }else{
                        cout<<" K "<<"|";
                    }
                }else{
                    if(cases[i][j].getPiece()->getName() == "Damier"){
                        cout<<" O "<<"|";
                    }else{
                        cout<<" Q "<<"|";
                    }
                }
            }
        }
        cout<<std::endl;
        if(i == 7 ) cout<<"  +-------------------------------+"<<endl;
        else cout<<"  +---+---+---+---+---+---+---+---+"<<endl;
    }
    cout<<"    a   b   c   d   e   f   g   h"<<endl<<endl;

    cout<<endl;
    cout<<notification_to_show<<endl;
    cout<<notification_to_show2<<endl;
}

void CheckersBoard::setNotification(string notif){
    this->notification_to_show = notif;
}

void CheckersBoard::setNotification2(string notif){
    this->notification_to_show2 = notif;
}

string CheckersBoard::getListPossibleMoves(string color_player){
    string ret = "";
    CheckersRule rule;
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
                            if(!getCase(k_1,l_1).isEmpty() && getCase(k_1,l_1).getPiece()->getColor() == color_player){
                            }else{
                                if(getCase(i_1,j_1).getPiece()->getName() == "Damier"){
                                    if(rule.checkDamier(Position(j,i),Position(l,k),getCase(i_1,j_1), this) 
                                        || rule.damierJump(Position(j,i),Position(l,k),getCase(i_1,j_1), this, 1)){
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
                                }else if(getCase(i_1,j_1).getPiece()->getName() == "DamierKing"){
                                    if(rule.checkDamierKing(Position(j,i),Position(l,k),getCase(i_1,j_1), this, 1)){
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
    }
    ret += "\n ----------CONSOLE :-----------\n";
    return ret;
}

vector< pair<Position,Position> > CheckersBoard::getListPossibleMovesVector(string color_player){
    vector< pair<Position,Position> > ret;
    CheckersRule rule;

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