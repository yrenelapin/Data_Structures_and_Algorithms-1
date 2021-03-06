#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

// This is a DP - Bottom up approach. Efficient one.
lli minCost(vector<vector<lli>> cost)
{
    lli n = cost[0].size(), m = cost.size();

    // Table to store the minimum cost path to each postiton .
    // i.e. table[i][j] contains the minimum cost path to (i,j) position
    // starting from (0,0).
     
    vector<vector<lli>> table(m, vector<lli>(n));

    for (lli i = 0; i < m; i++)
    {
        for (lli j = 0; j < n; j++)
        {  
            // Including its own Cost in the beginning itself  
            table[i][j] = cost[i][j];
            
            // fill first row
            if (i == 0 && j > 0)
                table[0][j] += table[0][j - 1]; 
                // Cumulative since only 1 min cost path.
        
            // fill first column
            else if (j == 0 && i > 0)           
                table[i][0] += table[i - 1][0];
                // Cumulative since only 1 min cost path.
        
            // fill remaining table
            else if (i > 0 && j > 0)
                // Taking the minimum value among the left and top & keep on adding.
                table[i][j] += min(table[i - 1][j], table[i][j - 1]);
        }
    }

    return table[m - 1][n - 1];
}

int main(){
    lli m, n;
    cin >>m>>n;
    vector<vector<lli>> matrix(m, vector<lli>(n,-1));
    for (lli i = 0;i<m; i++){
        for (lli j = 0; j <n ; j++){
            cin >> matrix[i][j];
        }
    }
    
    cout << minCost(matrix);

}