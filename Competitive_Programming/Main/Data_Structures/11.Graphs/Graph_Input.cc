#include <bits/stdc++.h>
using namespace std;

void inp_adj_list(){
    // Graph as an Adjacency List with n vertices assuming that all vertex numbers are <= n
    // For weighted graph, use vector< vector< pair<int,int> > > adj_list(n+1);  and push { destination, weight }

    int n; cin >> n;
    int vertex, destination;
    vector< vector<int> > adj_list(n+1);
    for (int i = 0; i < n; i++){
        cin >> vertex;
        while (1){
            cin >> destination;
            if (destination == -1)  break;              // -1 representing the end of adjacent vertices to the current vertex. or [ while (cin>> temp) ] may be needed.
            adj_list[vertex].push_back(destination);   
            // adj_list[destination].push_back(vertex);  // If Graph is UNDIRECTED, use it. Note that, vertices may be repeatedly added into adj list. Mostly in case of DENSE Graph.
        }
    }

    // Print
    for (int i = 1; i <= n; i++){
        cout << "Vertex " << i << " -> ";
        vector<int> adj = adj_list[i];
        for (int j = 0; j < adj.size(); j++){
            cout << adj[j] << " ";
        }
        cout << endl;
    }

}

void inp_adj_mat(){
    // Graph as an Adjacency Matrix with n vertices assuming that all vertex numbers are <= n.
    // For weighted graph, take the weight input too. 

    int n, no_of_edges;
    cin >> n >> no_of_edges ; 
    vector< vector<int> > adj_matrix( n+1, vector<int>(n+1) );
    while(no_of_edges--){
        int start, end, w = 1;
        cin >> start >> end ;            // cin >> w;
        adj_matrix[start][end] = w;
        // adj_matrix[end][start] = w;   // If Graph is UNDIRECTED, use it. 
    }

    // Print
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

}

void inp_edge_list(){
    // Graph as an Edge List.
    // For weighted graph, use vector< vector<int> > and push { a, b, weight }

    int no_of_edges;
    cin >> no_of_edges ; 
    vector< pair<int,int> > edge_list;
    while(no_of_edges--){
        int start, end, w = 1;
        cin >> start >> end ;             // cin >> w;
        edge_list.push_back( { start, end } ); 
        // edge_list.push_back( { end, end } );  // If Graph is UNDIRECTED, use it. 
    }

    // Print
    for (int i = 0; i < edge_list.size(); i++){
        cout << edge_list[i].first << " " << edge_list[i].second << endl;
    }

}

int main(){ 
    inp_adj_list();   cout << endl;
    inp_adj_mat();    cout << endl;
    inp_edge_list();  cout << endl;
}