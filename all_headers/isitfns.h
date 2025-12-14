int isvalidmove(char board[8][8], char c1, int r1, char c2, int r2, int skip);
int ispathclear(char board[8][8], int destrow, int destcol, int startrow, int startcol);
int iswhite(char piece);
int isblack(char piece);
int isempty(char place);
int ispromotion(char board[8][8], char c1, int r1, char c2, int r2);
int ispromotionvalid(char board[8][8],char promotionpiece , int  startrow, int startcol);