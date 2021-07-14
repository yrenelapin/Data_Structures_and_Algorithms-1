#include <bits/stdc++.h>
using namespace std;

int n = 10001;
vector<bool> visited(n+1);
vector<int> color(n+1);
vector< vector<int> > adj (n + 1);

// DFS
bool isBipartite( int v, int col ){
    visited[v] = true;
    color[v] = col;
    for(auto child: adj[v]){
        
        if (!visited[child]){
             visited[child] = true;
             
             if (!isBipartite(child, !col)){
                 return 0;
             }
        }
        else{
            if (color[child] == color[v]){
                return 0;
            }
        }
    }
    
    return 1;
    
}

int main()
{
    int m;
    cin >> n >> m;
    int source, destination;
    for (int i = 0; i < m; i++)
    {
        cin >> source >> destination;
        adj[source].push_back(destination);
        adj[destination].push_back(source);
    }

    // Assuming input is connected graph.
    if (isBipartite(1, 1)) {
	    cout << "Yes";
    }
	else{ cout << "No";
	}

	return 0;
}
