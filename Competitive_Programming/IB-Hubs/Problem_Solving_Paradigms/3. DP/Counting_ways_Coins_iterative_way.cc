#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

/* Calculate the total number of ways to produce a sum x using the coins. For
example, if coins = {1,3,4} and x = 5, there are a total of 6 ways */


vector<int> coins = {1,3,4};

vector<int> dp(6,-1);  // size = x+1 since we need to store from 0,1,2,3,,,...x

int solve(int x){
    
    dp[0] = 1;

    for (int j = 1; j <= x; j++){
            
            dp[j] = 0;
            
            for (int i = 0 ; i < coins.size(); i++){
                
                // The coin we are putting should have its value( coins[i] ) atleast as the sum (j) for which we are computing.    
                if ( j-coins[i] >= 0)
                    dp[j] += dp[j-coins[i]] ;

            dp[j] %= mod;
        }

    }
    
    return dp[x];


}


int main(){
    cout << solve(5);
}