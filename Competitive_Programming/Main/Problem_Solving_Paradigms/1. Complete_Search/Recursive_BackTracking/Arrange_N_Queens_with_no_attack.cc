#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Checks whether we can place Queen at given Coordinate 
bool is_valid(int (&chessboard)[8][8], pair<int,int> &Coord, vector<pair<int,int>> &Coordinates ){

    int row = Coord.first;
    int column = Coord.second;

    int row_check = 1, column_check = 1, diagonal_check= 1;
    
    for (int i = 0; i< 8; i++){
        if (chessboard[row][i] == 1) {row_check = 0;}
        if (chessboard[i][column] == 1) {column_check = 0;}
    }
    
    // Diagonal check
    for (int each =  0 ; each < Coordinates.size(); each++){
            int row_present = Coordinates[each].first ;
            int column_present = Coordinates[each].second ;
            if ( abs(row-row_present) ==  abs(column-column_present)){
                diagonal_check = 0;
            }
    }    

    return (row_check && column_check && diagonal_check);
}

void Place_Queens(int (&chessboard)[8][8], vector<pair<int,int>> &Coordinates, int ROW, int COL_Start, int n){

    if (n==0) {
        for (auto j : Coordinates) {
            cout << "(" << j.first << " "  << j.second << ")   "; 
        }
        cout << endl;
    }

    else{       

        int placed_queen = 0;

        // COL_Start helps when we are doing BackTracking to avoid reusing the positions. 
        for (int col = COL_Start; col < 8; col++){

            pair<int,int> temp_coord(ROW,col);

            if (is_valid(chessboard, temp_coord, Coordinates)){
                chessboard[ROW][col] = 1;
                Coordinates.push_back(make_pair(ROW,col));
                placed_queen = 1; 
                break;}
        
        }
            
          
            if (placed_queen == 0){
                int len= Coordinates.size();
                int row = Coordinates[len-1].first;
                int col =  Coordinates[len-1].second;          
                chessboard[row][col] =  0;
                Coordinates.pop_back();
                // Back Tracking 
                Place_Queens(chessboard,Coordinates, row, col+1 , n+1); 
            }

            else {
                // Moving Forward, If we found a valid position for last ROW.
                Place_Queens(chessboard,Coordinates, ROW+1 , 0 , n-1); }
        }
}


void find_one_possible_position(int (&chessboard)[8][8], int &n){
    
    // To store the coordinates of the existing Queens! 
    vector<pair<int,int>> Coordinates;  
    Place_Queens(chessboard, Coordinates, 0, 0, n);
}


int main(){
    int n = 8;
    int chess_board[8][8] = {0};
    find_one_possible_position(chess_board, n);
}