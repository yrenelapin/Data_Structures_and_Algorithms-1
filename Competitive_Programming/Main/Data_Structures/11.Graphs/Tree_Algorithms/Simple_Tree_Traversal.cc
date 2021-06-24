#include <bits/stdc++.h>
using namespace std;

// s -> current node
// par-> Parent node of the current node.
void dfs(int s, int par, vector< vector<int> > &adj_list) {

    // process node s
    cout << s << " ";

    // Traversing all the children of the current node.
    for (auto child : adj_list[s]) {
        if (child != par) {
        
             dfs(child, s, adj_list); 
        
        }
    }

}

int main(){
    // Tree as an Adjacency List with n vertices assuming that all vertex numbers are <= n and m edges.
   
    int n, m; cin >> n >> m;
    int vertex, destination;
    vector< vector<int> > adj_list(n+1);
    for (int i = 0; i < m; i++){
            cin >> vertex >> destination;
            adj_list[vertex].push_back(destination);   
            adj_list[destination].push_back(vertex);
    }

    int start = 1;
    dfs(start,0, adj_list);

    
    /* Sample Input:
    4 3
    1 2
    1 3
    2 4
    */
}