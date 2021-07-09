/*
C++ program to print the complete DFS-traversal of graph using back-tracking

Ref: https://www.geeksforgeeks.org/print-the-dfs-traversal-step-wise-backtracking-also/
*/

#include <bits/stdc++.h>
using namespace std;

int n = 11;
vector<vector<int>> adj(n+1);
vector<bool> visited(n+1, false);

// Vector to track last visited road
vector<pair<int, int> > road_used;   // (parent, child)


// Function to print the complete DFS-traversal
void dfs(int u, int parent){

	int c = 0;
	// Count visited nodes.
	for (int i = 0; i < n; i++)
		if (visited[i])
			c++;

	// If all the nodes are visited.
	if (c == n)
		return;
    

    // As usual dfs step
	visited[u] = true;
	cout << u << " ";

	// Track the current edge
	road_used.push_back({ parent, u });

	// Check for not visited nodes and proceed with it.
	for (int x : adj[u]) {

		// call the DFs function if not visited
		if (!visited[x])
			dfs(x, u);
	}

	// After traversing all the adjacent nodes of curent node `u` (as shown above), Backtrack through the last visited nodes
	for (auto y : road_used)
		if (y.second == u)   // check who is my parent.
			dfs(y.first, u); // Now assume my parent (y.first) is my current child.     

}


// Function to insert edges in Graph
void insertEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Driver Code
int main()
{
	// Function call to create the graph
	insertEdge(0, 1);
	insertEdge(0, 2);
	insertEdge(1, 5);
	insertEdge(1, 6);
	insertEdge(2, 4);
	insertEdge(2, 9);
	insertEdge(6, 7);
	insertEdge(6, 8);
	insertEdge(7, 8);
	insertEdge(2, 3);
	insertEdge(3, 9);
	insertEdge(3, 10);
	insertEdge(9, 10);

	// Start from the node `0` & since it has no parent, pass `-1`
    dfs(0,-1);

    // For disconnected Graphs
    // for (int v = 0; v < n ; v++){
    //     if (!visited[v]){
    //         dfs(v, parent[v]);
    //     }
    // }
	
	return 0;
}
