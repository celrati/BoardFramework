#ifndef MR_ROBOT
#define MR_ROBOT

#include "../Core/Player.hpp"
#include "../Core/Board.hpp"

using namespace std;

class MrRobot : public Player{
public:
	MrRobot(string name, string color,int score);
	virtual string getName() const;
	virtual string getColor() const;
	virtual int getScore() const;
	virtual int getState() const;
	virtual void playMove(Board * board, string color_robot);
        virtual void playMove2(Board * board, string color_robot);
};


#endif