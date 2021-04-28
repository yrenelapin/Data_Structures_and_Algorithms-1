#include <bits/stdc++.h>
using namespace std;
int main(){

    //------------------------------------------------------------
    // Graph as an Adjacency Matrix with n vertices
    
    int n, no_of_edges;
    cin >> n >> no_of_edges ; 
    
    // In case of Adjacency matrix, we need to initialise for all positions.
    vector< vector<int> > adj_matrix( n ,vector<int>(n, 0) );
    
    while(no_of_edges--){
        int start, end;
        cin >> start >> end ;
    
        // If Graph is UNDIRECTED
        adj_matrix[start][end] = 1;
        adj_matrix[end][start] = 1;   // If Graph is DIRECTED, this line wont exist.
    }
    
    for (int i = 0; i< n ; i++){
        for (int j= 0 ; j n ; j++){
            cout  << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }


    //------------------------------------------------------------
    // Graph as an Adjacency List with n vertices

    int n, vertex, destination;
    cin >> n;

    // Note that We are assuming ( 0 <= vertex <= n -1 ), Otherwise we may need to initialise adj_list(n+1)
    vector< vector<int> > adj_list(n);


    for (int i = 0; i < n; i++)
    {
        cin >> vertex;
        while (1)
        {
            cin >> destination;
            if (destination == -1)  // -1 representing the end of adjacent vertices to the current vertex.
                break;
            

            // If Graph is UNDIRECTED
            adj_list[vertex].push_back(destination);
            adj_list[destination].push_back(vertex);   // If Graph is DIRECTED, this line wont exist.
        }
    }

}