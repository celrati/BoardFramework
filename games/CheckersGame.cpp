#include "CheckersGame.hpp"
#include "../lib/HumanPlayer.hpp"
#include "../lib/MrRobot.hpp"
#include "../pipe/OutputWriter.hpp"
#include "../lib/StateDetector.hpp"
#include <fstream>
#include <string.h>

using namespace std;

CheckersGame::CheckersGame(int mode){
    switch(mode){
        case VS_1_PLAYER:	
            this->checkersBoard = new CheckersBoard(BOARD_INIT);
            this->state_game = GAME_START;
            this->player_1 = new HumanPlayer("human",WHITE,0);
            this->player_2 = new HumanPlayer("human",BLACK,0);
            this->turn_player = TURN_PLAYER_1; // white always start --
            this->inputReader = new InputReader<CheckersBoard,CheckersRule>(checkersBoard, new CheckersRule());
            break;
        case VS_1_MACHINE:
            this->checkersBoard = new CheckersBoard(BOARD_INIT);
            this->state_game = GAME_START;	
            this->player_1 = new HumanPlayer("human",WHITE,0);
            this->player_2 = new MrRobot("eliot",BLACK,0);	
            this->turn_player = TURN_PLAYER_1;	
            this->inputReader = new InputReader<CheckersBoard,CheckersRule>(checkersBoard, new CheckersRule());
            // later --
            break;
        case VS_1_PLAYER_FILE:
            this->checkersBoard = new CheckersBoard(BOARD_INIT);
            this->state_game = GAME_START;
            this->player_1 = new HumanPlayer("human",WHITE,0);
            this->player_2 = new HumanPlayer("human",BLACK,0);
            this->inputReader = new InputReader<CheckersBoard,CheckersRule>(checkersBoard, new CheckersRule());			
            this->gameLoad();
            break;
    }
}

void CheckersGame::gameStart(){
    this->state_game = GAME_PLAY;
    while(this->state_game == GAME_PLAY ){
        if(StateDetector::gameEnd(checkersBoard) == WHITE_WIN){
            checkersBoard->setNotification("WHITE PLAYER IS THE WINNER !");
            OutputWriter::writeToFileNotification("WHITE IS THE WINNER !");
            gameOver();
            OutputWriter::writeToFileCheckers(checkersBoard);
            printBoard();
            continue;
        }else if(StateDetector::gameEnd(checkersBoard) == BLACK_WIN){
            checkersBoard->setNotification("BLACK PLAYER IS THE WINNER !");
            OutputWriter::writeToFileNotification("BLACK IS THE WINNER !");
            gameOver();
            OutputWriter::writeToFileCheckers(checkersBoard);
            printBoard();
            continue;
        }
        
        if(this->turn_player == TURN_PLAYER_1){		
            checkersBoard->setNotification2("To help you here's some moves that you can play : \n"+
                    checkersBoard->getListPossibleMoves(WHITE));
            OutputWriter::writeToFileCheckers(checkersBoard);
            printBoard();
            cout<<"player white turn :"<<endl;

            // check if the player move a white piece -- 
            if(inputReader->read(WHITE, this)){
                this->turn_player = TURN_PLAYER_2;
            }
        }else if(this->turn_player == TURN_PLAYER_2){
            if(this->player_2->getName() == "human"){
                checkersBoard->setNotification2("To help you here's some moves that you can play : \n"+
                        checkersBoard->getListPossibleMoves(BLACK));
                OutputWriter::writeToFileCheckers(checkersBoard);
                printBoard();
                cout<<"player black turn :"<<endl;

                if(inputReader->read(BLACK, this)){
                    this->turn_player = TURN_PLAYER_1;
                }				
            }else{ // mr robot --
                // mr robot will play right now --
                player_2->playMove2(checkersBoard, BLACK);
                this->turn_player = TURN_PLAYER_1;
            }
        }
    }
    cout<<"------ Game Ended ------\n"<<endl;
}

void CheckersGame::gamePause(){
    this->state_game = GAME_PAUSE;
}

void CheckersGame::gameStop(){
    this->state_game = GAME_STOP;
    cout<<string( 100, '\n' );
    cout<<"Good Game !!"<<endl;
}

void CheckersGame::gameOver(){
    this->state_game = GAME_OVER;
    cout<<string( 100, '\n' );
    cout<<"Game OVER !!"<<endl;
}

void CheckersGame::printBoard(){
    cout<<string( 100, '\n' );
    this->checkersBoard->printBoard();
}

void CheckersGame::gameRestart(){
    if(this->player_2->getName() == "human"){
        this->checkersBoard = new CheckersBoard(BOARD_INIT);
        this->player_1 = new HumanPlayer("human",WHITE,0);
        this->player_2 = new HumanPlayer("human",BLACK,0);
            this->turn_player = TURN_PLAYER_1; // white always start --
            this->inputReader = new InputReader<CheckersBoard,CheckersRule>(checkersBoard, new CheckersRule());
        }else{
            this->checkersBoard = new CheckersBoard(BOARD_INIT);
            this->player_1 = new HumanPlayer("human",WHITE,0);
            this->player_2 = new MrRobot("lain",BLACK,0);	
            this->turn_player = TURN_PLAYER_1;	
            this->inputReader = new InputReader<CheckersBoard,CheckersRule>(checkersBoard, new CheckersRule());	
        }
    }

bool CheckersGame::gameLoad(){ // load game between two human players --
    cout<<"Whats the file's name in the directory files/    :"<<endl;
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
bool CheckersGame::gameSave(string name_file){
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

void CheckersGame::saveMove(char a, char b, char c, char d){
    this->moves_players_list.push_back(
            make_pair(Position(a,b), Position(c,d))
            );
}

char CheckersGame::getMaxColumn(){
    return 'h';
}

char CheckersGame::getMaxRow(){
    return '8';
}

void CheckersGame::launchGame(){
    cout<<"_________________________________"<<endl;
    cout<<"Welcome Dear Player : "<<endl;
    cout<<" #####     ###     #   #    #### "<<endl;
    cout<<" #    #   #   #   # # # #   #    "<<endl;
    cout<<" #     #  #####  #   #   #  #### "<<endl;
    cout<<" #    #   #   #  #       #  #    "<<endl;
    cout<<" #####    #   #  #       #  #### "<<endl;
    cout<<"_________________________________"<<endl;
    cout<<endl;
    cout<<endl;
    int c;
    while(1){
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
        CheckersGame checkersGame1(VS_1_PLAYER);
        checkersGame1.gameStart();	
    }
    if(c == 2){
        CheckersGame checkersGame2(VS_1_MACHINE);
        checkersGame2.gameStart();
    }
    if(c == 3){
        CheckersGame checkersGame2(VS_1_PLAYER_FILE);
        checkersGame2.gameStart();
    }
}