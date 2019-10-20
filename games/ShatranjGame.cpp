#include "ShatranjGame.hpp"
#include "../lib/HumanPlayer.hpp"
#include "../lib/MrRobot.hpp"
#include "../pipe/OutputWriter.hpp"
#include "../lib/StateDetector.hpp"
#include <fstream>
#include <string.h>

using namespace std;

ShatranjGame::ShatranjGame(int mode){
	switch(mode){
		case VS_1_PLAYER:	
			this->shatranjBoard = new ShatranjBoard(BOARD_INIT);
			this->state_game = GAME_START;
			this->player_1 = new HumanPlayer("human",WHITE,0);
			this->player_2 = new HumanPlayer("human",BLACK,0);
			this->turn_player = TURN_PLAYER_1; // white always start --
			this->inputReader = new InputReader<ShatranjBoard,ShatranjRule>(shatranjBoard, new ShatranjRule());
			break;
		case VS_1_MACHINE:
			this->shatranjBoard = new ShatranjBoard(BOARD_INIT);
			this->state_game = GAME_START;	
			this->player_1 = new HumanPlayer("human",WHITE,0);
			this->player_2 = new MrRobot("eliot",BLACK,0);	
			this->turn_player = TURN_PLAYER_1;	
			this->inputReader = new InputReader<ShatranjBoard,ShatranjRule>(shatranjBoard, new ShatranjRule());
			
			// later --
			break;
		case VS_1_PLAYER_FILE:
			this->shatranjBoard = new ShatranjBoard(BOARD_INIT);
			this->state_game = GAME_START;
			this->player_1 = new HumanPlayer("human",WHITE,0);
			this->player_2 = new HumanPlayer("human",BLACK,0);
			this->inputReader = new InputReader<ShatranjBoard,ShatranjRule>(shatranjBoard, new ShatranjRule());		
			this->gameLoad();
			break;
	}
}
void ShatranjGame::gameStart(){
	this->state_game = GAME_PLAY;

	while( this->state_game == GAME_PLAY ){
		// print > file 


			
		if(StateDetector::checkMate_shatranj(shatranjBoard) == CHECK_MATE_TO_BLACK){
			shatranjBoard->setNotification("CHECK MATE !! WHITE IS THE WINNER ");
			OutputWriter::writeToFileNotification("CHECK MATE !! WHITE IS THE WINNER ");
			gameOver();
			OutputWriter::writeToFileChess(shatranjBoard);
			printBoard(); // for the last time
			continue;
		}

		
		if(StateDetector::checkMate_shatranj(shatranjBoard) == CHECK_MATE_TO_WHITE){
			shatranjBoard->setNotification("CHECK MATE !! BLACK IS THE WINNER ");
			OutputWriter::writeToFileNotification("CHECK MATE !! BLACK IS THE WINNER ");
			gameOver();
			OutputWriter::writeToFileChess(shatranjBoard);
			printBoard(); // for the last time
			continue;
		}

		
		shatranjBoard->setNotification2("To help you here's the moves that you could play : \n"+
			shatranjBoard->getListPossibleMoves(WHITE));
		printBoard(); // print the chessBoard
		OutputWriter::writeToFileChess(shatranjBoard);


			if(this->turn_player == TURN_PLAYER_1){		
		shatranjBoard->setNotification2("To help you here's the moves that you could play : \n"+
			shatranjBoard->getListPossibleMoves(WHITE));
		printBoard(); // print the chessBoard
				cout<<"player white turn :"<<endl;
	
				// check if the player move a white piece -- 
				if( inputReader->read(WHITE,this)){
					this->turn_player = TURN_PLAYER_2;
				}

			}else if(this->turn_player == TURN_PLAYER_2){

					if(this->player_2->getName() == "human"){
					shatranjBoard->setNotification2("To help you here's the moves that you could play : \n"+
					shatranjBoard->getListPossibleMoves(BLACK));
				printBoard(); // print the chessBoard	
						cout<<"player black turn :"<<endl;

						if( inputReader->read(BLACK,this)){
							this->turn_player = TURN_PLAYER_1;
						}				
				}else{ // mr robot --
					// mr robot will play right now --
					player_2->playMove(shatranjBoard,BLACK);
					this->turn_player = TURN_PLAYER_1;
				}


			}



			if(StateDetector::isCheck_shatranj(shatranjBoard) == CHECK_TO_WHITE){
				// check to white
				shatranjBoard->setNotification("check to White player !! ");
				OutputWriter::writeToFileNotification("check to White player !! ");
			}
			if(StateDetector::isCheck_shatranj(shatranjBoard) == CHECK_TO_BLACK){
				// check to black
				OutputWriter::writeToFileNotification("check to White player !! ");
			}


				
		}
		
}
void ShatranjGame::gamePause(){
	this->state_game = GAME_PAUSE;
}
void ShatranjGame::gameStop(){
	this->state_game = GAME_STOP;
	cout<<string( 100, '\n' );
	cout<<"Good Game !!"<<endl;
}
void ShatranjGame::gameOver(){
	this->state_game = GAME_OVER;
	cout<<string( 100, '\n' );
	cout<<"GAme OVER !!"<<endl;
}


void ShatranjGame::printBoard(){
	cout<<string( 100, '\n' );
	//cout<<*(this->chessBoard);
	this->shatranjBoard->printBoard();
}

void ShatranjGame::gameRestart(){
	if(this->player_2->getName() == "human"){
		this->shatranjBoard = new ShatranjBoard(BOARD_INIT);
		this->player_1 = new HumanPlayer("human",WHITE,0);
		this->player_2 = new HumanPlayer("human",BLACK,0);
			this->turn_player = TURN_PLAYER_1; // white always start --
			this->inputReader = new InputReader<ShatranjBoard,ShatranjRule>(shatranjBoard, new ShatranjRule());
		}else{
			this->shatranjBoard = new ShatranjBoard(BOARD_INIT);
			this->player_1 = new HumanPlayer("human",WHITE,0);
			this->player_2 = new MrRobot("lain",BLACK,0);	
			this->turn_player = TURN_PLAYER_1;	
			this->inputReader = new InputReader<ShatranjBoard,ShatranjRule>(shatranjBoard, new ShatranjRule());	
		}
	}

bool ShatranjGame::gameLoad(){ // load game between two human players --
	cout<<"Whats the name of the file in the directory files/    :"<<endl;
	string file; cin>>file;

	ifstream infile("files/"+file);
	if(infile){
		string move;
		this->turn_player = TURN_PLAYER_1;
		string color_player = WHITE;
		while(getline(infile,move)){
			string pos_start = move.substr(0, 2);
			string pos_end = move.substr(3, 2);
			if(this->turn_player == TURN_PLAYER_1) this->turn_player = TURN_PLAYER_2;
			else if(this->turn_player == TURN_PLAYER_2) this->turn_player = TURN_PLAYER_1;
			this->inputReader->play(color_player,pos_start,pos_end,this);
			if(color_player == WHITE) color_player = BLACK;
			else if(color_player == BLACK) color_player = WHITE;
		}

		infile.close();
		return true;
	}else{
		return false;
	}

}
bool ShatranjGame::gameSave(string name_file){
  ofstream myfile;
  myfile.open("files/"+name_file+".oc");
  for(int i = 0; i < moves_players_list.size() ;i++){
  	myfile<<moves_players_list[i].first.getColPos()<<moves_players_list[i].first.getRowPos();
  	myfile<<" ";
  	myfile<<moves_players_list[i].second.getColPos()<<moves_players_list[i].second.getRowPos();
  	myfile<<endl;
  }
  myfile.close();
}

void ShatranjGame::saveMove(char a, char b, char c, char d){
	this->moves_players_list.push_back(
		make_pair(Position(a,b),
				  Position(c,d))
		);
}
char ShatranjGame::getMaxColumn(){
	return 'h';
}
char ShatranjGame::getMaxRow(){
	return '8';
}


void ShatranjGame::launchGame(){
        cout<<"__________________________________________________"<<endl;
        cout<<"Welcome Dear Player : "<<endl;
        cout<<" #####  #    #    ##   ####### #####     ######   "<<endl;
        cout<<" #      #    #   #  #     #    #    #       #    "<<endl;
        cout<<"   #    ######  ######    #    ######       #    "<<endl;
        cout<<"     #  #    #  #    #    #    #     #  ##  #    "<<endl;
        cout<<" #####  #    #  #    #    #    #      #  ###      "<<endl;
        cout<<"__________________________________________________"<<endl;
        cout<<endl;
        cout<<endl;
	int c;
	while(1){
		cout<<"Shatranj game :  "<<endl;
		cout<<"1 - PLAYER vs PLAYER "<<endl;
		cout<<"2 - Player vs AI v.Mr Robot "<<endl;
		cout<<"3 - Load Game (list of moves) "<<endl;
		cout<<" Please choose a number : "<<endl;
		cin>>c;
		if(c <= 0 || c >3 ){
			cout<<"ERROR repeat !"<<endl;
			continue;
		}	
		break;	
	}

	if(c == 1){
		ShatranjGame shatranjGame1(VS_1_PLAYER);
		shatranjGame1.gameStart();		
	}
	if(c == 2){
		ShatranjGame shatranjGame2(VS_1_MACHINE);
		shatranjGame2.gameStart();	
	}
	if(c == 3){
		ShatranjGame shatranjGame2(VS_1_PLAYER_FILE);
		shatranjGame2.gameStart();	
	}	
}