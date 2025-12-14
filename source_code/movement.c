#include "variables.h"
#include "criticalscenarios.h"
#include "isitfns.h"
#include "movement.h"
#include "renderfns.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <time.h>
#include "sidenotes.h"


void movement(char board[8][8]){
    if(check(board, movesplayed)){printf("Check!\n");}
    char c1, c2;
    int r1, r2;
      if(turn(movesplayed)==0){
       printf("White's move:");
    }
    else{
        printf("Black's move:");
    }
    fgets(inputmove, 80, stdin);
    if (strchr(inputmove, '\n') == NULL){clearinputbuffer();}
    cleaninput(inputmove);
    if(strlen(inputmove) != 4){printf("Move is invalid, please enter another move\n"); return;}
    c1 = inputmove[0];
    c2 = inputmove[2];
    r1 = inputmove[1] - '0';
    r2 = inputmove[3] - '0';    
    if(isvalidmove(board, c1, r1, c2, r2, 0)){
    int destcol = c2 - 'A';
    int destrow = 8 - r2;
    int startcol = c1 - 'A';
    int startrow = 8 - r1;
    int eatenpiece = board[destrow][destcol];
    char startpiece = board[startrow][startcol];
    board[destrow][destcol] = board[startrow][startcol];
    if(ispromotion(board, c1, r1, c2, r2)){
        while(1){
        printf("Promotion What would you like to upgrade to?\nbishop(B or b), knight(N or n), queen(Q or q), rook(R or r):");
         char inputprom[10];
         fgets(inputprom, 10, stdin);
         if (strchr(inputprom, '\n') == NULL){clearinputbuffer();}
         cleaninput(inputprom);
         promotionpiece = inputprom[0];
         if(turn(movesplayed) == 0){promotionpiece = tolower(promotionpiece);}
         else if(turn(movesplayed) == 1){promotionpiece = toupper(promotionpiece);}
         if(!ispromotionvalid(board, promotionpiece, startrow, startcol)){
        printf("Promotion invalid please enter another one\n");}
        else{board[destrow][destcol] = promotionpiece;
        break;}  
}}
    if(check(board, movesplayed)){
        printf("Illegal move it puts your king in check\n");
        board[startrow][startcol] = startpiece;
        board[destrow][destcol] = eatenpiece;
        return;
    }
    if((startcol+startrow)%2){
        board[startrow][startcol] = '.';
    }
    else{
        board[startrow][startcol] = '-';
    }
    if(eatenpiece != '-' && eatenpiece != '.'){eatenpieces(eatenpiece);}
    printBoard(board);
    movesplayed++;
    }
    else{
        printf("Move is invalid, please enter another move\n");
    }
}


void clearinputbuffer(){
    int c;
    while(( c = getchar()) != '\n' && c != EOF){}
}


void cleaninput(char* input){
    int j = 0;
    for(int i = 0; input[i] != '\0' ; i++){
     if(input[i] != ' ' && input[i] != '\n'){
   input[j] = toupper(input[i]);
   j++;}
}
input[j] = '\0';
}


int turn(int movesplayed){
    if(movesplayed%2==0){
        return 0;
    }
    else if(movesplayed%2==1){
        return 1;
    }
}