/*
Determine whether a given graph contains Hamiltonian Cycle or not. 
If it contains, then prints the path. 	

Input:
A 2D array graph[V][V] where V is the number of vertices in graph and graph[V][V] is adjacency matrix representation of the graph.
A value graph[i][j] is 1 if there is a direct edge from i to j, otherwise graph[i][j] is 0.

Output:
An array path[V] that should contain the Hamiltonian Path. path[i] should represent the ith vertex in the Hamiltonian Path. 
The code should also return false if there is no Hamiltonian Cycle in the graph.

Ref: https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/

O(n!)
*/

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 5

void printSolution(vector<int> &path){

	cout << "Solution Exists!, Following is one Hamiltonian Cycle \n";
	for (int i = 0; i < V; i++)
		cout << path[i] << " ";

	// Let us print the first vertex again to show the complete cycle.
	cout << path[0] << " " << endl;
}

/* A utility function to check if the vertex v can be added at index 'pos' in the Hamiltonian Cycle constructed so far */
bool isSafe(int v, bool graph[V][V], vector<int> &path, int pos){

	/* Check if this vertex is an adjacent
	vertex of the previously added vertex. */
	if (graph [path[pos - 1]][ v ] == 0)
		return false;

	/* Check if the vertex has already been included. 
    This step can be optimized by creating an array of size V */
	for (int i = 0; i < pos; i++)
		if (path[i] == v)
			return false;

	return true;
}

/* A recursive utility function to solve hamiltonian cycle problem */
bool hamCycleUtil(bool graph[V][V], vector<int> &path, int pos){

	// base case: If all vertices are included in Hamiltonian Cycle 
	if (pos == V){
        
		// And if there is an edge from the last included vertex to the first vertex
		if (graph[path[pos - 1]][path[0]] == 1)
			return true;
		else
			return false;
	}

	// Try different vertices as a next candidate in Hamiltonian Cycle. 
	for (int v = 0; v < V; v++){

		/* Check if this vertex can be added to Hamiltonian Cycle */
		if (isSafe(v, graph, path, pos)){

			path[pos] = v;

			/* recur to construct rest of the path */
			if (hamCycleUtil (graph, path, pos + 1) == true)
				return true;

			/* If adding vertex v doesn't lead to a solution, then remove it */
			path[pos] = -1;
		}
	}

	/* If no vertex can be added to Hamiltonian Cycle constructed so far, then return false */
	return false;
}


/* 
This function solves the Hamiltonian Cycle problem using Backtracking. It mainly uses hamCycleUtil() to solve the problem. 
It returns false if there is no Hamiltonian Cycle possible, otherwise return true and prints the path. 
Please note that there may be more than one solutions, this function prints one of the feasible solutions.
*/
bool hamCycle(bool graph[V][V]){

    vector<int> path(V,-1);

	/* Let us put vertex 1 as the first vertex in the path.
	If there is a Hamiltonian Cycle, then the path can be
	started from any point of the cycle as the graph is undirected */

    int start = 1;
	path[0] = start;

	if (hamCycleUtil(graph, path, 1) == false )
	{
		cout << "\nSolution does not exist";
		return false;
	}

	printSolution(path);
	return true;
}



int main(){
	bool graph1[V][V] = {{0, 1, 0, 1, 0},
						{1, 0, 1, 1, 1},
						{0, 1, 0, 0, 1},
						{1, 1, 0, 0, 1},
						{0, 1, 1, 1, 0}};
	
	// Print the solution
	hamCycle(graph1);

	bool graph2[V][V] = {{0, 1, 0, 1, 0},
						{1, 0, 1, 1, 1},
						{0, 1, 0, 0, 1},
						{1, 1, 0, 0, 0},
						{0, 1, 1, 0, 0}};

	// Print the solution
	hamCycle(graph2);

	return 0;
}