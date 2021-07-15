#include <bits/stdc++.h>
using namespace std;

int n = 1000;


/*
0 -> White ( Unprocessed )
1 -> Gray ( Processing )
2 -> Black (Processed )
*/

vector<vector<int>> adj_list(n+1);
vector<int> traversalColor(n+1, 0);
vector<int> distance_vec(n+1);
queue<int> q; // Queue is to store the vertices to be visited ( Adjacent vertices )

// Iterative -> O(|V| + |E|)
void BFS(int vertex){

    distance_vec[vertex] = 0;
    traversalColor[vertex] = 1;
    q.push(vertex);

    while(!q.empty()){
        int curr = q.front(); 
        q.pop();
    
        // Process the Node
        cout << curr << " ";

        for(auto v: adj_list[curr]){
            if (traversalColor[v] == 0){
                traversalColor[v] = 1;
                distance_vec[v] = distance_vec[curr]+1;
                q.push(v);
            }
        }

        // Now the `curr` node is processed.
        traversalColor[curr] = 2;

    }

}

// Recursive -> O(|V| + |E|) with no distance_vec implementation
void BFS_rec( vector<vector<int>> adj_list, queue<int> &queue, vector<int> &traversalColor) {

    if (queue.empty())
        return;

    int vertex = queue.front();
    queue.pop();

    // Process the Node
    cout << vertex << " ";

    for (auto i : adj_list[vertex]) {
        if (traversalColor[i] == 0) {
            traversalColor[i] = 1;
            queue.push(i);
        }
    }

    // Now the `vertex` node is processed.
    traversalColor[vertex] = 2;

    BFS_rec(adj_list, queue, traversalColor);
}



int main() {

    // Graph as an Adjacency List with n vertices assuming that all vertex numbers are <= n and having `m` edges.
    // For weighted graph, use vector< vector< pair<int,int> > > adj_list(n+1);  and push { destination, weight }
      
cin >> n;
int source, destination;
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
    
    // This loop is required since there might be some nodes which are not covered 
    // if we just call BFS once i.e when the Graphs are not CONNECTED.
    for (int i=1; i<=n; i++) {
       
      // We need to ensure that all nodes are visited.
        if (traversalColor[i] == 0) {
             BFS(i);

            // queue<int> q; q.push(i); traversalColor[i] = 1;
            // BFS_rec(adj_list, q, traversalColor);
        }
        
    }

    return 0;
}
