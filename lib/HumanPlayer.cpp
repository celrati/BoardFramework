#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer(string name, string color,int score){
	this->name_player = name;
	this->color_player = color;
	this->score_player =score;
	this->state_player = PLAYER_CREATED;
}
string HumanPlayer::getName() const{
	return this->name_player;
}
string HumanPlayer::getColor() const{
	return this->color_player;
}
int HumanPlayer::getScore() const{
	return this->score_player;
}
int HumanPlayer::getState() const{
	return this->state_player;
}
void HumanPlayer::setName(string name){
	this->name_player = name;
}
void HumanPlayer::setColor(string color){
	this->color_player = color;
}
void HumanPlayer::setScore(int score){
	this->score_player = score;
}
void HumanPlayer::setState(int state){
	this->state_player = state;
}
void HumanPlayer::playMove(Board * board, string color_robot){
	// empty
}
void HumanPlayer::playMove2(Board * board, string color_robot){
	// empty
}
