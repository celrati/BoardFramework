#ifndef INPUT_R_HPP
#define INPUT_R_HPP

#include <iostream>
#include "OutputWriter.hpp"
#include "../Core/Game.hpp"
#include "../Pieces/PieceFactory/PieceFactory.hpp"

/*
* here a template class for processing the input
*  you have just to modify the read function() and code what you want --
*/	

template<typename T, typename S> class InputReader{
// T type of the board
// S type of the rule
private:
	T * board;
	S * rule;
public:
	template <typename A, typename B> InputReader(A * board, B * rule){
		this->board = board;
		this->rule = rule;
	}

	bool play(string colorPlayer,string pos_start, string pos_end, Game * game){
// processing the input handling the exceptions --

		//state game
		if(pos_start == "do" && pos_end == "restart"){
			game->gameRestart();
		}
		if(pos_start == "do" && pos_end == "abort"){
			game->gameStop();
		}
		if(pos_start == "do" && pos_end == "save"){
			string name_file;
			cout<<"whats the name of the new file ?"<<endl;
			cin>>name_file;
			game->gameSave(name_file);
			return false;
		}
		// change nothing here --

		// you have to change the checkAll function of the game ruler
		return rule->checkAll(colorPlayer,pos_start,pos_end,game,board);
	}


	bool read(string colorPlayer, Game * game){ // arg colorPlayer to check if the player want to move the right piece --
		// get the strings from the STDIN --
		string pos_start, pos_end;

			// dont change anything here --
		do{  
			cout<<"What's the move ? "<<endl;
			cin>>pos_start>>pos_end;

			if(pos_start == "do") break;

			if(pos_start.length() != 2 || pos_end.length() != 2) continue;

			if(pos_start[0] > game->getMaxColumn() || pos_start[0] < 'a') continue;
			if(pos_start[1] > game->getMaxRow() || pos_start[1] < '1') continue;

			if(pos_end[0] > game->getMaxColumn() || pos_end[0] < 'a') continue;
			if(pos_end[1] > game->getMaxRow() || pos_end[1] < '1') continue;
			break;

		}while(true);
		
		return play(colorPlayer,pos_start,pos_end,game);
	
	}
	

};

#endif