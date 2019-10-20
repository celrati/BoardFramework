#ifndef OUTPUT_WRITER_HPP
#define OUTPUT_WRITER_HPP

#include <fstream>
#include <iostream>
#include "../lib/ShortCutUtil.hpp"
#include "../Core/Board.hpp"
#include "../games/boards/ChessBoard.hpp"
#include "../games/boards/ShatranjBoard.hpp"
#include "../games/boards/CheckersBoard.hpp"
#include "../games/boards/DunsanyChessBoard.hpp"

using namespace std;

class OutputWriter{
	// static class just to print the board on a separated file
private:
	OutputWriter(); // private construct we dont use it --
public:


	/**
	**   add new methods for the output for other boards --
	**
	**/

	static void writeToFileChess(ChessBoard * board){
		string file = "Graphics/dataBoard.oc";  // the format oc it means oussama/achraf
		ofstream outputFile;
		outputFile.open(file);	
		outputFile<<*board;		
	}
	static void writeToFileChess(ShatranjBoard * board){
		string file = "Graphics/dataBoard.oc";  // the format oc it means oussama/achraf
		ofstream outputFile;
		outputFile.open(file);	
		outputFile<<*board;		
	}
        static void writeToFileChess(DunsanyChessBoard * board){
		string file = "Graphics/dataBoard.oc";  // the format oc it means oussama/achraf
		ofstream outputFile;
		outputFile.open(file);	
		outputFile<<*board;		
	}
        static void writeToFileCheckers(CheckersBoard * board){
		string file = "Graphics/dataBoardC.oc";  // the format oc it means oussama/achraf
		ofstream outputFile;
		outputFile.open(file);	
		outputFile<<*board;		
	}

	static void writeToFileNotification(string notification){
		string file = "Graphics/dataNotif.oc";  // the format oc it means oussama/achraf
		ofstream outputFile;
		outputFile.open(file);		
		outputFile<<notification<<endl;
		
	}
};




#endif