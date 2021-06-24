#include <bits/stdc++.h>
using namespace std;


// O(|V|*|E|)
void BF_shortest( vector< vector<int> > &edge_list, int n, int start){

    // Assuming vertices values are <= n. 
    // distance[i] = { predecessor, shortest_distance }
    vector<pair<int,int>> distance(n+1, {INT_MAX,INT_MAX} );

    distance[start].first  = -1;
    distance[start].second = 0;

    // Running it for `n` rounds instead of `n-1` to check for the presence of negative cycles.
    bool neg_cycle_check = 0;

    for(int i = 1; i <= n; i++){

        for ( int j = 0; j < edge_list.size(); j++){
            int a = edge_list[j][0]; 
            int b = edge_list[j][1];
            int w = edge_list[j][2];

            if (distance[b].second > distance[a].second + w){
                distance[b].second = distance[a].second + w ;
                distance[b].first = a; 
                
                if (i == n){
                    // If in the nth Round, Some distance is reduced, so it has a neg cycle.
                    neg_cycle_check = 1;
                }
            }
            
        }

    }

    if (neg_cycle_check){
        // Shortest path is not meaningful in this situation.
        cout << "There is a Negative Cycle!\n";
    }
    else{

        // If there is no path to a node, Its values remain {INF,INF}.
        for(int i = 1; i <= n; i++){
            cout << distance[i].first << " " << distance[i].second << endl;
        }

    }

  
}




int main(){

    // Graph as an "Edge List" assuming all the vertices values are <= n
    // For weighted graph, use vector< vector<int> > and push { a, b, weight }

    int n, no_of_edges;
    cin >> n >> no_of_edges ; 
    vector< vector<int> > edge_list;
    while(no_of_edges--){
        int start, end, w = 1;
        cin >> start >> end; cin >> w;
        edge_list.push_back( { start, end, w } ); 
        edge_list.push_back( { end, start, w  } );  // If Graph is UNDIRECTED, use it. 
    }

    BF_shortest(edge_list, n, 1);

    /* 
    Input from CP Book:
    6
    7
    1 2 5
    1 3 3
    1 4 7
    2 5 2
    2 4 3
    4 5 2
    3 4 1
    -------
    4
    5
    1 2 3
    1 3 5
    2 3 2
    2 4 1
    3 4 -7
    */
}