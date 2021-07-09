#include <bits/stdc++.h>
using namespace std;

/*
You are given a tree consisting of n nodes.
The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.
[ Given an undirected tree, we need to find the longest path of this tree where a path is defined as a sequence of nodes ]
*/

int n =  2*(1e5) + 5;
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

	cout << t2.second;
}


int main(){

    cin >> n;
    if (n == 1){
        cout << 0;
        return 0;
    }
    int vertex, destination;
    for (int i = 1; i <= n-1; i++){
            cin >> vertex >> destination;  
            adj_list[vertex].push_back(destination);
            adj_list[destination].push_back(vertex);
    }

   longestPathLength();
}

// Ref: https://www.geeksforgeeks.org/longest-path-undirected-tree/