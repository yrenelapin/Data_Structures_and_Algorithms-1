#include <bits/stdc++.h>
using namespace std;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;


// Implementing the Simplex Algorithm
vvd SetSimplex( vd maxFunction, 
       vvd A, 
       vd b)
{
 vvd simplex;


 int numVariables = maxFunction.size();
 int numEquations = A.size();
 int numCols = numVariables + numEquations + 1 + 1;


 for(int iRow = 0; iRow < numEquations; iRow++)
 {
  vd row(numCols, 0);
  for(int iCol = 0; iCol < numVariables; iCol++)
  {
   row[iCol] = A[iRow][iCol];
  }
  row[numVariables + iRow] = 1;
  row[numCols - 1] = b[iRow];


  simplex.push_back( row );
 }


 vd lastRow(numCols, 0);
 for(int iVar = 0; iVar < numVariables; iVar++)
 {
  lastRow[iVar] = 0 - maxFunction[iVar];
 }
 lastRow[numVariables + numEquations] = 1;
 simplex.push_back(lastRow);


 return simplex;
}


bool GetPivots(vvd simplex, int & pivotCol, int & pivotRow, bool & noSolution)
{
 int numRows = simplex.size();
 int numCols = simplex[0].size();
 int numVariables = numCols - numRows - 1;


 noSolution = false;


 double min = 0;
 for(int iCol = 0; iCol < numCols - 2; iCol++)
 {
  double value = simplex[numRows - 1][iCol];
  if(value < min)
  {
   pivotCol = iCol;
   min = value;
  }
 }


 if(min == 0)
  return false;


 double minRatio = 0.0;
 bool first = true;
 for(int iRow = 0; iRow < numRows - 1; iRow++)
 {
  double value = simplex[iRow][pivotCol];
  
  if(value > 0.0)
  {
   double colValue = simplex[iRow][numCols - 1];
   double ratio = colValue / value;


   if((first || ratio < minRatio) && ratio >= 0.0)
   {
    minRatio = ratio;
    pivotRow = iRow;
    first = false;
   }
  }
 }


 noSolution = first;
 return !noSolution;
}


vd PerformSimplexAlgo(vvd simplex, double & max)
{
 int pivotCol, pivotRow;
 int numRows = simplex.size();
 int numCols = simplex[0].size();


 bool noSolution = false;
 while( GetPivots(simplex, pivotCol, pivotRow, noSolution) )
 {
  double pivot = simplex[pivotRow][pivotCol];
  
  for(int iCol = 0; iCol < numCols; iCol++)
  {
   simplex[pivotRow][iCol] /= pivot;
  }


  for(int iRow = 0; iRow < numRows; iRow++)
  {
   if(iRow != pivotRow)
   {
    double ratio =  -1 * simplex[iRow][pivotCol];
    for(int iCol = 0; iCol < numCols; iCol++)
    {
     simplex[iRow][iCol] = simplex[pivotRow][iCol] * ratio + simplex[iRow][iCol];
    }
   }
  }
 }


 if(noSolution)
 {
  vd vec;
  return vec;
 }
 

 max = simplex[numRows-1][numCols-1];
 int numVariables = numCols - numRows - 1;
 vd x(numVariables, 0);
 
 for(int iCol = 0; iCol < numVariables; iCol++)
 {
  bool isUnit = true;
  bool first = true;
  double value;
  for(int j = 0; j < numRows; j++)
  {
   if(simplex[j][iCol] == 1.0 && first)
   {
    first = false;
    value = simplex[j][numCols - 1];
   }
   else if(simplex[j][iCol] != 0.0)
   {
    isUnit = false;
   }
  }


  if(isUnit && !first)
   x[iCol] = value;
  else
   x[iCol] = 0.0;
 }


 return x;
}



vvd Transpose(vvd M)
{
 
 vvd T;

 int mNumRows = M.size();
 int mNumCols = M[0].size();

 for(int mCol = 0; mCol < mNumCols; mCol++)
 {
  vd tRow;
  for(int mRow = 0; mRow < mNumRows; mRow++)
  {
   tRow.push_back(M[mRow][mCol]);
  }

  T.push_back(tRow);
 }

 return T;
 
 return M;
}

vvd SetLinearProgram(vvd A){
 vd maxFunc;
 vd b;

 vvd T = Transpose(A);

 for(int iRow = 0; iRow < T.size(); iRow++)
 {
  for(int iCol = 0; iCol < T[iRow].size(); iCol++)
  {
   T[iRow][iCol] *= -1.0;
  }
  T[iRow].push_back(  1.0 );
  T[iRow].push_back( -1.0 );
 }

 for(int iRow = 0; iRow < T.size(); iRow++)
 {
  b.push_back( 0.0 );
 }

 int rowSize = T[0].size();

 vd rowEq1(rowSize, 1.0);
 rowEq1[rowSize - 2] = rowEq1[rowSize - 1] = 0.0;
 T.push_back( rowEq1 );
 b.push_back( 1.0 );

 vd rowEq2(rowSize, -1.0);
 rowEq2[rowSize - 2] = rowEq2[rowSize - 1] = 0.0;
 T.push_back( rowEq2 );
 b.push_back( -1.0 );

 for(int i = 0; i < rowSize; i++)
 {
  if( i < rowSize - 2 )
   maxFunc.push_back(1.0);
  else if( i < rowSize - 1 )
   maxFunc.push_back(1.0);
  else
   maxFunc.push_back(-1.0);
 }

 return SetSimplex(maxFunc, T, b);
}


void solve(vvd G){

    vvd simplex = SetLinearProgram(G);

    double max;
    vd result = PerformSimplexAlgo(simplex, max);

    int size = result.size();
    if( !size )
    {
      printf("\nNo optimal solution exists\n");
      return;
    }

    for(int i = 0; i < result.size() - 2; i++)
    {
      printf("\nx%d = %f ", i+1, result[i]);
    }

     printf("\nThe Maximum Payoff value is %f\n", result[size - 2] - result[size - 1]);
}

int main ()
{
  vvd G = { {  3.0, -1.0 } ,
            { -2.0,  1.0 } };
  solve(G);
}