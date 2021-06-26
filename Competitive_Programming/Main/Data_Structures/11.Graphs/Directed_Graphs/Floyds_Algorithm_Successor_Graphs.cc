#include <bits/stdc++.h>
using namespace std;

/*
Consider a successor graph that only contains a path that ends in a cycle. 
If we begin our walk at the starting node, 
1) what is the first node in the cycle?
2) how many nodes does the cycle contain?
*/

const int n = 100;
vector<vector<int>> adj_list(n+1);

// Assuming maximum number of steps we walk is <= 2*n+1
int dp[n][n]; 

// To precompute the values o
// int dp[n+1][n+1];
// memset(dp,-1, sizeof(dp));

int succ(int x){
    return adj_list[x][0];
}

// succ(x,k) that gives the node that we will reach if we begin at node x and walk k steps forward.
int succ( int k, int x){

    if (dp[k][x] != -1){
        return dp[k][x];
    }
    else{
        if (k == 1){
            return dp[k][x] = succ(x); 
        }
        else{
            return dp[k][x] = succ(succ(x,k/2), k/2);
        }
    }

}

void Floyd_Algo(int x){

    int a = succ(x);
    int b = succ(succ(x));
    while (a != b) {
        a = succ(a);
        b = succ(succ(b));
    }

    a = x;
    while (a != b) {
        a = succ(a);
        b = succ(b);
    }

    int first = a;
    cout << "\nFirst Node in the cycle: " << first << endl;

    b = succ(a);
    int length = 1;
    while (a != b) {
        b = succ(b);
        length++;
    }

    cout << "\nLength of cycle: " << length << endl;

}


int main(){
    // Sample Input from CP Book.
    // adj_list[1] = {2};
    // adj_list[2] = {3};
    // adj_list[3] = {4};
    // adj_list[4] = {5};
    // adj_list[5] = {6};
    // adj_list[6] = {4};
    adj_list[1] = {3};
    adj_list[3] = {7};
    adj_list[7] = {1};
    adj_list[9] = {3};
    adj_list[2] = {5};
    adj_list[5] = {2};
    adj_list[4] = {6};
    adj_list[8] = {6};
    adj_list[6] = {2};

    
    memset(dp,-1, sizeof(dp));

    // Floyd_Algo(1);

    for(int x = 1; x <=n; x++ ){
        // for(int k =1; k <= n; k++){
            int k = 1;
            cout << x << " " << k << " " << succ(x,k) << "\n"; 
        
    }



}
