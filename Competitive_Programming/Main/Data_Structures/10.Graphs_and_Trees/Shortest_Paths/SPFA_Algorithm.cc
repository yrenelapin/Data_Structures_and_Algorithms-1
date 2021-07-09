#include <bits/stdc++.h>
using namespace std;

/*
Average Time Complexity: O(|E|) 
Worstcase Time Complexity: O(|V|*|E|) 
*/
void SPFA_shortest(vector< vector<pair<int, int> > >  &adj_list, int S, int V){

    // Assuming vertices values are <= n. 
    // distance[i] = { predecessor, shortest_distance }
    vector<pair<int,int>> distance(V+1, {INT_MAX,INT_MAX} );
    distance[S].first  = -1;
    distance[S].second =  0;	

    // Boolean array to check if vertex
    // is present in queue or not
    bool inQueue[V + 1] = { false };
    queue<int> q;

    q.push(S);
    inQueue[S] = true;
 
    while (!q.empty()) {
 
        // Take the front vertex from Queue
        int u = q.front();
        q.pop();
        inQueue[u] = false;
 
        // Relaxing all the adjacent edges of
        // vertex taken from the Queue
        for (int i = 0; i < adj_list[u].size(); i++) {
 
            int v = adj_list[u][i].first;
            int weight = adj_list[u][i].second;

            if (distance[v].second > distance[u].second + weight){
                distance[v].second = distance[u].second + weight ;
                distance[v].first = u;

                // Check if vertex v is in Queue or not
                // if not then push it into the Queue
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
   
 	// If there is no path to a node, Its values remain {INF,INF}.
	for(int i = 1; i <= V; i++){
		cout << distance[i].first << " " << distance[i].second << endl;
	}

}




int main(){

     // Graph as an Adjacency List with n vertices assuming that all vertex numbers are <= n and having `m` edges.
    // For weighted graph, use vector< vector< pair<int,int> > > adj_list(n+1);  and push { destination, weight }
      
    int n, m; cin >> n >> m;
    int vertex, destination, weight;
    vector< vector< pair<int,int> > > adj_list(n+1);
    for (int i = 0; i < m; i++){
            cin >> vertex >> destination >> weight;
            adj_list[vertex].push_back({ destination, weight} );   
            adj_list[destination].push_back( { vertex, weight} );  // If Graph is UNDIRECTED, use it. 
    }

    SPFA_shortest(adj_list, 1, n);

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