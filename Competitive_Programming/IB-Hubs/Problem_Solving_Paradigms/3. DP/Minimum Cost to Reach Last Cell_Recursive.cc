#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli m,n;
bool is_valid(lli i, lli j){
    return ( i >=0 and i <m and j >=0 and j < n);
}

vector<vector<lli>> dp(m+1, vector<lli>(n+1,-1));

// This is just RECURSIVE APPROACH. It is more Intuitive

// If we add Memoisation property using TOP DOWN DP approach,
// It will be efficient.

lli min_cost(vector<vector<lli>> &matrix, lli i, lli j){

    if (!is_valid(i,j)){
        return INT_MAX;
    }
    
    // We need to reach matrix[m-1][n-1] with min cost
    // We reached the destination
    if ( m-1 == i && n-1 == j){
        return matrix[i][j];
    }

    if (dp[i][j] != -1){
        return dp[i][j];
    }

    
    lli right = min_cost(matrix,i, j+1); 
    lli down = min_cost(matrix,i+1, j); 
    lli ans = matrix[i][j] + min(right, down);
    dp[i][j] = ans;
    return ans;
    
}

int main(){
    cin >>m>>n;
    vector<vector<lli>> matrix(m, vector<lli>(n,-1));
    for (lli i = 0;i<m; i++){
        for (lli j = 0; j <n ; j++){
            cin >> matrix[i][j];
        }
    }
    
    cout << min_cost(matrix, 0, 0);
    
  
}