#include <iostream>
#include "router.hpp"

using namespace std;


int main(){
        cout<<"+--------------------------------------------------+"<<endl;
        cout<<"|         WELCOME TO THE BOARD GAME MAKER          |"<<endl;
        cout<<"| you can create any board game in less than 30min |"<<endl;
        cout<<"| all you have to do is code the rules add pieces  |"<<endl;
        cout<<"|     design your board and you are good to go     |"<<endl;
        cout<<"+--------------------------------------------------+"<<endl;
        
        while(true){
            cout<<"You can alrady start playing some pre-made games, Enjoy..."<<endl;
            cout<<"Choose a number to play: "<<endl;
            cout<<"1- Chess"<<endl;
            cout<<"2- Shatranj"<<endl;
            cout<<"3- Checkers"<<endl;
            cout<<"4- Dunsany Chess"<<endl;
            cout<<"5- exit"<<endl;

            int s;
            while(true){
                cin>>s;
                if(s <= 0 || s > 5){
                    cout<<"Choose a correct number !"<<endl;
                    continue;
                }	
                break;
            }


            if(s == 1) Router::get("chessGame");
            else if(s == 2) Router::get("shatranjGame");
            else if(s == 3) Router::get("checkersGame");
            else if(s == 4) Router::get("dunsanyChessGame");
            else if(s == 5){
                cout<<"BYE, See you soon ! \n---- Programe ended ! ----"<<endl;
                break;
            }
	
        }
	return 0;
	
}