/*
Sponsoring a Gamer
There are N gamers numbered 1 to N looking for sponsors. Your friend is a gamer who knows the 
importance of Game Sense and wants to sponsor a gamer with maximum Game Sense. Unfortunately, 
there is no standard metric to measure it, and he only knows who has more Game Sense than who through comparisons.

A comparison is a pair [x, y] between two gamers which says gamer 'x' has lesser Game Sense than gamer 'y'. 
Given M comparisons of these N gamers, write a program to print gamers in non-increasing order according to their Game Sense rank.

Note: If there are more than one gamer with the same Game Sense rank, their order in the output should be lexicographically increasing.

Input
First line contains two space separated integers N and M.
In each of the next M lines contain two space separated integers representing a pair.

Output
Output contains N lines. In each line, there are two space integers representing the rank and the gamer.

Constraints
2 <= N, M <= 1000
*/

#include <bits/stdc++.h>
using namespace std;
int n = 1005;
vector< vector<int> > adj_list(n + 1); 
vector<bool> visited(n + 1, false);
vector<int> levels(n+1);
vector<pair<int,int>> result ;

void topological_sort() {
    
    vector<int> in_degree(n+1, 0);
    
    // Using Min Heap for Priority Queue, So that elements in the queue are firstly sorted in increasing
    // order based on rank & then if both have same rank, vertex with min value comes first.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    // store indegree of every vertex
    for (int i=1; i<=n; i++) {
        for (auto u : adj_list[i]) {
            in_degree[u]++;
        }
    }
   
    // push vertices with indegree 0 to queue
    for (int i=1; i<=n; i++) {
        if (in_degree[i]==0) {
            pq.push({1, i});  // ( rank, vertex )
            visited[i] = true;
        }
    }

    while (!pq.empty()) {
        int rank = pq.top().first;
        int vertex = pq.top().second; 
        cout << rank << " " << vertex << endl;
        pq.pop();
        for (auto i : adj_list[vertex]) {
            if (!visited[i]){
                if (--in_degree[i] == 0) {
                    pq.push({rank+1, i} );  // ( rank, vertex )
                    visited[i] = true;
                }
            }
        }
    }
    return;
}

int main(){
    int m, source, destination;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> source >> destination;
        // Notice this!
        adj_list[destination].push_back(source);
    }
    topological_sort();
    return 0;
}