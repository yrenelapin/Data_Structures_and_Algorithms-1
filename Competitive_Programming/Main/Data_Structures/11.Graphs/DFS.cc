#include <bits/stdc++.h>
using namespace std;

// O(|V| + |E|)
void DFS(int vertex,  vector< vector<int> > adj_list , vector<bool> &visited){

    visited[vertex] = true;
    cout << vertex << " ";   // Process the node here.
 
    for (auto i : adj_list[vertex]){
        if (!visited[i]){
            DFS(i, adj_list, visited);
        }
    }
}

int main()
{
    // Graph as an Adjacency List with n vertices assuming that all vertex numbers are <= n and having `m` edges.
    // For weighted graph, use vector< vector< pair<int,int> > > adj_list(n+1);  and push { destination, weight }
      
    int n, m; cin >> n >> m;
    int vertex, destination;
    vector< vector<int> > adj_list(n+1);
    for (int i = 0; i < m; i++){
            cin >> vertex >> destination;
            adj_list[vertex].push_back(destination);   
            adj_list[destination].push_back(vertex);  // If Graph is UNDIRECTED, use it. 
    }


    // Creates a vector of size n+1 with all values defaulted as `false`.
    vector<bool> visited(n + 1, false);
    
    
    // This loop is required since there might be some nodes which are not covered 
    // if we just call DFS once i.e when the Graphs are not CONNECTED.
    for (int i=1; i<=n; i++) {
        
        // We need to ensure that all nodes are visited.
        if (visited[i] == false) {
            DFS(i, adj_list, visited); 
        }

    }
    
    return 0;
}
