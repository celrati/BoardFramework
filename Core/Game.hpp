#ifndef GAME_HPP
#define GAME_HPP


#include <iostream>

using namespace std;

class Game{

protected:	

	int state_game;			 // PAUSE START STOP GAMEOVER --

public:


	virtual void gameStart() = 0;
	virtual void gamePause() = 0;
	virtual void gameStop() = 0;
	virtual void gameOver() = 0;

	virtual void gameRestart() = 0;

	virtual bool gameLoad() = 0;
	virtual bool gameSave(string name_file) = 0;

	virtual void printBoard() = 0;

	virtual void saveMove(char a, char b, char c, char d) = 0;


	// methods to get the caracteristics of the board
	virtual char getMaxColumn() = 0;
	virtual char getMaxRow() = 0;


};

#endif