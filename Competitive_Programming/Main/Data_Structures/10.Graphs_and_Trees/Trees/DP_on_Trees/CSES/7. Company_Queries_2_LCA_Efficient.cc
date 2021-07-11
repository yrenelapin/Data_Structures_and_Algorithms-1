// Lowest Common Ancestor in O(logn)

#include <bits/stdc++.h>
using namespace std;
 
// log2(200001) ~ 20
 
// up[v][j]  -> 2^j th ancestor of v.
int up[200001][20];
vector<int> adj_list[200001];

int lvl[200001];

void preprocessing(int src, int par, int level){
    
    lvl[src] = level;
    for(auto child: adj_list[src]){
        if (child != par){
            preprocessing(child, src, level+1);
        }
    }
}
 
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


int LCA_eff(int u, int v){

    // Let us keep the node with low level value as `v`. Low level value indicates it is closer to root.
    if (lvl[u] < lvl[v]){
        swap(u,v);
    }

    int diff = lvl[u]-lvl[v];

    // Lets move the other node to same level
    int new_u = ans_query(u, diff);

    if (new_u == v){  // I v is ancestor of u.
        return v;
    }
    else{
        // Now, Both new_u,v are on same level.
        // Lets call the amount of jump we need to make from current level to reach LCA is x.
        // We will try to reach nodes which are the children of LCA. That is we try to make a jump of `x-1` size from each nodes (new_u, v).
        // We know every number can be written as a power of 2. So (x-1) can also be written. 
        // We will make the longest possible jump of size Power of 2 from current  u, v such that nodes we reach after jump from u, v are NOT EQUAL.
        
        // Note, here in problem N = 200000, Log(N) ~ 19, It means we can make a max jump of size 2^19.
        for (int i = 19; i >= 0; i--){
         
            if (up[v][i] != up[new_u][i]){
                   new_u = up[new_u][i];
                   v = up[v][i];
            }

        }

        // Reaching LCA in one step since we are at x-1 currently.
        return ans_query(new_u, 1);
    }

    return 0;

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
    preprocessing(1,-1, 0);
 
    for (int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        cout << LCA_eff(a, b) << '\n';
    }
}