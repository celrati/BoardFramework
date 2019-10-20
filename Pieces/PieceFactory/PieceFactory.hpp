#ifndef PIECE_FACTORY
#define PIECE_FACTORY


#include <iostream>
#include "../../Core/Piece.hpp"
#include "PieceList.hpp"


class PieceFactory{ 

  			/** 
  				class just for creating new pieces
				every time you add create new piece
				try to think of two chars to represent it
				and add it here with the others --
  			*/

private: 
	PieceFactory();      		// 	make impossible to construct --


public:

	static Piece * newPiece(string piece){

		if(	piece == "pb" )
			{ Piece * pawnBlack = new Pawn(BLACK); return pawnBlack; }

		if(	piece == "pw")
			{ Piece * pawnWhite = new Pawn(WHITE); return pawnWhite; }

		if(	piece == "rb")
			{ Piece * rookBlack = new Rook(BLACK); return rookBlack; }

		if(	piece == "rw")
			{ Piece * rookWhite = new Rook(WHITE); return rookWhite; }

		if(	piece == "kb")
			{ Piece * knightBlack = new Knight(BLACK); return knightBlack; }

		if(	piece == "kw")
			{ Piece * knightWhite = new Knight(WHITE); return knightWhite; }

		if(	piece == "bb")
			{ Piece * bishopBlack = new Bishop(BLACK); return bishopBlack; }

		if(	piece == "bw")
			{ Piece * bishopWhite = new Bishop(WHITE); return bishopWhite; }

		if(	piece == "qb")
			{ Piece * queenBlack = new Queen(BLACK); return queenBlack; }

		if(	piece == "qw")
			{ Piece * queenWhite = new Queen(WHITE); return queenWhite; }

		if(	piece == "Kb")
			{ Piece * kingBlack = new King(BLACK); return kingBlack; }

		if(	piece == "Kw")
			{ Piece * kingWhite = new King(WHITE); return kingWhite; }
                
                if(	piece == "Dw")
			{ Piece * damierWhite = new Damier(WHITE); return damierWhite; }
                
                if(	piece == "Db")
			{ Piece * damierBlack = new Damier(BLACK); return damierBlack; }
                
                if(	piece == "Mw")
			{ Piece * damierKingWhite = new DamierKing(WHITE); return damierKingWhite; }
                
                if(	piece == "Mb")
			{ Piece * damierKingBlack = new DamierKing(BLACK); return damierKingBlack; }

		if(	piece == "x") return NULL;

	}

};











#endif