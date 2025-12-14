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

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
   srand(time(NULL));
   char board[8][8];
   initposition(board);
   printBoard(board);
   while(!endgame(board)){
   movement(board);}

    return 0;
}
