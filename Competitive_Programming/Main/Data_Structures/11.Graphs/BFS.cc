#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS( vector<vector<int>> adj_list, queue<int> &queue, vector<bool> &visited) {
    if (queue.empty())
        return;

    int vertex = queue.front();
    queue.pop();
    cout << vertex << " ";
    
    // Pushing all the adjacent elements into Queue.
    for (auto i : adj_list[vertex]) {
        if (!visited[i]) {
            visited[i] = true;
            queue.push(i);
        }
    }
    BFS(adj_list, queue, visited);
}

int main() {
    int n, source, destination;
    cin >> n;

    // Since the vertices values range from 1 to n, we need `n+1` vector size. 
    vector< vector<int> > adj_list(n+1); 
    for (int i = 0; i < n; i++)
    {
        cin >> source;
        while (1)
        {
            cin >> destination;
            if (destination == -1)
                break;
            adj_list[source].push_back(destination);
            adj_list[destination].push_back(source);
        }
    }
    vector<bool> visited(n+1, false);
    queue<int> queue;
    
    // This loop is required since there might be some nodes which are not covered 
    // if we just call BFS once.
    for (int i=1; i<=n; i++) {
        
        // We need to ensure that all nodes are visited.
        if (visited[i] == false) {
            visited[i] = true;
            queue.push(i);
            BFS(adj_list, queue, visited);
        }
    }
    return 0;
}
