#include <bits/stdc++.h>
using namespace std;

// Iterative -> O(|V| + |E|)
void BFS(vector<vector<int>> &adj_list, queue<int> &q, vector<bool> &visited, vector<int> &distance ){


    while(!q.empty()){
        int curr = q.front(); 
        q.pop();
    
        // Process the Node
        cout << curr << " ";

        for(auto v: adj_list[curr]){
            if (visited[v]) continue;
            visited[v] = true;
            distance[v] = distance[curr]+1;
            q.push(v);
        }

    }

}

// Recursive -> O(|V| + |E|)
void BFS_rec( vector<vector<int>> adj_list, queue<int> &queue, vector<bool> &visited) {

    if (queue.empty())
        return;

    int vertex = queue.front();
    queue.pop();

    // Process the Node
    cout << vertex << " ";

    for (auto i : adj_list[vertex]) {
        if (!visited[i]) {
            visited[i] = true;
            queue.push(i);
        }
    }

    BFS_rec(adj_list, queue, visited);
}



int main() {

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

    
    // Initialisation 
    vector<bool> visited(n+1, false);
    vector<int> distance(n+1);
    queue<int> q;
    
    // This loop is required since there might be some nodes which are not covered 
    // if we just call BFS once i.e when the Graphs are not CONNECTED.
    for (int i=1; i<=n; i++) {
        
        // We need to ensure that all nodes are visited.
        if (visited[i] == false) {
            distance[i] = 0;
            visited[i] = true;
            q.push(i);
            BFS(adj_list, q, visited, distance);
        }
    }

    cout << endl;
    cout << "Distances: \n";
    for(int i = 1; i <= n; i++ ){
        cout << i << " -> " << distance[i] << "\n";
    }

    return 0;
}
