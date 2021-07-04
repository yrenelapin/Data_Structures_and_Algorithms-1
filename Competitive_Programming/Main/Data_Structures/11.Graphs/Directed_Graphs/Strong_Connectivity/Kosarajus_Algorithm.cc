#include <bits/stdc++.h>
using namespace std;

int n = 100, m;
vector<vector<int>> adj(n+1), adj_rev(n+1);
vector<bool> used;
vector<int> order, component;

//  Function dfs1 fills the list `order` with vertices in increasing order of their exit times (actually, it is making a reverse topological sort).
void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

// Function dfs2 stores all reached vertices in list `component`, that is going to store next strongly connected component after each run.
void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m ; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);          
        adj_rev[b].push_back(a);
    }

    used.assign(n+1, false);

    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());
    // Now `order` contains the topological sorting. 

    // Condensation Graph Implementation
    vector<int> roots(n+1, 0);
    vector<int> root_nodes;
    vector<vector<int>> adj_scc(n+1);

    for (auto v : order)
        if (!used[v]) {
            dfs2(v);

            // ... processing next component ...
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);

            component.clear();
        }


    for (int v = 1; v <= n; v++)
        for (auto u : adj[v]) {
            int root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v)
                adj_scc[root_v].push_back(root_u);
        }

    // Here, we have selected the root of each component as the first node in its list.
    // This node will represent its entire SCC [ Strongly Connected Component ] in the condensation graph.

    // root_nodes is the list of all root nodes (one per component) in the condensation graph.
    // adj_scc is the adjacency list of the root_nodes.

    // We can now traverse on adj_scc as our condensation graph, using only those nodes which belong to root_nodes.
    // roots[v] indicates the root node for the SCC to which node v belongs. 

    cout << "The roots of the strongly connected components in the component graph are :\n";
    for(auto i : root_nodes){
        cout << i << "\n";
    }
    // To get all the components, just perform a DFS starting from each node in the `root_nodes`.


    /*  Sample Input:
        7
        10 
        1 2
        2 1
        1 4
        5 4
        2 5
        3 2
        6 3
        6 5
        3 7
        7 6
    */
}