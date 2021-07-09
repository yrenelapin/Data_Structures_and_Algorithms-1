#include <bits/stdc++.h>
using namespace std;

void dfs(int s, int e, vector< vector<int> > &adj_list, vector<int> &counter) {
    
    // Initialising the counter.
    counter[s] = 1;
    for (auto u : adj_list[s]) {
        if (u != e) {
            dfs(u, s, adj_list, counter);
            counter[s] += counter[u];
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

    // For each node s a value counter[s] is the number of nodes in its subtree.
    vector<int> counter(n+1);

    int start = 1;
    dfs(start, 0, adj_list, counter);

    
    for(int i = 1; i <= n; i++){
        cout << i << " " << counter[i] << endl;
    }

    /* Sample Input:
    4 3
    1 2
    1 3
    2 4
    */

}