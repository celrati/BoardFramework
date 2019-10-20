#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <iostream>
#include "games/ChessGame.hpp"
#include "games/ShatranjGame.hpp"
#include "games/CheckersGame.hpp"
#include "games/DunsanyChessGame.hpp"

/**
*     router v0.01 for the framework
*
*
**/

class Router{
public:
	static void get( string game){


if( game == "chessGame"){
	ChessGame::launchGame();
	return;
}

if( game == "shatranjGame"){
	ShatranjGame::launchGame();
	return;
}

if( game == "checkersGame"){
	CheckersGame::launchGame();
	return;
}

if( game == "dunsanyChessGame"){
	DunsanyChessGame::launchGame();
	return;
}


}


private:
	Router(){}

};


#endif