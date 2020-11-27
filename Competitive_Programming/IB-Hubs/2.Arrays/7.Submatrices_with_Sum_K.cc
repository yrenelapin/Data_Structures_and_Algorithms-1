/*
Submatrices with Sum K
Given a matrix A of size M * N and an integer K, find number of submatrices with sum equal to K.

Input
First line contains three space separated integers M, N and K.
Each of the following M lines contains N space separated integers of A.

Output
Print a single integer representing the number of matrices with sum equal to K.
*/

#include <bits/stdc++.h>
#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
   public:
   int numSubmatrixSumTarget(vector<vector<int>>& matrix, int
   target) {
      int ans = 0;
      int col = matrix[0].size();
      int row = matrix.size();
      for(int i = 0; i < row; i++){
         for(int j = 1; j < col; j++){
            matrix[i][j] += matrix[i][j - 1];
         }
      }
      unordered_map <int, int> m;
      for(int i = 0; i < col; i++){
         for(int j = i; j < col; j++){
            m.clear();
            m[0] = 1;
            int sum = 0;
            for(int k = 0; k < row; k++){
               int current = matrix[k][j];
               if(i - 1 >= 0)current -= matrix[k][i - 1];
               sum += current;
               ans += m[target - sum];
               m[-sum]++;
            }
         }
      }
      return ans;
   }
};
main(){
   Solution ob;
    int M;
    scanf("%d",&M);
    int N;
    scanf("%d",&N);
    int K;
    scanf("%d",&K);
    
    // Initializing the vector of vectors 
    vector<vector<int> > vec; 
 
    // Inserting elements into vector 
    for (int i = 0; i < M; i++) { 
        // Vector to store column elements 
        vector<int> v1; 
  
        for (int j = 0; j < N; j++) { 
            int num ;
            scanf("%d",&num);
            v1.push_back(num); 
        } 
  
        // Pushing back above 1D vector 
        // to create the 2D vector 
        vec.push_back(v1); 
    } 
   cout << (ob.numSubmatrixSumTarget(vec, K));
  
} 
