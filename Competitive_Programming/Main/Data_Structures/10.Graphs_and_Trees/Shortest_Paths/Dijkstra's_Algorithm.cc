#include <bits/stdc++.h>
using namespace std;

//  This algorithm requires that there are no negative weight edges in the graph!

// O( |V| + |E|*log(|E|) )
void Dij_shortest( vector< vector<pair<int, int> > > &adj_list, int n, int start){

    // Assuming vertices values are <= n. 
    // distance[i] = { predecessor, shortest_distance }
    vector<pair<int,int>> distance(n+1, {INT_MAX,INT_MAX} );
    distance[start].first  = -1;
    distance[start].second =  0;	

	vector<bool> visited(n+1, false); 

	// Contains (−d, x), meaning that the current distance to node x is d.
	// `-d` is used to use the default c++ MAX Priority Queue but to fetch the pair with min distance.
	priority_queue<pair<int,int>> q;
	q.push({0, start});

	while(!q.empty()){
		int a =  q.top().second; q.pop();

		if (visited[a]) continue;

		visited[a] = true;
		for ( auto i: adj_list[a]){     // O(|E|)

			int b = i.first; int w = i.second;
			if (distance[b].second > distance[a].second + w){
                distance[b].second = distance[a].second + w ;
                distance[b].first = a;
				q.push({-distance[b].second, b});  // O(log|E|) since size of `q` is O(|E|).
            }
		}

	}
 
	// If there is no path to a node, Its values remain {INF,INF}.
	for(int i = 1; i <= n; i++){
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


    Dij_shortest(adj_list, n, 1);

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