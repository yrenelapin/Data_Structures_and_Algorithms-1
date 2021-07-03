// For every node in the tree the maximum length of a path that begins at the node.
// This is working only for DIRECTED TREES!

#include <bits/stdc++.h>
using namespace std;
#define N 8
vector<int> leaf(N,-1);

/*
For each node x:
• maxLength1(x): the maximum length of a path from x. (same as toLeaf function used in Diameter)
*/

// Recursive Memoisation on DFS. 
int maxLength1(int s, int e, vector<vector<int>> &adj_list){

    // If its already calculated.
    if (leaf[s] !=  -1)
        return leaf[s];

    // If there are no children for this node, It is a leaf by itself.
    if (adj_list[s].empty()) {
        leaf[s] = 0;
        return leaf[s];
    }
    else {
        // to calculate maxLength1(x), we go through the children of x, choose a child c with maximum maxLength1(c) and add one to this value.

        int maximum = 0;
        for (auto u: adj_list[s]) {
            if (u != e){   
                maximum = max(maximum, maxLength1(u, e, adj_list)); }       
        }

        leaf[s] = maximum + 1;
        return leaf[s];
    }
}


int maxLength2(int s, int e, vector<vector<int>> &adj_list){

    // If its already calculated.
    if (leaf[s] !=  -1)
        return leaf[s];

    // If there are no children for this node, It is a leaf by itself.
    if (adj_list[s].empty()) {
        leaf[s] = 0;
        return leaf[s];
    }
    else {
        // to calculate maxLength1(x), we go through the children of x, choose a child c with maximum maxLength1(c) and add one to this value.

        int maximum = 0;
        for (auto u: adj_list[s]) {
            if (u != e){   
                maximum = max(maximum, maxLength1(u, e, adj_list)); }       
        }

        leaf[s] = maximum + 1;
        return leaf[s];
    }
}



int main(){

    vector<vector<int>> adj_list(N);
    adj_list[1] = {2, 3, 4};
    adj_list[2] = {5, 6};

    for (int v = 1; v <= N; v++){
          cout << "maxLength1(): of " << v << " " << maxLength1(v, 0, adj_list) << endl;
    }
  
}