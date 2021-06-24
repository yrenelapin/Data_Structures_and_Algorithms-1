#include <bits/stdc++.h>
using namespace std;

int n = 100;
vector< vector<int> > adj_list(n+1);

// Iterative -> O(|V| + |E|)
pair<int, int> BFS(int start){

    // Initialisation 
    vector<bool> visited(n+1, false);
    vector<int> distance(n+1);
    queue<int> q;

    distance[start] = 0;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){

        int curr = q.front(); 
        q.pop();
    
        // Process the Node
        //cout << curr << " ";

        for(auto v: adj_list[curr]){
            if (visited[v]) continue;
            visited[v] = true;
            distance[v] = distance[curr]+1;
            q.push(v);
        }

    }

    int maxDis = 0;
	int nodeIdx;
    // get farthest node distance and its index
	for (int i = 1; i <= n; i++)
	{
		if (distance[i] > maxDis)
		{
			maxDis = distance[i];
			nodeIdx = i;
		}
	}

	return make_pair(nodeIdx, maxDis);

}


void longestPathLength() {

	pair<int, int> t1, t2;

	// first bfs to find one end point of
	// longest path
	t1 = BFS(1);

	// second bfs to find actual longest path
	t2 = BFS(t1.first);

	cout << "Longest path is from " << t1.first << " to "
		<< t2.first << " of length " << t2.second;
}


int main() {
    // Graph as an Adjacency List with n vertices assuming that all vertex numbers are <= n and having `m` edges.
  
    int m; cin >> n >> m;
    int vertex, destination;

    for (int i = 0; i < m; i++){
            cin >> vertex >> destination;
            adj_list[vertex].push_back(destination);   
            adj_list[destination].push_back(vertex);  
    }

    longestPathLength();

    /*
    Sample Inputs:
    10
    9
    1 2
    2 7
    7 9
    7 8
    2 3
    3 4
    3 5
    5 6
    3 10
    ANS: 5
    -----
    6                                                                                      
    5
    1 3
    1 4
    1 2
    2 5
    2 6
    ANS: 3
    */

}


// Ref: https://www.geeksforgeeks.org/longest-path-undirected-tree/