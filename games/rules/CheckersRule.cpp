#include "CheckersRule.hpp"
 #include "../../lib/StateDetector.hpp"
#include "../../pipe/OutputWriter.hpp"
#include "../../Core/Game.hpp"


bool CheckersRule::check(Position pos_start, Position pos_end, Board * board){
        
	int i_start = Position::getMatrixNumber(pos_start.getRowPos());
	int j_start = Position::getMatrixNumber(pos_start.getColPos());
        
	if(board->getCase(i_start,j_start).isEmpty()) return false;
        
        if(board->getCase(i_start,j_start).getPiece()->getName() == "Damier"){
            if(checkDamier(pos_start,pos_end,board->getCase(i_start,j_start),board)){
                return true;
            }else if(damierJump(pos_start,pos_end,board->getCase(i_start,j_start),board, 0)){
                return true;
            }else return false;
	}
	
        if(board->getCase(i_start,j_start).getPiece()->getName() == "DamierKing"){
            return checkDamierKing(pos_start,pos_end,board->getCase(i_start,j_start),board, 0);           
	}
        
	return false;
}

bool CheckersRule::checkAll(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board){
    if(pos_start == "do") return false; // to avoid errors

    int col_start = Position::getMatrixNumber(pos_start[0]);
    int row_start = Position::getMatrixNumber(pos_start[1]);

    int col_end = Position::getMatrixNumber(pos_end[0]);
    int row_end = Position::getMatrixNumber(pos_end[1]);
    if(check(Position(pos_start[0],pos_start[1]),Position(pos_end[0],pos_end[1]),board)){
        if(board->getCase(row_start,col_start).getPiece()->getColor() == colorPlayer){ // to check the color	
            board->movePieceTo(Position(pos_start[0],pos_start[1]),Position(pos_end[0],pos_end[1]));
            board->setNotification2("-------");
            doIfPromoteDamier(colorPlayer,pos_start,pos_end,game,board);
            game->saveMove(pos_start[0],pos_start[1],pos_end[0],pos_end[1]);
            board->setNotification("Good Move");
            OutputWriter::writeToFileNotification("GOOD MOVE ! !");
            if(canStillPlay(Position(pos_end[0],pos_end[1]),board->getCase(row_end,col_end),board)){
                board->setNotification("You still have another play to make");
                return false;
            }else{
                return true;
            }
        }else{
            // errors or exception --
            board->setNotification("Wrong Move Not Your Piece");
            OutputWriter::writeToFileNotification("WRONG MOVE NOT YOUR PIECE ! ");
            cout<<"not the right piece --"<<endl;
        }
    }else{
        // errors or exception --
        board->setNotification("WRONG MOVE RESPECT THE RULES !  ");
        OutputWriter::writeToFileNotification("WRONG MOVE RESPECT THE RULES !  ");
    }
    return false;
}

bool CheckersRule::damierJump(Position pos_start, Position pos_end, Case case_piece, Board * board, int mode){
    int i_end = Position::getMatrixNumber(pos_end.getRowPos());
    int j_end = Position::getMatrixNumber(pos_end.getColPos());

    int i_start = Position::getMatrixNumber(pos_start.getRowPos());
    int j_start = Position::getMatrixNumber(pos_start.getColPos());
    
    string color_damier = case_piece.getPiece()->getColor();
    
    if(board->getCase(i_end, j_end).isEmpty()){
        if((i_start + 2 == i_end && j_start - 2 == j_end)){
            if(board->getCase(i_start + 1, j_start - 1).isEmpty()){
                return false;
            }else{
                if(color_damier != board->getCase(i_start+1, j_start-1).getPiece()->getColor()){
                    cout<<"++++1"<<endl;
                    if(mode == 0) board->freeCase(i_start + 1, j_start - 1);
                    return true;
                }
                return false;
            }
        }else if((i_start - 2 == i_end && j_start - 2 == j_end)){
            if(board->getCase(i_start - 1, j_start - 1).isEmpty()){
                return false;
            }else{
                if(color_damier != board->getCase(i_start-1, j_start-1).getPiece()->getColor()){
                    cout<<"++++2"<<endl;
                    if(mode == 0) board->freeCase(i_start - 1, j_start - 1);
                    return true;
                }
                return false;
            }
        }else if((i_start - 2 == i_end && j_start + 2 == j_end)){ 
            if(board->getCase(i_start - 1, j_start + 1).isEmpty()){
                return false;
            }else{
                if(color_damier != board->getCase(i_start-1, j_start+1).getPiece()->getColor()){
                    cout<<"++++3"<<endl;
                    if(mode == 0) board->freeCase(i_start - 1, j_start + 1);
                    return true;
                }
                return false;
            }
        }else if((i_start + 2 == i_end && j_start + 2 == j_end)){
            if(board->getCase(i_start + 1, j_start + 1).isEmpty()){
                return false;
            }else{
                if(color_damier != board->getCase(i_start+1, j_start+1).getPiece()->getColor()){
                    cout<<"++++4"<<endl;
                    if(mode == 0) board->freeCase(i_start + 1, j_start + 1);
                    return true;
                }
                return false;
            }
        }
    }
     
    return false;
}


bool CheckersRule::checkDamier(Position pos_start, Position pos_end, Case case_piece, Board * board){
    int i_end = Position::getMatrixNumber(pos_end.getRowPos());
    int j_end = Position::getMatrixNumber(pos_end.getColPos());

    int i_start = Position::getMatrixNumber(pos_start.getRowPos());
    int j_start = Position::getMatrixNumber(pos_start.getColPos());

    string color_damier = case_piece.getPiece()->getColor();
    if(color_damier == WHITE){//ColPos=abcdef Rowpos=12345
        if(board->getCase(i_end, j_end).isEmpty()){
            if((i_start - 1 == i_end && j_start + 1 == j_end)||(i_start - 1 == i_end && j_start - 1 == j_end)){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
        
    }else{//BLACK
        if(board->getCase(i_end, j_end).isEmpty()){
            if((i_start + 1 == i_end && j_start + 1 == j_end)||(i_start + 1 == i_end && j_start - 1 == j_end)){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        } 
    }
    return false;
}

bool CheckersRule::checkDamierKing(Position pos_start, Position pos_end, Case case_piece,Board * board, int mode){
    int i_end = Position::getMatrixNumber(pos_end.getRowPos());
    int j_end = Position::getMatrixNumber(pos_end.getColPos());

    int i_start = Position::getMatrixNumber(pos_start.getRowPos());
    int j_start = Position::getMatrixNumber(pos_start.getColPos());
    string color_damierking = case_piece.getPiece()->getColor();
    // check if the mouvement is diag
    int mouv_x = fabs(j_end - j_start);
    int mouv_y = fabs(i_end - i_start);
    int err = 0;
    
    if(mouv_y == mouv_x && mouv_y != 0){	// detect the diago 
        if(pos_end.getRowPos() > pos_start.getRowPos() &&
            pos_end.getColPos() > pos_start.getColPos() ){ // UP RIGHT

            int i = i_start - 1;
            for(int j = j_start + 1 ; j < j_end ; j++){
                if(!board->getCase(i,j).isEmpty()) err++;
                i--;
            }
            if(err > 1) return false;
            i = i_start - 1;
            for(int j = j_start + 1 ; j < j_end ; j++){
                if(!board->getCase(i,j).isEmpty()){
                    for(int k = 1; k < 8; k++){
                        if((i - k == i_end) && (j + k == j_end) && board->getCase(i-k,j+k).isEmpty()){
                            if(color_damierking != board->getCase(i, j).getPiece()->getColor()){
                                if(mode == 0) board->freeCase(i,j);
                                return true;
                            }
                        }
                    }
                    return false;
                }
                i--;
            }
            if(board->getCase(i_end,j_end).isEmpty()) return true;	
            return false;
        }
        if(pos_end.getRowPos() > pos_start.getRowPos() &&
            pos_end.getColPos() < pos_start.getColPos() ){ // UP LEFT

            int i = i_end + 1;
            for(int j = j_end + 1 ; j < j_start ; j++){
                if(!board->getCase(i,j).isEmpty()) err++;
                i++;
            }
            if(err > 1) return false;
            i = i_end + 1;
            for(int j = j_end + 1 ; j < j_start ; j++){
                if(!board->getCase(i,j).isEmpty()){
                    for(int k = 1; k < 8; k++){
                        if((i - k == i_end) && (j - k == j_end) && board->getCase(i-k,j-k).isEmpty()){
                            if(color_damierking != board->getCase(i, j).getPiece()->getColor()){
                                if(mode == 0) board->freeCase(i,j);
                                return true;
                            }
                        }
                    }
                    return false;
                }
                i++;
            }			
            if(board->getCase(i_end,j_end).isEmpty()) return true;
            return false;
        }
        if(pos_end.getRowPos() < pos_start.getRowPos() &&
            pos_end.getColPos() > pos_start.getColPos()){  // DOWN RIGHT

            int i = i_start +  1;
            for(int j = j_start + 1 ; j < j_end ; j++){
                if(!board->getCase(i,j).isEmpty()) err++;
                i++;
            }
            if(err > 1) return false;
            i = i_start +  1;
            for(int j = j_start + 1 ; j < j_end ; j++){
                if(!board->getCase(i,j).isEmpty()){
                    for(int k = 1; k < 8; k++){
                        if((i + k == i_end) && (j + k == j_end) && board->getCase(i+k,j+k).isEmpty()){
                            if(color_damierking != board->getCase(i, j).getPiece()->getColor()){
                                if(mode == 0) board->freeCase(i,j);
                                return true;
                            }
                        }
                    }
                    return false;
                }
                i++;
            }
            if(board->getCase(i_end,j_end).isEmpty()) return true;
            return false;
        }
        if(pos_end.getRowPos() < pos_start.getRowPos() &&
            pos_end.getColPos() < pos_start.getColPos()){  // DOWN LEFT

            int i = i_end - 1;
            for(int j = j_end + 1 ; j < j_start ; j++){
                if(!board->getCase(i,j).isEmpty()) err++;
                i--;
            }
            if(err > 1) return false;
            i = i_end - 1;
            for(int j = j_end + 1 ; j < j_start ; j++){
                if(!board->getCase(i,j).isEmpty()){
                    for(int k = 1; k < 8; k++){
                        if((i + k == i_end) && (j - k == j_end) && board->getCase(i+k,j-k).isEmpty()){
                            if(color_damierking != board->getCase(i, j).getPiece()->getColor()){
                                if(mode == 0) board->freeCase(i,j);
                                return true;
                            }
                        }
                    }
                    return false;
                }
                i--;
            }		

            if(board->getCase(i_end,j_end).isEmpty()) return true;
            return false;
        }
    }

    return false;
}

void CheckersRule::doIfPromoteDamier(string colorPlayer,string pos_start, string pos_end, Game * game,Board * board){
    int row_start = Position::getMatrixNumber(pos_start[1]);

    int col_end = Position::getMatrixNumber(pos_end[0]);
    int row_end = Position::getMatrixNumber(pos_end[1]);

    int i_end = row_end; int j_end = col_end;

    int i_start = row_start;

    Case c_end = board->getCase(row_end,col_end);
    if(colorPlayer == WHITE && c_end.getPiece()->getName() == "Damier"){
        if(i_end == 0 && (i_start == 1 || i_start == 2)){
            Case * c = new Case();
            c->setColor(board->getCase(i_end, j_end).getColor());
            board->setNotification("Congratulations white player, your Pawn just been promoted to a KingPawn!\n");
            c->setPiece(PieceFactory::newPiece("Mw"));

            board->setCase(i_end,j_end,*c);
        }
    }else if(colorPlayer == BLACK && c_end.getPiece()->getName() == "Damier" ){ // BLACK PLAYER
        if(i_end == 7 && (i_start == 6 || i_start == 5)){
            Case * c = new Case();
            c->setColor(board->getCase(i_end, j_end).getColor());
            board->setNotification("Congratulations black player, your Pawn just been promoted to a KingPawn!\n");
            
            c->setPiece(PieceFactory::newPiece("Mb"));

            board->setCase(i_end,j_end,*c);				
        }
    }
}

bool CheckersRule::canStillPlay(Position pos_start, Case case_piece,Board * board){
    
    int i_start = Position::getMatrixNumber(pos_start.getRowPos());
    int j_start = Position::getMatrixNumber(pos_start.getColPos());

    string color_damier = case_piece.getPiece()->getColor(); 
    if(i_start - 1 <= 0 || i_start + 1 >= 8 || j_start - 1 <= 0 || j_start + 1 >= 8){
        return false;
    }else{
        if(!board->getCase(i_start - 1, j_start + 1).isEmpty()){ //TOP RIGHT
            if(board->getCase(i_start - 2, j_start + 2).isEmpty() 
                && color_damier != board->getCase(i_start - 1, j_start + 1).getPiece()->getColor()){
                if(i_start - 2 <= 0 || j_start + 2 >= 8) return false;
                else return true;
            }
        }else if(!board->getCase(i_start - 1, j_start - 1).isEmpty()){ //TOP LEFT
            if(board->getCase(i_start - 2, j_start - 2).isEmpty() 
                && color_damier != board->getCase(i_start - 1, j_start - 1).getPiece()->getColor()){
                if(i_start - 2 <= 0 || j_start - 2 <= 0) return false;
                else return true;
            }
        }else if(!board->getCase(i_start + 1, j_start - 1).isEmpty()){ //BOT LEFT
            if(board->getCase(i_start + 2, j_start - 2).isEmpty()
                && color_damier != board->getCase(i_start + 1, j_start - 1).getPiece()->getColor()){
                if(i_start + 2 >= 8 || j_start - 2 <= 0) return false;
                else return true;
            }
        }else if(!board->getCase(i_start + 1, j_start + 1).isEmpty()){ //BOT RIGHT
            if(board->getCase(i_start + 2, j_start + 2).isEmpty()
                && color_damier != board->getCase(i_start + 1, j_start + 1).getPiece()->getColor()){
                if(i_start + 2 >= 8 || j_start + 2 >= 8) return false;
                else return true;
            }
        }   
    }
    return false;
    
}