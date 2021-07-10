// https://codeforces.com/contest/161/problem/D

/*
The distance between two vertices of a adj_list is the length (in edges) of the shortest path between these vertices.

You are given a adj_list with n vertices and a positive number k. 
Find the number of distinct pairs of the vertices which have a distance of exactly k between them.
Note that pairs (v, u) and (u, v) are considered to be the same pair
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n =  50005, k =  505;
vector< vector<int> > adj_list(n+1);

// dp1[i][x] -> No of nodes that are at a distance of `x` from the node `i` in the subadj_list rooted at node `i`.
vector<vector<int>> dp1( n,vector<int>(k));

// dp2[i][x] -> No of nodes that are at a distance of `x` from the node `i` in the Actual adj_list.
vector<vector<int>> dp2( n,vector<int>(k));

void dfs(int src, int par, int& k){

    for(int child : adj_list[src])
        if(child != par)
            dfs(child, src, k);
 
    dp1[src][0] = 1;
    for(int distance = 1; distance <= k; distance++){
        dp1[src][distance] = 0;
        for(int child : adj_list[src])
            if(child != par)
                dp1[src][distance] += dp1[child][distance-1];
    }
}
 
void solve(int src, int par, int& k){

    // For the root, dp1 & dp2 are same.
    for(int dis = 0; dis <= k; dis++)
        dp2[src][dis] = dp1[src][dis];
    
    // If it is not root, we compute dp2
    if (par != 0){

       dp2[src][1] += dp2[par][0];
       for(int dis = 2; dis <= k; dis++){
           // This recurrence is very intuitive if we draw on paper & think.

           // No of nodes that are at a distance of `dis` from `src` are already initialised to dp1[src][dis] i.e. all the nodes 
           // that are at a distance of `dis` from `src` and also under the subtree at node `src`. Now we just need to 
           // include the nodes that are at a distance of `dis-1` from `par` & to avoid recounting of already included nodes (nodes 
           // of same subtree ), we subtract nodes that are at a distance of `dis-1` from `src`.
           dp2[src][dis] += ( dp2[par][dis - 1] - dp1[src][dis - 2] );
       }

    }
 
    for(int child : adj_list[src])
        if(child != par)
            solve(child, src, k);
}


signed main(){
    
    cin >> n >> k;
    int vertex, destination;
    for (int i = 1; i <= n-1; i++){
            cin >> vertex >> destination;
            adj_list[destination].push_back(vertex);   
            adj_list[vertex].push_back(destination);
    }

    dfs(1,0,k);
    solve(1,0,k);

    int ans = 0;
    for (int v = 1; v <= n; v++){
        ans += dp2[v][k];
    }

    cout << ans/2;

}