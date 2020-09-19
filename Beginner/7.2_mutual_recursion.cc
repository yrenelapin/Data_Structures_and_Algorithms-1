/* TIC TAC TOE

Recursions which include Multiple functions

It looks basically like 1st function calls other function recursively and that 2nd function calls this 1st function recursively.

Ex:
int func2(){
    func1();
}

int func1(){
    func2();
}

*/

#include <stdio.h>
#define SIZE 3
#define BLANK '_'
#define DRAW -1
#define LOSE 0

void print_board(char board[SIZE][SIZE]){
    int i ,j ;
    for (i=0 ;i<SIZE;i++){
        for (j=0 ;j<SIZE;j++){
            printf("%c\t",board[i][j]);}

        printf("\n");
    }
}

/*
Function returns 1 if it is a Win for Player. Otherwise returns 0.
*/
int isWin(char board[SIZE][SIZE] , char player){
    int i,j,count ;

    // Row wise checking
    for(i=0; i<SIZE; i++){
        count =0 ;
        for(j=0; j<SIZE; j++)
            if (board[i][j]== player) count++ ;


        // Returns 1 if the Player Wins !
        if (count ==3 ) return 1 ;
    }


    // Column wise checking
    for(i=0; i<SIZE; i++){
        count =0 ;
        for(j=0; j<SIZE; j++)
            if (board[j][i]== player) count++ ;
        // Returns 1 if the Player Wins !
        if (count ==3 ) return 1 ;
    }

    // Diagonal Checking 

    if  ( (board[0][0]== player) && (board[1][1]== player) && (board[2][2]== player) ) return 1;

    if  ( (board[0][2]== player) && (board[1][1]== player) && (board[2][0]== player) ) return 1;


    return 0 ;

} 

int xmove(char board[SIZE][SIZE]);

/*
The function returns a position in a board (1-9) if the o player will surely win from there. 
It returns DRAW(-1) if it is a draw from that position.
It returns LOSE(0) if it is a lose from that position no matter what.   
*/
int omove(char board[SIZE][SIZE]){
    int i, j ,success, outcome = LOSE , full =1;


    for(i=0; i<SIZE;i++){
        for(j=0 ; j<SIZE; j++ ){
            if(board[i][j] != BLANK) continue ;

            full =0 ;
            board[i][j] = 'o' ;

            if (isWin(board,'o')==1){board[i][j] = BLANK; return(i*3+j+1); }        //BASE CASE

            success = xmove(board);

            // It is a good move.
            if(success == LOSE){board[i][j] = BLANK; return(i*3+j+1); }

            if(success == DRAW) outcome = DRAW;

            // if success has a value from 1-9, It means oPlayer wins from that move, So we replace _ again
            board[i][j] = BLANK;


        }

    }
    // No places to put, Implies Draw
    if (full == 1) return DRAW;       // BASE CASE

    return outcome;


}




/*
The function returns a position in a board (1-9) if the x player will surely win from there. 
It returns DRAW(-1) if it is a draw from that position.
It returns LOSE(0) if it is a lose from that position no matter what.   
*/
int xmove(char board[SIZE][SIZE]){
    int i, j ,success, outcome = LOSE , full =1;


    for(i=0; i<SIZE;i++){
        for(j=0 ; j<SIZE; j++ ){
            if(board[i][j] != BLANK) continue ;

            full =0 ;
            board[i][j] = 'x' ;

            if (isWin(board,'x') == 1){board[i][j] = BLANK; return(i*3+j+1); }        //BASE CASE

            success = omove(board);

            // It is a good move.
            if(success == LOSE){board[i][j] = BLANK; return(i*3+j+1); }

            if(success == DRAW) outcome = DRAW;

            // if success has a value from 1-9, It means oPlayer wins from that move, So we replace _ again
            board[i][j] = BLANK;


        }

    }
    // No places to put, Implies Draw
    if (full == 1) return DRAW;                 // BASE CASE

    return outcome;
}


int main(){

    char board[SIZE][SIZE] = {
        {BLANK,BLANK,'x'},                  
        {BLANK,BLANK,BLANK},
        {'o',BLANK,BLANK},
    
    };

    print_board(board);
    printf("\n");

    // Assume we are player 'o'
    // Computer predicts the move for 'x'
    printf("Move for x player = %d\n",xmove(board));
}


/*
In each recursive step , No of BLANK entries are being decreased.
*/