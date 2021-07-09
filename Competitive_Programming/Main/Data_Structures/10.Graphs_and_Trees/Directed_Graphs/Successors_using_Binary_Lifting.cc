#include <bits/stdc++.h>
using namespace std;

const int n = 9;
vector<vector<int>> adj_list(n+1);

int succ(int x){
    return adj_list[x][0];
}

// Actually, It should be the maximum number of steps we will ever walk.
// So the `LOG` bound depends on the Input constraints. Also in similar problems like Ancestors, It is either direct Log or Depth of Tree. 
int LOG = log2(n) + 1;

// dp[v][j]  -> 2^j th successor of v.
vector<vector<int>> dp(n+1, vector<int>(LOG+1) );

void precompute(){

    // 2^0th i.e, 1st successor of `v`
    for (int v = 1; v <= n; v++ ){
        dp[v][0] = succ(v);                            // if (k == 1) succ(x,k) = succ(x);
    } 

    // Finding the 2^jth successor using the 2^j-1 th successor.
    // Notice the ordering of the `for` loops.
    for ( int j = 1; j < LOG; j++ ){
        for ( int v = 1; v <= n; v++ ){
                dp[v][j] = dp[ dp[v][j-1]  ][j-1];    // if (k > 1) succ(x,k) = succ(succ(x,k/2), k/2);
        }
    }

}

// O(logk) ~ O(logn)
int getSuccessor(int node, int k) {
    
    int curr_log = log2(k)+1;

    // We are checking the positions at which `k` has bit as `1`.
    for ( int j = 0; j < curr_log; j++ ){

        if ( k & (1 << j) ){
            node = dp[node][j];
        }
    }

    return node;
}


int main(){
    // Sample Input from CP Book.
    adj_list[1] = {3};
    adj_list[3] = {7};
    adj_list[7] = {1};
    adj_list[9] = {3};
    adj_list[2] = {5};
    adj_list[5] = {2};
    adj_list[4] = {6};
    adj_list[8] = {6};
    adj_list[6] = {2};

    // O(n*Logn)
    precompute();

    // Printing the table
    for (int k = 0; (1 << k) <= 9; k++ ){
        for (int x = 1; x <= 9; x++ ){
            cout << getSuccessor(x,1 << k) << " ";
        }
        cout << endl;
    }

    // If there are q queries, then can be answered in O(qlogn + nlogn)
    // But if we use Bruteforce, It takes O(qn)
}

