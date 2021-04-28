#include <iostream>
#include <vector>
using namespace std;

// We need Stack Functionality
void DFS(int vertex,  vector< vector<int> > adj_list , vector<bool> &visited)
{
    cout << vertex << " ";
    visited[vertex] = true;
    for (auto i : adj_list[vertex])
    {
        if (!visited[i])
        {
            DFS(i, adj_list, visited);
        }
    }
}

int main()
{
    int n, source, destination;
    cin >> n;

    // Since the vertices values range from 1 to n, we need `n+1` vector size. 
    vector< vector<int> > adj_list(n+1); // Array of Vectors
    
    for (int i = 0; i < n; i++)
    {
        cin >> source;
        while (1)
        {
            cin >> destination;
            if (destination == -1)
                break;
            adj_list[source].push_back(destination);
            
            // Since It is an UNDIRECTED Graph.
            adj_list[destination].push_back(source);
        }
    }
    
    // Creates a vector of size n+1 with all values defaulted as `false`.
    vector<bool> visited(n + 1, false);
    
    DFS(1, adj_list, visited);
    return 0;
}
