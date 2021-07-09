#include <bits/stdc++.h>
using namespace std;

int n = 100;

// This contains the order of the DFS tarversal of nodes which on reversing we get Topological sorted order.
vector<int> top_sort ;

// Parent[i] contains all the vertices that have an edge to edge `i`.
vector<vector<int>> parents(n+1);

void DFS(int vertex, vector< vector<int> > adj_list , vector<bool> &visited)
{
    visited[vertex] = true;

    for (auto i : adj_list[vertex]){

        // Notice that It should be present outside the (!visited[i]).
        parents[i].push_back(vertex);
        
        if (!visited[i]){

            DFS(i, adj_list, visited);
        }

    }
    // Note that we need to push at then end of DFS. 
    top_sort.push_back(vertex);
}



void topological_sort_DFS(   vector< vector<int> > &adj_list, vector<bool> &visited){
   
    for (int i = 1; i < visited.size() ; i++){
        if (visited[i] == false){
            DFS(i, adj_list, visited);
        }
    }
}

int main()
{
    int source, destination;
    cin >> n;

    // Since the vertices values range from 1 to n, we need `n+1` array size
    vector< vector<int> > adj_list(n + 1); 

    for (int i = 0; i < n; i++)
    {
        cin >> source;
        while (1)
        {
            cin >> destination;
            if (destination == -1)
                break;
            adj_list[source].push_back(destination);
        }
    }
    
    // Creates a vector of size n+1 with all values defaulted as `false`.
    vector<bool> visited(n + 1, false);
    
    topological_sort_DFS(adj_list, visited);

    // Making the Topological ordering.
    reverse(top_sort.begin(), top_sort.end());

    int start = top_sort[0];

    // Let paths(x) denote the number of paths from node `start` to node x.     
    vector<int> paths(n+1);
    paths[start] = 1;

    // Filling the paths dp in the topological ordering.
    for (int i = 1; i < n ; i ++){
        
        // For current node, take sum using all the nodes that have a node to current node.
        for(int par = 0; par < parents[top_sort[i]].size(); par++ ){

            paths[top_sort[i]] += paths[parents[top_sort[i]][par]];

        }
    }

     for (int i = 0; i < n ; i ++){
         cout << top_sort[i] << " -> " << paths[top_sort[i]] << "\n";
     }

    return 0;

    /* Sample Input:
    6
    1 2 4 -1
    2 3 -1  
    3 6 -1  
    4 5 -1  
    5 2 3 -1
    6 -1  
    */
}
