#include "ChessGame.hpp"
#include "../lib/HumanPlayer.hpp"
#include "../lib/MrRobot.hpp"
#include "../pipe/OutputWriter.hpp"
#include "../lib/StateDetector.hpp"
#include <fstream>
#include <string.h>

using namespace std;

ChessGame::ChessGame(int mode){
	switch(mode){
		case VS_1_PLAYER:	
			this->chessBoard = new ChessBoard(BOARD_INIT);
			this->state_game = GAME_START;
			this->player_1 = new HumanPlayer("human",WHITE,0);
			this->player_2 = new HumanPlayer("human",BLACK,0);
			this->turn_player = TURN_PLAYER_1; // white always start --
			this->inputReader = new InputReader<ChessBoard,ChessRule>(chessBoard, new ChessRule());
			break;
		case VS_1_MACHINE:
			this->chessBoard = new ChessBoard(BOARD_INIT);
			this->state_game = GAME_START;	
			this->player_1 = new HumanPlayer("human",WHITE,0);
			this->player_2 = new MrRobot("eliot",BLACK,0);	
			this->turn_player = TURN_PLAYER_1;	
			this->inputReader = new InputReader<ChessBoard,ChessRule>(chessBoard, new ChessRule());
			// later --
			break;
		case VS_1_PLAYER_FILE:
			this->chessBoard = new ChessBoard(BOARD_INIT);
			this->state_game = GAME_START;
			this->player_1 = new HumanPlayer("human",WHITE,0);
			this->player_2 = new HumanPlayer("human",BLACK,0);
			this->inputReader = new InputReader<ChessBoard,ChessRule>(chessBoard, new ChessRule());			
			this->gameLoad();
			break;
	}
}
void ChessGame::gameStart(){
	this->state_game = GAME_PLAY;

	while( this->state_game == GAME_PLAY ){
		// print > file 


			
		if(StateDetector::checkMate(chessBoard) == CHECK_MATE_TO_BLACK){
			chessBoard->setNotification("CHECK MATE !! WHITE IS THE WINNER ");
			OutputWriter::writeToFileNotification("CHECK MATE !! WHITE IS THE WINNER ");
			gameOver();
			OutputWriter::writeToFileChess(chessBoard);
			printBoard(); // for the last time
			continue;
		}

		
		if(StateDetector::checkMate(chessBoard) == CHECK_MATE_TO_WHITE){
			chessBoard->setNotification("CHECK MATE !! BLACK IS THE WINNER ");
			OutputWriter::writeToFileNotification("CHECK MATE !! BLACK IS THE WINNER ");
			gameOver();
			OutputWriter::writeToFileChess(chessBoard);
			printBoard(); // for the last time
			continue;
		}

		
		chessBoard->setNotification2("To help you here's the moves that you could play : \n"+
			chessBoard->getListPossibleMoves(WHITE));
		printBoard(); // print the chessBoard
		OutputWriter::writeToFileChess(chessBoard);


			if(this->turn_player == TURN_PLAYER_1){		
		chessBoard->setNotification2("To help you here's the moves that you could play : \n"+
			chessBoard->getListPossibleMoves(WHITE));
		printBoard(); // print the chessBoard
				cout<<"player white turn :"<<endl;
	
				// check if the player move a white piece -- 
				if( inputReader->read(WHITE,this)){
					this->turn_player = TURN_PLAYER_2;
				}

			}else if(this->turn_player == TURN_PLAYER_2){

					if(this->player_2->getName() == "human"){
					chessBoard->setNotification2("To help you here's the moves that you could play : \n"+
					chessBoard->getListPossibleMoves(BLACK));
				printBoard(); // print the chessBoard	
						cout<<"player black turn :"<<endl;

						if( inputReader->read(BLACK,this)){
							this->turn_player = TURN_PLAYER_1;
						}				
				}else{ // mr robot --
					// mr robot will play right now --
					player_2->playMove(chessBoard,BLACK);
					this->turn_player = TURN_PLAYER_1;
				}


			}



			if(StateDetector::isCheck(chessBoard) == CHECK_TO_WHITE){
				// check to white
				chessBoard->setNotification("check to White player !! ");
				OutputWriter::writeToFileNotification("check to White player !! ");
			}
			if(StateDetector::isCheck(chessBoard) == CHECK_TO_BLACK){
				// check to black
				OutputWriter::writeToFileNotification("check to White player !! ");
			}


				
		}
		
}
void ChessGame::gamePause(){
	this->state_game = GAME_PAUSE;
}
void ChessGame::gameStop(){
	this->state_game = GAME_STOP;
	cout<<string( 100, '\n' );
	cout<<"Good Game !!"<<endl;
}
void ChessGame::gameOver(){
	this->state_game = GAME_OVER;
	cout<<string( 100, '\n' );
	cout<<"GAme OVER !!"<<endl;
}


void ChessGame::printBoard(){
	cout<<string( 100, '\n' );
	//cout<<*(this->chessBoard);
	this->chessBoard->printBoard();
}

void ChessGame::gameRestart(){
	if(this->player_2->getName() == "human"){
		this->chessBoard = new ChessBoard(BOARD_INIT);
		this->player_1 = new HumanPlayer("human",WHITE,0);
		this->player_2 = new HumanPlayer("human",BLACK,0);
			this->turn_player = TURN_PLAYER_1; // white always start --
			this->inputReader = new InputReader<ChessBoard,ChessRule>(chessBoard, new ChessRule());
		}else{
			this->chessBoard = new ChessBoard(BOARD_INIT);
			this->player_1 = new HumanPlayer("human",WHITE,0);
			this->player_2 = new MrRobot("lain",BLACK,0);	
			this->turn_player = TURN_PLAYER_1;	
			this->inputReader = new InputReader<ChessBoard,ChessRule>(chessBoard, new ChessRule());	
		}
	}

bool ChessGame::gameLoad(){ // load game between two human players --
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
bool ChessGame::gameSave(string name_file){
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

void ChessGame::saveMove(char a, char b, char c, char d){
	this->moves_players_list.push_back(
		make_pair(Position(a,b),
				  Position(c,d))
		);
}
char ChessGame::getMaxColumn(){
	return 'h';
}
char ChessGame::getMaxRow(){
	return '8';
}


void ChessGame::launchGame(){
        cout<<"_____________________________________________"<<endl;
        cout<<"Welcome Dear Player : "<<endl;
        cout<<" #####   #  #   ####   ####  ####   "<<endl;
        cout<<"##       #  #   #      #     #    "<<endl;
        cout<<"##       ####   ####    ##    ##  "<<endl;
        cout<<" ##      #  #   #         #     #  "<<endl;
        cout<<"  ####   #  #   ####   ####  ###   "<<endl;
        cout<<"_____________________________________________"<<endl;
        cout<<endl;
        cout<<endl;
	int c;
	while(1){
		cout<<"Chess game :  "<<endl;
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
		ChessGame chessGame1(VS_1_PLAYER);
		chessGame1.gameStart();		
	}
	if(c == 2){
		ChessGame chessGame2(VS_1_MACHINE);
		chessGame2.gameStart();	
	}
	if(c == 3){
		ChessGame chessGame2(VS_1_PLAYER_FILE);
		chessGame2.gameStart();	
	}	
}