#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli coinChange( vector<lli> &S, lli m, lli n ) 
{ 
    // table[i] will be storing the number of solutions for 
    // value i. We need n+1 rows as the table is constructed 
    // in bottom up manner using the base case (n = 0) 
    lli table[n+1] = {0}; 
  
    // Base case (If given value is 0) 
    table[0] = 1; 
  
    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin 
    for(lli i=0; i<m; i++) 
        for(lli j = S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    return table[n]; 
} 

int main()
{
    lli m, n;
    cin >> m >> n;
    // Initializes a vector with `0` as its values.
    vector<lli> diff_coins(m);
    for (auto i = 0; i < m; i++)
        cin >> diff_coins[i];

    cout << coinChange(diff_coins, m, n);
    return 0;
}