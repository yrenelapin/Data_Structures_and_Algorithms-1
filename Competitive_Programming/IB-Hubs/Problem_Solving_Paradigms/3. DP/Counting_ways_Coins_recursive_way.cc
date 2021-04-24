#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

/* Calculate the total number of ways to produce a sum x using the coins. For
example, if coins = {1,3,4} and x = 5, there are a total of 6 ways */


vector<int> coins = {1,3,4};

vector<int> dp(6,-1);  // size = x+1 since we need to store from 0,1,2,3,,,...x

int solve(int x){
    
    if (x < 0) {
        return 0;
    }
    if (x == 0){
        return 1;
    }

    if (dp[x] != -1){
        return dp[x];
    }

    int sum = 0;
    for (int i = 0 ; i < coins.size(); i++){
        sum += (solve(x-coins[i]));
    }

    dp[x] = sum;
    dp[x] %= mod;
    return sum;


}


int main(){
    cout << solve(5);
}