#ifndef CHECKERSB_HPP
#define CHECKERSB_HPP

#include "../../Core/Board.hpp"
#include <utility>
#include <vector>
#include "../../Pieces/PieceFactory/PieceFactory.hpp"

using namespace std;

class CheckersBoard: public Board{
private:
	Case cases[SIZE_BOARD_DAME][SIZE_BOARD_DAME];
	string notification_to_show;
	string notification_to_show2;
public:
	
	CheckersBoard(int flag); // a flag to init or ... the board
	void initBoardColor();
	friend ostream & operator<<(ostream & os, const CheckersBoard & checkersBoard);

	void movePieceTo(Position start_pos, Position end_pos); // dump move we no rules --
	Case  getCase(int row,int col);
	void setCase(int row, int col, Case c);
	pair<int, int>  getCase(string color_piece, string name_piece);
	void printBoard();
	void setNotification(string notif);
	void setNotification2(string notif);
	string getListPossibleMoves(string color_player);
	vector< pair<Position,Position> > getListPossibleMovesVector(string color_player);
	virtual void restartBoard();
        virtual void freeCase(int row, int col);
};

#endif