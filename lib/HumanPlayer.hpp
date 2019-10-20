#ifndef HUMAN_PLAYER_HPP
#define HUMAN_PLAYER_HPP

#include <iostream>
using namespace std;
#include "../Core/Player.hpp"
#include "ShortCutUtil.hpp"

class HumanPlayer : public Player{

public:
	HumanPlayer(string name, string color,int score);
	virtual string getName() const;
	virtual string getColor() const;
	virtual int getScore() const;
	virtual int getState() const;

	void setName(string name);
	void setColor(string color);
	void setScore(int score);
	void setState(int state);

	virtual void playMove(Board * board, string color_robot);
        virtual void playMove2(Board * board, string color_robot);
};



#endif