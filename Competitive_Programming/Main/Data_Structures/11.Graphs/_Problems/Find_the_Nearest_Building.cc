/*

Find the Nearest Building
Given N buildings numbered 1 to N along with M routes between them, K of the given N buildings are hospitals. 
Your friend being a doctor, wants to stay in a building that is nearest (in the distance) to any one of the K hospitals. 
Help your friend to choose a building.

Note: If there are multiple routes between same two buildings, consider the route with minimum distance.

Input
First line contains three space separated integers N, M, and K.
Second line contains K space separated integers representing hospitals.
Next M lines contain three space separated integers A, B and C, where A and B represents a road (route) between building A and building B and C represents the distance between them.

Output
Print two space separated integers representing the building number and the minimum distance from it to a hospital.
Print -1 if no route exists from any building to a hospital.
If there are multiple buildings with same minimum distance to a hospital, choose the building with minimum number.
*/


#include<bits/stdc++.h>
using namespace std;

pair<int, int> bfs(const vector< vector< int > > &adj, int h, const set<int> &hospital)
{
    pair<int, int> minm = {-1, INT_MAX};
    int n = adj.size()-1;
    
    // Traversing all the adjacent buildings to the given hospital `h`.
    for(int i = 1; i < n+1; i++)
    {   
        // If the building (i) is adjacent & not a hospital &  Distance from this building to hosiptal h is less.
        if(adj[h][i] != INT_MAX && hospital.find(i) == hospital.end() && adj[h][i] < minm.second)
        {
            minm = {i, adj[h][i]};
        }
    }
    
    // Minimum among a given hospital.
    return minm;
}


pair<int, int> nearest_building(const vector< vector< int > > &adj, const set<int> &hospital)
{
    pair<int, int> ans = {-1, INT_MAX};
    
    for(auto h : hospital)
    { 
        // BFS for the hospital `h`.
        pair<int, int> temp = bfs(adj, h, hospital);
        
        // Minimum among all hospitals
        if(temp.second < ans.second)
        {
            ans = temp;
        }
        
        // If there are multiple buildings with same min. distance ,
        // We choose the building with min number.
        if (temp.second == ans.second){
            if (temp.first < ans.first){
                ans = temp;
            }
        }
    }
    
    return ans;
}


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    set<int> hospital;
    for(int i = 0; i < k; i++)
    {
        int j;
        cin >> j;
        hospital.insert(j);
    }
    
    
    // Whenever we have Weighted Graphs, better use the Adjacency Matrix. 
    // Filling the matrix with INT_MAX helps in taking the minimum distance.
    vector< vector< int > > adj(n+1, vector<int> (n+1, INT_MAX));
    
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        // This helps in storing only the minimum path between two vertices.
        adj[u][v] = min(adj[u][v], w);
        
        // Undirected Graph.
        adj[v][u] = adj[u][v]; 
    }
    
    pair<int, int> p = nearest_building(adj, hospital);
    
    if(p.first != -1)
    {
        cout << p.first << " " << p.second;
    }
    else
    {
        cout << "-1";
    }
    return 0;
}