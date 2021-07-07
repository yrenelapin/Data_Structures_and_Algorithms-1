/*
You are given a tree consisting of n nodes.
The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.
*/

#include <bits/stdc++.h>
using namespace std;

int n =  2*(1e5) + 5;
vector< vector<int> > adj_list(n+1);

/*
Crucial observation for DP solution:

Note that for the diameter of the tree rooted at node `u`, We just have 2 possible options:

-> Diameter of the Tree passes through the root node `u`.
  In this case, answer is found by inding the downpaths which inturn can be computed recursively. 

-> Diameter of the Tree does not pass through the root node `u`. 
   In this case, answer is just the maximum diameter of subtrees rooted at its children. So we got similiar subproblem. 
*/


// downpath[i] : length of the longest simple path in subtree rooted at i that starts at i.  
// we count no of edges in the path. It is exactly same as depth of node `i`.
vector<int> downpath(n); 

// diameter[i] : what is diameter if path pass through node `i` for the subtree rooted at node `i`
vector<int> diameter(n); 

void eval_downpaths(int s, int par) {

    for (auto child : adj_list[s]) {
        if (child != par) {

            // This makes sure that by the time we calculate the answer for a node, All its children answers are calculated.
            eval_downpaths(child, s);  

            downpath[s] = max(downpath[s],  1 + downpath[child] );
        }
    }
}


// Each time this function is called, It finds the diameter of a subtree rooted at `s`
void dfs(int s, int par) {  
    
     // This stores the diameter for the current subtree if none of the edge having `s` as node is included. 
    int ans = 0; 

    vector<int> childrenDownPaths;
    for (auto child : adj_list[s]) {
        if (child != par) {
            

            // This makes sure that by the time we calculate the answer for a node, All its children answers are calculated.
            dfs(child, s);  
            childrenDownPaths.push_back(downpath[child]);
            ans = max(ans, diameter[child]);
        }
    }
   
    sort(childrenDownPaths.begin(), childrenDownPaths.end());

    int noOfChild = childrenDownPaths.size();
    if (noOfChild == 0){
        diameter[s] = 0;
    }
    else if (noOfChild == 1){
        diameter[s] = 1 + childrenDownPaths[0];
    }
    else{
        diameter[s] = 2 + childrenDownPaths[noOfChild-1] + childrenDownPaths[noOfChild-2];
    }

    diameter[s] = max(ans, diameter[s]);
    
}

int main(){
    
    cin >> n;
    int vertex, destination;
    for (int i = 1; i <= n-1; i++){
            cin >> vertex >> destination;
            adj_list[destination].push_back(vertex);   
            adj_list[vertex].push_back(destination);
    }

    int start = 1;
    eval_downpaths(start,0);
    dfs(start, 0);

    cout << diameter[1];
}