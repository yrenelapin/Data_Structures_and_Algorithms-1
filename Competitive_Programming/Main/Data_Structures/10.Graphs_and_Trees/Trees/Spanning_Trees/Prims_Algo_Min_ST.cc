#include <bits/stdc++.h>
using namespace std;

//  This algorithm works only for UNDIRECTED GRAPHS!

// O( |V| + |E|*log(|E|) )
void Prims_Algo( vector< vector<pair<int, int> > > &adj_list, int n, int start){

	// All the included edges are in this mst.
    vector<vector<int>> mst;
	vector<bool> inmst(n+1, false);

	vector<bool> visited(n+1, false); 

	priority_queue< vector<int> > q;

	for ( auto i: adj_list[start]){ 
		q.push({ -i.second, start, i.first });
	}

	visited[start] = true;
	inmst[start] = true;

	while(!q.empty()){
		
		auto a =  q.top(); q.pop();
		
		if (!inmst[a[2]]){
			mst.push_back({a[1], a[2], -a[0]});
			inmst[a[2]] = true;
		}
	

		if (!visited[a[2]]){

			visited[a[2]] = true;

			for ( auto i: adj_list[a[2]]){    

					int source = a[2];
					int destination = i.first;
					int weight = i.second;
					if (!inmst[destination]){
						q.push({-weight, source, destination}); 
					}
					
			}

		}
	}

	cout << "\nThe Edges included in MST: \n";
    for(int i = 0; i < mst.size(); i++){
        cout << mst[i][0] << " "  << mst[i][1] << " " << mst[i][2] << "\n" ;
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
			adj_list[destination].push_back({ vertex, weight} );  
    }


    Prims_Algo(adj_list, n, 1);

      /* 
    Input from CP Book:
    6 8
    1 2 3
    1 5 5
    2 5 6
    2 3 5
    5 6 2
    3 6 3
    3 4 9
    6 4 7
	-----
	9 14
	1 2 4
	1 8 8
	2 3 8
	2 8 11
	3 4 7
	3 9 2
	3 6 4
	4 5 9
	4 6 14
	5 6 10
	6 7 2
	7 8 1
	7 9 6
	8 9 7
	----
	Ans: 37 ( https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/ )
    */
}