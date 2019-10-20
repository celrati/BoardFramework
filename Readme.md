/**
*    Framework BoardGames v0.304
*     to create new board games 
*		by Charif Achraf && Oussama aouessar
*/


------------------------------------------------------
// how to play ---
e1 e3  : move the piece in case e1 to case e3
do o-o : castle king side
do o-o-o : castle queen side
do restart   :  restart the game
do abort     :  abort the game
do save
------------------------------------------------------





-- how to create a game:
1 - create your pieces inside the Pieces folder
2 - add conditions to the PieceFactory inside Pieces/PieceFactory just do the same as the others pieces
	and just change the twochar that will represent your pieces
3 - add the #include of your pieces class inside the Pieces/PieceFactory !! important
4 - implement your board inside the games/boards folder just respect the same architecure as the ChessBoard !
5 - implement your game inside the games/boards folder just respect the same architecture as the ChessGame !
6 - think of create new method  "writeToFileChecker" inside the pipe/OutpurWriter.hpp and use it for your classes

7 - implement your rule inside the games/rule folder just respect the same architecture as the ChessRule !
    you must implements the check and checkAll methods of your ruler soo the imputReader can use them perfectly
8 - inside the files think of create initBoardChecker and use it to init your board inside your Board
9 - CheckerGame::launchGame(); implements this method inside your game and use it in the router 
10 - to test the game just uncomment the Router::get("chckerGame"); and comment the others 
11 - for the interface you will find everything inside the Graphics folder 
		create new folder CheckerChessGraphics inside the Graphics and code the script in python 
		to test it python start.py

12 - dont touch The StateDetector, you dont need it for checker
