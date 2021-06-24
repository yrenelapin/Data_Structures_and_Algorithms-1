#include <bits/stdc++.h>
using namespace std;
#define N 8
vector<int> leaf(N,-1);

/*
For each node x:
• toLeaf(x): the maximum length of a path from x to any leaf
• maxLength(x): the maximum length of a path whose highest point is x
*/

int toLeaf(int s, int e, vector<vector<int>> &adj_list){

    // If its already calculated.
    if (leaf[s] >= 0)
        return leaf[s];

    // If there are no children for this node, It is a leaf by itself.
    else if (adj_list[s].empty()) {
        leaf[s] = 0;
        return leaf[s];
    }

    else {
        // to calculate toLeaf(x), we go through the children of x, choose a child c with maximum toLeaf(c) and add one to this value.

        int maximum = 0;
        for (auto u: adj_list[s]) {
            if (u == e) continue;
            maximum = max(maximum, toLeaf(u, e, adj_list));
        }

        leaf[s] = maximum + 1;
        return leaf[s];
    }
}

int maxLength(int s, int e, vector<vector<int>> &adj_list ){

    int maxLength = 0;

    // If there are no children for the node.
    if (adj_list[s].empty()) 
        return 0;
    
    // If only one child for the node.
    else if (adj_list[s].size() == 1)
        return 1 + toLeaf(adj_list[s][0], s, adj_list);

    else {
        //  we choose two distinct children a and b such that the sum toLeaf(a) + toLeaf(b) is maximum and add two to this sum.

        int a = 0, b = 0;

        for (auto u : adj_list[s]) {
            if (u == e) continue;
            int uLeaf = toLeaf(u, s, adj_list);

            if (uLeaf > a) {
                b = a;
                a = uLeaf;
            } 
            else if (uLeaf > b) {
                b = uLeaf;
            }
        }

        maxLength = a + b + 2;
    }

    return maxLength;
}

int main(){

    vector<vector<int>> adj_list(N);
    adj_list[1] = {2, 3, 4};
    adj_list[2] = {5, 6};
    adj_list[4] = {7};

    cout << "toLeaf(1): " << toLeaf(1, 0, adj_list) << endl;
    cout << "toLeaf(2): " << toLeaf(2, 0, adj_list) << endl;
    cout << "maxLength(1): " << maxLength(1, 0, adj_list) << endl;
    cout << "maxLength(2): " << maxLength(2, 0, adj_list) << endl;

    // Diamter is the maximum among all the maxLength values.
    int diam = INT_MIN;
    for(int i = 1; i < N; i++){
        diam = max(diam, maxLength(i, 0, adj_list) );
    } 
    cout << "Diameter -> " << diam;
}