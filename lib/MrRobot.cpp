#include "MrRobot.hpp"
#include <utility>
#include <vector>
#include <stdlib.h> 
#include <time.h>
#include "../pipe/InputReader.hpp"
#include "../games/boards/ChessBoard.hpp"
#include "../games/rules/ChessRule.hpp"
#include "../games/rules/CheckersRule.hpp"
#include "../games/boards/CheckersBoard.hpp"
#include "../games/boards/DunsanyChessBoard.hpp"
#include "../games/rules/DunsanyChessRule.hpp"
#include "StateDetector.hpp"

using namespace std;

/**
** Mr Robot v0.02 ***
**	AI ****
**/ 

MrRobot::MrRobot(string name, string color,int score){
    this->name_player = name;
    this->color_player = color;
    this->score_player =score;
    this->state_player = PLAYER_CREATED;
}
string MrRobot::getName() const{
    return this->name_player;
}
string MrRobot::getColor() const{
    return this->color_player;
}
int MrRobot::getScore() const{
    return this->score_player;
}
int MrRobot::getState() const{
    return this->state_player;
}
void MrRobot::playMove(Board * board, string color_robot){
    //InputReader * inputReader = new InputReader<ChessBoard,ChessRule>(board, new ChessRule());

    vector< pair<Position,Position> > list_player = board->getListPossibleMovesVector(color_robot);
    srand(time(NULL));
    while(1){
        int rand_index = rand() % list_player.size();
        pair< Position, Position> p_rand = list_player[rand_index];

        int col_start = Position::getMatrixNumber(p_rand.first.getColPos());
        int row_start = Position::getMatrixNumber(p_rand.first.getRowPos());

        int col_end = Position::getMatrixNumber(p_rand.second.getColPos());
        int row_end = Position::getMatrixNumber(p_rand.second.getRowPos());

        Case c_start = board->getCase(row_start,col_start);
        Case c_end = board->getCase(row_end,col_end);

        board->movePieceTo(p_rand.first,p_rand.second);
        if(StateDetector::isCheck(board) == CHECK_TO_BLACK){
            board->setCase(row_start,col_start,c_start);
            board->setCase(row_end,col_end,c_end);
            continue;
        }		
        break;
    }
}

void MrRobot::playMove2(Board * board, string color_robot){

    vector< pair<Position,Position> > list_player = board->getListPossibleMovesVector(color_robot);
    srand(time(NULL));
    while(1){
        int rand_index = rand() % list_player.size();
        pair< Position, Position> p_rand = list_player[rand_index];

        int col_start = Position::getMatrixNumber(p_rand.first.getColPos());
        int row_start = Position::getMatrixNumber(p_rand.first.getRowPos());

        int col_end = Position::getMatrixNumber(p_rand.second.getColPos());
        int row_end = Position::getMatrixNumber(p_rand.second.getRowPos());

        Case c_start = board->getCase(row_start,col_start);
        Case c_end = board->getCase(row_end,col_end);

        board->movePieceTo(p_rand.first,p_rand.second);
        		
        break;
    }
}