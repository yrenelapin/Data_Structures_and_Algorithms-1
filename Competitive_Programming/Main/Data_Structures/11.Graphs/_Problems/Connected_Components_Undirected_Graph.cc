#include <bits/stdc++.h>
using namespace std;

int n = 1e5 + 1;

vector< vector<int> > adj_list(n+1);
    
// Creates a vector of size n+1 with all values defaulted as `false`.
vector<bool> visited(n + 1, false);


// O(|V| + |E|)
void DFS(int vertex, vector<int> &comp){

    visited[vertex] = true;
    
    comp.push_back(vertex);

    //cout << vertex << " ";   // Process the node here.
 
    for (auto i : adj_list[vertex]){
        if (!visited[i]){
            DFS(i, comp);
        }
    }
}

int main()
{
    // Graph as an Adjacency List with n vertices assuming that all vertex numbers are <= n and having `m` edges.
    // For weighted graph, use vector< vector< pair<int,int> > > adj_list(n+1);  and push { destination, weight }
      
    int m; cin >> n >> m;
    int vertex, destination;
    for (int i = 0; i < m; i++){
            cin >> vertex >> destination;
            adj_list[vertex].push_back(destination);   
            adj_list[destination].push_back(vertex);  // If Graph is UNDIRECTED, use it. 
    }


    vector< vector<int> > connected_comp;

    // This loop is required since there might be some nodes which are not covered 
    // if we just call DFS once i.e when the Graphs are not CONNECTED.
    for (int i=1; i<=n; i++) {
        
        // We need to ensure that all nodes are visited.
        if (visited[i] == false) {

            vector<int> comp;

            DFS(i, comp);

            connected_comp.push_back(comp); 

        }

    }

     for (int i=0; i< connected_comp.size(); i++) {
          
          auto curr_comp =  connected_comp[i] ;

          for (int j=0; j< curr_comp.size(); j++) {
              cout << curr_comp[j] << " ";
          }

          cout << endl;
     }

    
    return 0;
}
