/*
Given the structure of a company, your task is to calculate for each employee the number of their subordinates.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int s, int e, vector< vector<int> > &adj_list, vector<int> &counter) {
    
    // Initialising the counter.
    counter[s] = 1;
    for (auto u : adj_list[s]) {
        if (u != e) {
            dfs(u, s, adj_list, counter);
            counter[s] += counter[u];
        }
    }

}

int main(){
    // Tree as an Adjacency List with n vertices assuming that all vertex numbers are <= n and m edges.
   
    int n; cin >> n;
    int vertex, destination;
    vector< vector<int> > adj_list(n+1);
    for (int i = 0; i < n-1; i++){
            cin >> vertex;
            adj_list[i+2].push_back(vertex);   
            adj_list[vertex].push_back(i+2);
    }

    // For each node s a value counter[s] is the number of nodes in its subtree.
    vector<int> counter(n+1);

    int start = 1;
    dfs(start, 0, adj_list, counter);

    for(int i = 1; i <= n; i++){
        cout << counter[i]-1 << " ";
    }

}