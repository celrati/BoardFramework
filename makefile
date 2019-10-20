CC=g++
VERSION= -std=c++11
OPTION= -Wall

all: run

run: main.o games/rules/ShatranjRule.o games/ShatranjGame.o games/boards/ShatranjBoard.o  Core/Case.o  lib/Position.o  games/boards/ChessBoard.o games/ChessGame.o lib/HumanPlayer.o games/rules/ChessRule.o lib/StateDetector.o lib/MrRobot.o games/rules/CheckersRule.o games/CheckersGame.o games/boards/CheckersBoard.o games/rules/DunsanyChessRule.o games/DunsanyChessGame.o games/boards/DunsanyChessBoard.o
	clear
	$(CC) $(VERSION) $(OPTION) -o $@ $^

%.o:%.c
	$(CC) $(VERSION) $(OPTION) -c $<

clean: 
	rm -R *.o run