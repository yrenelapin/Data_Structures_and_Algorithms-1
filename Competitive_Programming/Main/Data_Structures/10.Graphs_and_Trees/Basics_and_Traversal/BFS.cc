#include <bits/stdc++.h>
using namespace std;

int n = 1e5 + 1;

vector<vector<int>> adj_list(n+1);
vector<bool> visited(n+1, false);
vector<int> distance_vec(n+1);
queue<int> q;

// Iterative -> O(|V| + |E|)
void BFS(int vertex){

    distance_vec[vertex] = 0;
    visited[vertex] = true;
    q.push(vertex);

    while(!q.empty()){
        int curr = q.front(); 
        q.pop();
    
        // Process the Node
        cout << curr << " ";

        for(auto v: adj_list[curr]){
            if (visited[v]) continue;
            visited[v] = true;
            distance_vec[v] = distance_vec[curr]+1;
            q.push(v);
        }

    }

}

// Recursive -> O(|V| + |E|) with no distance_vec implementation
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

    
    // This loop is required since there might be some nodes which are not covered 
    // if we just call BFS once i.e when the Graphs are not CONNECTED.
    for (int i=1; i<=n; i++) {

        // We need to ensure that all nodes are visited.
        if (visited[i] == false) {
            BFS(i);
        }

    }

    cout << endl;
    cout << "Distance_vecs: \n";
    for(int i = 1; i <= n; i++ ){
        cout << i << " -> " << distance_vec[i] << "\n";
    }

    return 0;
}
