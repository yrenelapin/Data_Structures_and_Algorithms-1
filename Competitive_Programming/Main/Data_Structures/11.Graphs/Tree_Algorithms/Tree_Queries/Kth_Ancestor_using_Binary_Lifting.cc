/*
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node.
The root of the tree is node 0. Find the kth ancestor of a given node.

The kth ancestor of a tree node is the kth node in the path from that node to the root node.

*/

// Ref : https://youtu.be/oib-XsjFa-M

// Note: The below solution works even if the parent[i] > i.

class TreeAncestor {
    
    // dp[v][j]  -> 2^j th ancestor of v.
    vector<vector<int>> dp;
    vector<int> depth;
    int LOG;
    
public:
    TreeAncestor(int n, vector<int>& parent) {
        
        // In General case, The `LOG` value is actually the Depth of the tree.
        LOG = log2(n) + 1;
        
        dp =  vector<vector<int>> (n, vector<int>(LOG) );
        depth = vector<int>(n);

        parent[0]  = 0; // This makes sure that when ever we make a query for which that `kth` ancestor is missing, We stay in root only.

        depth[0]   = 0;  // Depth of root node is 0.

        // 2^0th i.e, 1st ancestor of `v` is just its parent. 
        for(int v = 0; v < n; v++ ){
            dp[v][0] = parent[v];
            // We cant compute the depths here because there may be cases where parent[v] > v; in which case we get wrong results.
        }

        // Finding the 2^jth ancestors using the 2^j-1 th ancestor.
        // Notice the ordering of the `for` loops.
        for ( int j = 1; j < LOG; j++ ){
            for ( int v = 0; v < n; v++ ){
                
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
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */