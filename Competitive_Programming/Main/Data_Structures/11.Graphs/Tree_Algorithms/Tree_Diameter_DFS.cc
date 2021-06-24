#include <bits/stdc++.h>
using namespace std;

// Ref: https://www.geeksforgeeks.org/diameter-tree-using-dfs/

// Used to track farthest node.
int x;

// O(|V| + |E|)
void DFS(int vertex,  int count, vector<bool> visited, int &max_count, vector< vector<int> > &adj_list){

    visited[vertex] = true; 
    count++;
    //cout << vertex << " ";   // Process the node here.

    for (auto i : adj_list[vertex]){
        if (!visited[i]){

            if (count >= max_count){
                max_count = count;
                x = i;
            }

            DFS(i, count, visited, max_count, adj_list );
        }
    }
}


int diameter(vector<vector<int>> &adj, int n){

    int maxCount = INT_MIN;
  
    /* DFS from a random node and then see
    farthest node X from it*/
    vector<bool> visited(n+1, false);
    int count = 0;
    DFS(1, count+1, visited, maxCount, adj );


    /* DFS from X and check the farthest node
    from it */
    vector<bool> copy_(n+1, false);
    visited = copy_; count = 0;
    // Increment count by 1 for visited node
    DFS(x, count+1, visited, maxCount, adj );

    return maxCount;
}

int main(){ 
    int n = 7;
    vector<vector<int>> adj_list(n+1);
    adj_list[1] = {2, 3, 4};
    adj_list[2] = {5, 6};
    adj_list[4] = {7};

    cout << "Diameter -> " << diameter(adj_list, n);
}

