/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the sum of the distances from the node to all other nodes.

The below technique is also known as RE-ROOTING TECHNIQUE!
Its called so because, everytime we evaluate the answer assuming the current node is the root of the Tree.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n =  2*(1e5) + 5;
vector< vector<int> > adj_list(n+1);

// ans[i] : Required answer for the node `i`
vector<int> ans(n); 

// subtreeSize[i] : Number of nodes in the subtree rooted at node `i`
vector<int> subtreeSize(n);

// subtreeAns[i] : Required Answer ( Sum of distances from node `i` to all nodes in a tree  ) 
// for the node `i` assuming the tree present is just the subtree rooted at node `i`.
vector<int> subtreeAns(n);


void preprocessing(int src, int par){

    subtreeSize[src] = 1;  // For Leaf nodes
    subtreeAns[src] = 0;   // For Leaf nodes
    for(int child : adj_list[src]){
        if(child != par){
            preprocessing(child, src);
            subtreeSize[src] += subtreeSize[child];
            subtreeAns[src] += ( subtreeAns[child] + subtreeSize[child]);
        }
    }

}

// We are finding the maximum distance from the node `src` whose parent is `par` & 
// the `par_ans` is the required answer for the node `par` excluding the subtree rooted at `src`.
// To get intuition of the recurrences, Draw a general tree & think!!
void dfs(int src, int par, int par_ans, int &TotalNodes) {  

    ans[src] = subtreeAns[src] + ( par_ans + (TotalNodes - subtreeSize[src]) );

    for(int child : adj_list[src]){

        if(child != par){
            int par_ans_src = ans[src] - ( subtreeAns[child] + subtreeSize[child] );
            dfs ( child, src, par_ans_src, TotalNodes );
        }

    }
  
}

signed main(){
    
    cin >> n;
    int vertex, destination;
    for (int i = 1; i <= n-1; i++){
            cin >> vertex >> destination;
            adj_list[destination].push_back(vertex);   
            adj_list[vertex].push_back(destination);
    }

    int start = 1;
    preprocessing(start,0);
    dfs(start, 0, 0, n);
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}