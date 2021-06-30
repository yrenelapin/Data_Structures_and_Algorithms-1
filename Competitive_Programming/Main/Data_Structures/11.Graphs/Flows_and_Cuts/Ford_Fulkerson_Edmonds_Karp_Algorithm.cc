#include <bits/stdc++.h>
using namespace std;

/*
The Edmonds-Karp algorithm is an implementation of the Ford-Fulkerson method for computing a maximal flow in a flow network.
It uses BFS for finding paths.
*/

const int INF = 1e9;
int n = 6;
vector<vector<int>> capacity(n+1, vector<int>(n+1));
vector<vector<int>> adj(n+1);

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
    int m; cin >> m;
    int vertex, destination, weight;
    for (int i = 0; i < m; i++){
            cin >> vertex >> destination >> weight;
            adj[vertex].push_back(destination);   
            capacity[vertex][destination] = weight;
            capacity[destination][vertex] = weight;
            adj[destination].push_back(vertex); 
    }

    // Print
    // for (int i = 1; i <= n; i++){
    //     cout << "Vertex " << i << " -> ";
    //     vector<int> a = adj[i];
    //     for (int j = 0; j < a.size(); j++){
    //         cout << a[j] << " ";
    //     }
    //     cout << endl;
    // }
    
    int s = 1;  // Source
    int t = 6;  // Sink
    cout << maxflow(s,t);
}