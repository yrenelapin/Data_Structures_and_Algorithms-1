// Ref : https://www.geeksforgeeks.org/check-if-a-given-graph-is-bipartite-using-dfs/ 

// C++ program to check if a "connected"
// graph is bipartite or not using DFS
#include <bits/stdc++.h>
using namespace std;


// function to check whether a graph is bipartite or not
bool isBipartite(vector< vector<int> >adj, int v,
				vector<bool>& visited, vector<int>& color)
{

	for (int u : adj[v]) {

		// if vertex u is not explored before
		if (visited[u] == false) {

			// mark present vertic as visited
			visited[u] = true;

			// mark its color opposite to its parent
			color[u] = !color[v];

			// if the subtree rooted at vertex v is not bipartite
			if (!isBipartite(adj, u, visited, color))
				return false;
		}

		// if two adjacent are colored with same color then
		// the graph is not bipartite
		else if (color[u] == color[v])
			return false;
	}
	return true;
}

// Driver Code
int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<int> > adj (n + 1);

    int source, destination;
    for (int i = 0; i < m; i++)
    {
        cin >> source >> destination;
        adj[source].push_back(destination);
        adj[destination].push_back(source);
    }


	// to keep a check on whether
	// a node is discovered or not
	vector<bool> visited(n + 1);

	// to color the vertices
	// of graph with 2 color
	vector<int> color(n + 1);


	// marking the source node as visited
	visited[1] = true;

	// marking the source node with a color
	color[1] = 0;

	// Function to check if the graph
	// is Bipartite or not.

    // Since this is for Connected Graphs, We need not try with all the vertices as Source.
	if (isBipartite(adj, 1, visited, color)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
