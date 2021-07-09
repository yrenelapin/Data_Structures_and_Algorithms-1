#include <bits/stdc++.h>
using namespace std;

// dp[v][j]  -> 2^j th ancestor of v.
vector<vector<int>> dp;
vector<int> depth;
int LOG;


void TreeAncestor(int n, vector<int>& parent) {
    
    // In General case, The `LOG` value is actually the Depth of the tree.
    LOG = log2(n+1) + 1;
    
    dp =  vector<vector<int>> (n+1, vector<int>(LOG) );
    depth = vector<int>(n+1);

    parent[0]  = 0; // This makes sure that when ever we make a query for which that `kth` ancestor is missing, We stay in root only.

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

int n = 8;
vector<vector<int>> adj_list(n+1);
vector<int> parent;

void lowest_comm_anc(int node1, int node2){


    // Step1 : O(logn)
    int p1 = node1;
    int p2 = node2;
    if (depth[p1] > depth[p2]){
        int diff = depth[p1] - depth[p2];
        p1 = getKthAncestor(p1, diff);
    }
    else if (depth[p1] < depth[p2]){
        int diff = depth[p2] - depth[p1];
        p2 = getKthAncestor(p2, diff);
    }
    else{
        // Nothing.
    }

    // Step2 : O(n)
    for (int i = 1; i <= n; i++) {
        if (getKthAncestor(p1,i) == getKthAncestor(p2,i)){
            cout << getKthAncestor(p1,i);
            break;
        }

    }
}


int main(){

    adj_list[1] = {2, 3, 4};
    adj_list[2] = {1, 5, 6};
    adj_list[4] = {1, 7};
    adj_list[3] = {1};
    adj_list[5] = {2};
    adj_list[6] = {2, 8};
    adj_list[7] = {4};
    adj_list[8] = {6};

    // parent of node `1` is assumed `0`. 
    parent = {0,0,1,1,1,2,2,4,6};

    // For precomputing the ancestors.
    TreeAncestor(n, parent);

    int node1, node2;
    cin >> node1 >> node2;
    lowest_comm_anc(node1,node2);
}
