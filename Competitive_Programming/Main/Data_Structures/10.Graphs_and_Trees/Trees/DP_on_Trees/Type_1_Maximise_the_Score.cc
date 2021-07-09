#include <bits/stdc++.h>
using namespace std;

// Score is the sum of the values of the nodes in the path from the root to leaf.
// Note that numbering of the nodes & values in the nodes are not same.

int n = 100;

//  dp[i] indicates the maximum score we can achieve by starting from the subtree of node `i`.
vector<int> dp(n+1);

// Values in the nodes.
vector<int> a(n+1);

// Tree 
vector< vector<int> > adj_list(n+1);

// s -> current node
// par -> Parent node of the current node.
void dfs(int s, int par) {

    // If we carefully observe this recursion, Correct DP Values are being filled from the Bottom of the Tree (leaf) to Top of the tree (root) 

    // process node s
    dp[s] = a[s];

    int maximum = 0; // It should be zero only (not INT_MIN) becoz, If there are no children, It contributes 0 in addition to a[s].  

    // Traversing all the children of the current node.
    for (int child : adj_list[s]) {

        if (child != par) {

            dfs(child, s);

            maximum = max(maximum, dp[child]);
        }
    }

    dp[s] += maximum;

}

int main(){
    // Tree as an Adjacency List with n vertices assuming that all vertex numbers are <= n and m edges.
   
    int m; cin >> n >> m;
    int vertex, destination;

    for (int i = 0; i < m; i++){
            cin >> vertex >> destination;
            adj_list[vertex].push_back(destination);   
            adj_list[destination].push_back(vertex);
    }

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int start = 1;

    // DFS makes sure that we got to next node only after visiting the parent node.
    dfs(start,0);

    // Maximum score by starting from root.( Assuming `1` is the root node. ) 
    cout << dp[1];
    
    /* Sample Input:
    14 13
    1 2
    1 3
    1 4
    2 5
    2 6
    5 11
    5 12
    3 7
    7 13
    7 14
    4 8
    4 9
    4 10
    3 2 1 10 1 3 9 1 5 3 4 5 9 8
    ANS: 22

    Ref: https://youtu.be/gm4Ye0fESpU
    */
}