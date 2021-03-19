#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli coinChange(vector<lli> diff_coins, lli n)
{
    lli count_include_j, count_exclude_j;
    lli m = diff_coins.size();
    
    // We are constructing a table with n+1 rows (For sum 
    // values of 0,1,...n)   and m columns.
    vector<vector<lli>> table(n + 1, vector<lli>(m));

    for (auto i = 0; i < n + 1; i++) // 'i' represents sum.
    {
        for (auto j = 0; j < m; j++) // 'j' represents coin index.
                                     // diff_coins[j] represents coin value.
        {
            if (i == 0)   // If sum is 0, 
                table[0][j] = 1;

            else
            {
                // count of solutions including diff_coins[j]
                count_include_j = (i - diff_coins[j] >= 0) ? table[i - diff_coins[j]][j] : 0;

                // count of solutions excluding diff_coins[j]
                count_exclude_j = (j >= 1) ? table[i][j - 1] : 0;
                
                // total count till here
                table[i][j] = count_include_j + count_exclude_j;
            }
        }
    }
    return table[n][m - 1];
}

int main()
{
    int m, n;
    cin >> m >> n;

    // Initializes a vector with `0` as its values.
    vector<lli> diff_coins(m);
    for (auto i = 0; i < m; i++)
        cin >> diff_coins[i];

    cout << coinChange(diff_coins, n);
    return 0;
}