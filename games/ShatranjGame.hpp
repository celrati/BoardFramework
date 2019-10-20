#ifndef SHATRANJ_GAME_HPP
#define SHATRANJ_GAME_HPP

#include "../lib/ShortCutUtil.hpp"
#include "../Core/Game.hpp"
#include "boards/ShatranjBoard.hpp"
#include "../Core/Player.hpp"
#include "../pipe/InputReader.hpp"
#include "rules/ShatranjRule.hpp"
#include <vector>
#include <utility>
#include "../lib/Position.hpp"

class ShatranjGame : public Game{
private:
	//state_game --
	ShatranjBoard * shatranjBoard;
	Player * player_1;
	Player * player_2;
	int turn_player;
	InputReader<ShatranjBoard,ShatranjRule> * inputReader;
	vector< pair< Position, Position> >  moves_players_list;
public:
	ShatranjGame(int mode); // 1 vs 2 or vs machine
	virtual void gameStart();
	virtual void gamePause();
	virtual void gameStop();
	virtual void gameOver();

	virtual bool gameLoad();
	virtual bool gameSave(string name_file);

	virtual void gameRestart();
	virtual void printBoard();
	virtual void saveMove(char a, char b, char c, char d);

	virtual char getMaxColumn();
	virtual char getMaxRow();

	static void launchGame();
};



#endif