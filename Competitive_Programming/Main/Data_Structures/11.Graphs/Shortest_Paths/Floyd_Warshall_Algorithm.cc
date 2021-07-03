#include <bits/stdc++.h>
using namespace std;

// O( |V|^3  )
void FW_shortest(  vector< vector<int> > &adj_matrix, int n){

    vector< vector<int> > distance(n+1,vector<int>(n+1) );

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j){ // Assuming Input graph is Simple (No self loops).
                distance[i][j] = 0;
            }
            else if (adj_matrix[i][j]){
                distance[i][j] = adj_matrix[i][j];
            }
            else{
                distance[i][j] = INT_MAX;
            }
        }
    }


    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){   
                int curr = distance[i][k]+ distance[k][j];
                distance[i][j] = min(distance[i][j], curr);
            }
        }
    }


    // Printing the Shortest Distances between every pair of nodes.
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }


}


int main(){
    // Graph as an Adjacency Matrix with n vertices assuming that all vertex numbers are <= n.
    // For weighted graph, take the weight input too. 

    int n, no_of_edges;
    cin >> n >> no_of_edges ; 
    vector< vector<int> > adj_matrix( n+1, vector<int>(n+1) );
    while(no_of_edges--){
        int start, end, w = 1;
        cin >> start >> end ; cin >> w;
        adj_matrix[start][end] = w;
        adj_matrix[end][start] = w;   // If Graph is UNDIRECTED, use it. 
    }

    FW_shortest(adj_matrix, n); 

    /*Input:
    5 6
    1 5 1
    1 4 9
    1 2 5
    2 3 2
    3 4 7
    4 5 2
    */
}
