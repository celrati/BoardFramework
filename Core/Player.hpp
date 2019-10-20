#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "Board.hpp"
using namespace std;

class Player{
protected:
	string name_player;
	string color_player;
	int score_player;
	int state_player;
	//Player(){}
public:
	virtual string getName() const = 0;
	virtual string getColor() const = 0;
	virtual int getScore() const = 0;
	virtual int getState() const = 0;
	virtual void playMove(Board * board, string color_robot) = 0;
        virtual void playMove2(Board * board, string color_robot) = 0;
};

#endif