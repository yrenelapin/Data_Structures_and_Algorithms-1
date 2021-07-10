/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the sum of the distances from the node to all other nodes.

The below technique is also known as RE-ROOTING TECHNIQUE!
Its called so because, everytime we evaluate the answer assuming the current node is the root of the Tree.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long


// dp[v][j]  -> 2^j th ancestor of v.
vector<vector<int>> dp;
vector<int> depth;
int LOG;


void TreeAncestor(int n, vector<int>& parent) {
    
    // In General case, The `LOG` value is actually the Depth of the tree.
    LOG = log2(n+1) + 1;
    
    dp =  vector<vector<int>> (n+1, vector<int>(LOG) );
    depth = vector<int>(n+1);

    parent[0]  = -1; // This makes sure that when ever we make a query for which that `kth` ancestor is missing, We stay in root only.

    depth[0]   = 0;  // Depth of root node is 0.

    // 2^0th i.e, 1st ancestor of `v` is just its parent. 
    for(int v = 1; v < n+1; v++ ){
        dp[v][0] = parent[v];
        // We cant compute the depths here because there may be cases where parent[v] > v; in which case we get wrong results.
    }

    // Finding the 2^jth ancestors using the 2^j-1 th ancestor.
    // Notice the ordering of the `for` loops.
    for ( int j = 1; j < LOG; j++ ){
        for ( int v = 1; v < n+1; v++ ){
            
                // Computing depths here makes sure that even if parent[v] > v, we get correct final depths. 
                if (v != 0){
                    depth[v] = depth[parent[v]] + 1;
                }

                dp[v][j] = dp[ dp[v][j-1]  ][j-1];  // 2^(j-1)th ancestor of  2^(j-1)th ancestor of v is the 2^j th ancestor of v
        }
    }
    
}

int getKthAncestor(int node, int k) {
    
    // There is no kth ancestor for the given node.
    if (depth[node] < k){
        return -1;
    }

    // We are checking the positions at which `k` has bit as `1`.
    for ( int j = 0; j < LOG; j++ ){

        if ( k & (1 << j) ){
            node = dp [node][j];
        }
    }

    return node;
}

signed main(){
    int n, q;
    cin >> n >> q;
    int vertex;
    vector<int> parent = {-1,-1};
    for (int i = 1; i <= n-1; i++){
            cin >> vertex;
            parent.push_back(vertex);
    }

    TreeAncestor(n,parent);
    int x, k;
    for (int i = 1; i <= q; i++){
        cin >> x >> k;
       cout << getKthAncestor(x,k) << endl;
    }
}