/*
Mini Sudoku of size 4x4
_________
0 0 | 3 0 
2 0 | 0 0 
__________
0 3  | 2 4 
4 0  | 0 0 
__________
1. Each cell contains numbers 1 to 4.
2. No number is repeated in any row/column.
3. No number is repeated in any 2x2 group shown.
*/

#include <stdio.h>
#define SIZE 4
int count = 0;


/*
This function takes a Sudoku board and Three Integers i,j,k and checks whether placing board[i][j] = k will violate the rules of Sudoku or not.
*/
int notViolating(int board[SIZE][SIZE], int i, int j, int k){

    int t ,l ;

    // Checking if already k is present or not in the row
    for (t=0; t<SIZE; t++){
        if (board[i][t] == k) return 0; }       // Returning 0 indicates it is not success.

    // Checking if already k is present or not in the column.
    for (t=0; t<SIZE; t++){
        if (board[t][j] == k) return 0; }       // Returning 0 indicates it is not success.

    
    // The below two lines make sure that we reach TOP LEFT Corner of each square box.

    t = i/2 *2 ;
    l = j/2 *2 ;
    
    // Checking for the presence of k in its corresponding Square Box.
    if (board[t][l] == k) return 0; 
    if (board[t+1][l] == k) return 0; 
    if (board[t][l+1] == k) return 0;  
    if (board[t+1][l+1] == k) return 0;

    return 1 ;  // 1 indicates that It is not Violating the rules.
}


void print_board(int board[SIZE][SIZE]){
    int i ,j ;
    for (i=0 ;i<SIZE;i++){
        for (j=0 ;j<SIZE;j++){
            printf("%d ",board[i][j]);

        }
        printf("\n");

    }
}


/*
The function solves the sudoku problem if possible. It also prints the solution in this case.
Input : Takes a board position.
Output: Returns 1 if solution is possible. Otherwise returns 0.
*/
int solve_sudoku (int board[SIZE][SIZE]){
    int full = 1, i , j , k , success;          // full checks for the presence of zeros.
    count ++ ;                                  // count checks the number of times "solve_sudoku" function is being called.
    for (i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){

            if (board[i][j] != 0) continue ;
             // continue skips the rest part of the loop and goes to the beginning of the next loop. (similar to python)
          
            full = 0 ; 

            for (k=1 ; k<SIZE+1; k++){

                // Checking whether it is safe to put k in the ijth position.
                if (notViolating(board,i,j,k)==1){
                    board[i][j] = k ;
                    success = solve_sudoku(board);  
                    // Recursive step.
                    // Note that Recursive Step is being called SIZE x SIZE x k times. No of Zeros are decreased in each step.

                    if (success ==1) return 1;
                    
                    // If success is not achieved we place 0 again in the ij-th position.
                    board[i][j] = 0;


                }


            } 

         }


     }

    // full =1 Implies that all elements are Non Zero
    if (full == 1){                 // BASE CASE when full == 1
        printf("\nSuccess! Sudoku is Solved !! \n");
         print_board(board);
         return 1;
     }
    
    // If board is neither full nor success, We reach here.
    return 0 ; // BASE CASE since we didnot succeed in filling up the board.


}



int main(){

    int board[SIZE][SIZE] = {
        {0,0,3,0},                  // Given Sudoko
        {2,0,0,0},
        {1,3,2,4},
        {4,0,0,0}
    };

    print_board(board);
    solve_sudoku(board);
    print_board(board);
    printf("count= %d",count);

}


// Using the Same Algo for 9 x 9 Sudoku will take too long time (More than Life of Earth!!!)
