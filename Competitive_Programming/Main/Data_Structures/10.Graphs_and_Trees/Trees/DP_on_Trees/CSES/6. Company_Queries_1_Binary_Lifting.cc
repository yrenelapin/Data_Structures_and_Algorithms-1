#include <bits/stdc++.h>
using namespace std;
 
// vector< vector<int> > adj_list(200001, vector<int>(20) );
// vector< vector<int> > up(200001, vector<int>(20) );
 
// log2(200001) ~ 20
 
// up[v][j]  -> 2^j th ancestor of v.
int up[200001][20];
vector<int> adj_list[200001];
 
 
// Evaluating the up table for the vertex `src`
void binary_lifting(int src, int par){
 
    up[src][0] = par;
    for(int i = 1; i < 20; i++){
 
        // If it has 2^(i-1)th ancestor.  ( -1 indicates there is no ancestor. )
        if(up[src][i-1] != -1)
 
            // 2^(j-1)th ancestor of  2^(j-1)th ancestor of v is the 2^j th ancestor of v
            up[src][i] = up[up[src][i-1]][i-1];
        
 
        else up[src][i] = -1;
    }
    
    // Evaluating the `up` for children of `src`
    for(int child : adj_list[src]){
        if(child != par)
            binary_lifting(child, src);
    }
}
 
int ans_query(int node, int jump_required){
    
    for(int i = 19; i >= 0; i--){
        
        // If we have finished our jumps/ there is no ancestor possible (node = -1), we return the node itself.
        if(node == -1 || jump_required == 0)
            break;
        
        // Trying to make the longest jump at each step
        if(jump_required >= (1<<i)){
            jump_required -= (1<<i);
            node = up[node][i];
        }

    }
    
    return node;
}
 
signed main(){
    int n, q;
    cin >> n >> q; int vertex;
    for (int i = 2; i <= n; i++){
            cin >> vertex;
            adj_list[vertex].push_back(i);
            adj_list[i].push_back(vertex);
    }
 
    binary_lifting(1, -1);
 
    for (int i = 1; i <= q; i++){
        int node, k;
        cin >> node >> k;
        cout << ans_query(node, k) << '\n';
    }
}