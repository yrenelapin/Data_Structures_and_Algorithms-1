#include <bits/stdc++.h>
using namespace std;

/*
This works only for UNDIRECTED Graphs. Even in some Undirected Graphs, It is failing. Debug it!
For Directed graphs, We need to talk in terms of STRONG CONNECTIVITY instead of CONNECTIVITY.
Another way to find out whether a graph contains a cycle is to simply calculate
the number of nodes and edges in every component. If a component contains c
nodes and no cycle, it must contain exactly c −1 edges (so it has to be a tree). If
there are c or more edges, the component surely contains a cycle.

Example Test case where it fails for directed graph:
7
1 3 2 -1
2 4 -1
3 5 -1
4 5 7 -1
5 6 -1
6 -1
7 -1
*/

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
      
    int source, dest;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> source;
        while (1)
        {
            cin >> dest;
            if (dest == -1)
                break;
            adj_list[source].push_back(dest);
        }
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
         // For each component
          auto curr_comp =  connected_comp[i] ;

          int nodes =  curr_comp.size();
          int edges = 0;
          for ( int j = 0; j < curr_comp.size(); j++) {
              // For each node in the current component.
                
                // Current Node adjacent values.
                cna = adj_list[curr_comp[j]];

                for (int k = 0; k < cna.size(); k++) {
                    
                    if ( find(cna.begin(), cna.end(), cna[k] ) != cna.end() ){
                        edges++;
                    } 
                    
                }
          }

          if (edges >= nodes){
              cout << "Yes";
              return 0;
          }
     }

     cout << "No";


}
