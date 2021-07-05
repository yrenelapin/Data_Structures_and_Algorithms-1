#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> tree_traversal;

int n = 8;
vector<vector<int>> adj(n+1);
vector<bool> visited(n+1, false);

// Vector to track last visited road
vector<pair<int, int> > road_used;   // (parent, child)


// Function to print the complete DFS-traversal
void dfs(int u, int parent){

	int c = 0;
	// Count visited nodes.
	for (int i = 1; i <= n; i++)
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

		// call the DFS function if not visited
		if (!visited[x])
			dfs(x, u);
	}

	// After traversing all the adjacent nodes of curent node `u` (as shown above), Backtrack through the last visited nodes
	for (auto y : road_used)
		if (y.second == u)   // check who is my parent.
			dfs(y.first, u); // Now assume my parent (y.first) is my current child.     

}


vector<int> parent;

void lowest_comm_anc(int node1, int node2){

}


int main(){

    adj[1] = {2, 3, 4};
    adj[2] = {1, 5, 6};
    adj[4] = {1, 7};
    adj[3] = {1};
    adj[5] = {2};
    adj[6] = {2, 8};
    adj[7] = {4};
    adj[8] = {6};

    // // parent of node `1` is assumed `0`. 
    // parent = {0,0,1,1,1,2,2,4,6};
     
    dfs(1,0);

    // for(int i = 0; i < tree_traversal.size(); i++){
    //     cout << tree_traversal[i].first << " " << tree_traversal[i].second <<  endl;
    // }
   
    // int node1, node2;
    // cin >> node1 >> node2;
    // lowest_comm_anc(node1,node2);
}
