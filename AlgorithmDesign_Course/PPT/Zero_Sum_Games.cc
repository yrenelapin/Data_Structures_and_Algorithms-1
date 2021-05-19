/*
This code is written as a part of CS222-Algorithm Design Course under Dr. Aripta Korwar.

End Semester Assessment - Final Presentation

Authors :   
      Sanjay Marreddi     1904119
      Rishabh Tripathi    1904129
      Prakhar Mathur      1906328
      Nishant Kumar       1904123
      Jaishika Korivi     1903121
      Naga Tanuja Bathena 1903126

Date: 19th May 2021

This file contains code that solves Zero Sum Games problem with the help of Simplex Algorithm.
*/


// Including all the required Libraries and Namespaces.
#include <bits/stdc++.h>
using namespace std;

// Defining a shortname for a datatype of vector of doubles. (Similar to 1D array)
typedef vector<double> vd;

// Defining a shortname for a datatype of vector of vector of doubles. (Similar to 2D array)
typedef vector<vector<double>> vvd;

// Defining a shortname for push_back
#define pb push_back


/* 
The `SetSimplex` function returns the Linear Program in canonical form. 

Inputs : 
max_function - Vector with values of coefficients for each variable.
A            - Matrix with the coefficients of the left hand sides of all the inequalities. 
b            - Vector with the values of the right hand sides of all the inequalities. 
*/
vvd SetSimplex( vd max_function, vvd A, vd b){

 vvd simplex;
 int num_variables = max_function.size();
 int num_equations = A.size();
 int num_cols = num_variables + num_equations + 1 + 1;


 for(int row_i = 0; row_i < num_equations; row_i++){
    vd row(num_cols, 0);
    for(int col_i = 0; col_i < num_variables; col_i++){
      row[col_i] = A[row_i][col_i];
    }
    row[num_variables + row_i] = 1;
    row[num_cols - 1] = b[row_i];
    simplex.pb( row );
 }


  vd last_row(num_cols, 0);
  for(int i = 0; i < num_variables; i++){
    last_row[i] = 0 - max_function[i];
  }

  last_row[num_variables + num_equations] = 1;
  simplex.pb(last_row);

  return simplex;
}


// This function aids in performing the Simplex Algorithm.
bool GetPivots(vvd simplex, int & pivotCol, int & pivotRow, bool & no_sol){

    int num_rows = simplex.size();
    int num_cols = simplex[0].size();
    int num_variables = num_cols - num_rows - 1;

    no_sol = false;
    double min = 0;
    for(int col_i = 0; col_i < num_cols - 2; col_i++){
        double value = simplex[num_rows - 1][col_i];
        if(value < min){
          pivotCol = col_i;
          min = value;
        }
    }


    if(min == 0) return false;

    double minRatio = 0.0;
    bool first = true;
    for(int row_i = 0; row_i < num_rows - 1; row_i++){
        double value = simplex[row_i][pivotCol];

        if(value > 0.0){
          double colValue = simplex[row_i][num_cols - 1];
          double ratio = colValue / value;

          if( (first || ratio < minRatio) && ratio >= 0.0 ){
            minRatio = ratio;
            pivotRow = row_i;
            first = false;
          }
        }
    }


    no_sol = first;
    return !no_sol;
}


// This function takes the output of the `SetSimplex` function and returns the vector containing the probabilites.
vd PerformSimplexAlgo(vvd simplex, double & max){

    int pivotCol, pivotRow;
    int num_rows = simplex.size();
    int num_cols = simplex[0].size();


    bool no_sol = false;
    while( GetPivots(simplex, pivotCol, pivotRow, no_sol) ){
      double pivot = simplex[pivotRow][pivotCol];
  
      for(int col_i = 0; col_i < num_cols; col_i++){
        simplex[pivotRow][col_i] /= pivot;
      }


      for(int row_i = 0; row_i < num_rows; row_i++){
        if(row_i != pivotRow){
          double ratio =  -1 * simplex[row_i][pivotCol];
          for(int col_i = 0; col_i < num_cols; col_i++){
            simplex[row_i][col_i] = simplex[pivotRow][col_i] * ratio + simplex[row_i][col_i];
          }
        }
      }
    }

    if(no_sol){
      vd vec;
      return vec;
    }
      
    max = simplex[num_rows-1][num_cols-1];
    int num_variables = num_cols - num_rows - 1;
    vd res(num_variables, 0);

    for(int col_i = 0; col_i < num_variables; col_i++){

      bool isUnit = true;
      bool first = true;
      double value;

      for(int j = 0; j < num_rows; j++){
          if(simplex[j][col_i] == 1.0 && first){
            first = false;
            value = simplex[j][num_cols - 1];
          }
          else if(simplex[j][col_i] != 0.0){
            isUnit = false;
          }
      }

      if ( isUnit && !first )
        res[col_i] = value;
      else
        res[col_i] = 0.0;
    }

    return res;
}


// Returns the Transpose of the given input matrix.
vvd Transpose(vvd M){
 
      vvd Trans;
      int no_rows = M.size();
      int no_cols = M[0].size();

      for(int j = 0; j < no_cols; j++){
        vd tRow;
        for(int i = 0; i < no_rows; i++){
          tRow.pb(M[i][j]);
        }

        Trans.pb(tRow);
      }

      return Trans;
}


// This function takes the input payoff matrix and converts it into a set of Standard Linear Programs.
vvd SetLinearProgram(vvd G){

      vd max_func, b;

      vvd T = Transpose(G);

      for(int row_i = 0; row_i < T.size(); row_i++){
        for(int col_i = 0; col_i < T[row_i].size(); col_i++){
          T[row_i][col_i] *= -1.0;
        }
        T[row_i].pb(  1.0 );
        T[row_i].pb( -1.0 );
      }

      for(int row_i = 0; row_i < T.size(); row_i++){
        b.pb( 0.0 );
      }

      int row_size = T[0].size();

      vd row_eq_1(row_size, 1.0);
      row_eq_1[row_size - 2] = row_eq_1[row_size - 1] = 0.0;
      T.pb( row_eq_1 );
      b.pb( 1.0 );

      vd row_eq_2(row_size, -1.0);
      row_eq_2[row_size - 2] = row_eq_2[row_size - 1] = 0.0;
      T.pb( row_eq_2 );
      b.pb( -1.0 );

      for(int i = 0; i < row_size; i++){
        if( i < row_size - 2 )
          max_func.pb(1.0);
        else if( i < row_size - 1 )
          max_func.pb(1.0);
        else
          max_func.pb(-1.0);
      }

      return SetSimplex(max_func, T, b);
}


// Takes the input matrix, sets the linear program, computes & prints the maximum payoff along with corresponding probabilities.
void solve(vvd G){

    vvd simplex = SetLinearProgram(G);

    double max;
    vd result = PerformSimplexAlgo(simplex, max);

    int size = result.size();

    if( size == 0){
      printf("\nThere is no optimal solution for given Input.\n");
      return;
    }

    for(int i = 0; i < result.size() - 2; i++)
    {
      printf("\nx%d = %f ", i+1, result[i]);
    }

     printf("\nThe Maximum Payoff value is %f\n", result[size - 2] - result[size - 1]);
}

int main (){

  // The Input Matrix of Payoffs.
  vvd G = { {  3.0, -1.0 } ,
            { -2.0,  1.0 } };

  solve(G);
}