#include <bits/stdc++.h>
using namespace std;
#define N 8
vector<int> leaf(N,-1);

// This is failng in many test cases! (https://cses.fi/problemset/result/2474779/)
// Debug it. Use the code at (DP_on_Trees\CSES\3. Tree_Diameter_DP.cc) if required.

/*
For each node x:
• toLeaf(x): the maximum length of a path from x to any leaf
• maxLength(x): the maximum length of a path whose highest point is x
*/

// Recursive Memoisation on DFS. 
int toLeaf(int s, int e, vector<vector<int>> &adj_list){

    // If its already calculated.
    if (leaf[s] !=  -1)
        return leaf[s];

    // If there are no children for this node, It is a leaf by itself.
    if (adj_list[s].empty()) {
        leaf[s] = 0;
        return leaf[s];
    }
    else {
        // to calculate toLeaf(x), we go through the children of x, choose a child c with maximum toLeaf(c) and add one to this value.

        int maximum = 0;
        for (auto u: adj_list[s]) {
            if (u != e){   
                maximum = max(maximum, toLeaf(u, e, adj_list)); }       
        }

        leaf[s] = maximum + 1;
        return leaf[s];
    }
}

// We are just doing DFS.
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

        // a has the 1st maximum toLeaf & b has the 2nd maximum toLeaf. 
        int a = 0, b = 0;
        
        // vector<int> to_leaf = {0,0};

        for (auto u : adj_list[s]) {

            if (u != e){

                int uLeaf = toLeaf(u, s, adj_list);
                
                // to_leaf.push_back(uLeaf);
                
                // The below 7 lines are doing the same thing as shown by `to_leaf` vector but in an Efficient Way!
                if (uLeaf > a) {
                    b = a;
                    a = uLeaf;
                } 
                else if (uLeaf > b) {
                    b = uLeaf;
                }
            }
        }

        // sort(to_leaf.begin(), to_leaf.end());
        // reverse(to_leaf.begin(), to_leaf.end());
        // int a = to_leaf[0]; int b = to_leaf[1];
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

    // Diameter is the maximum among all the maxLength values.
    int diam = INT_MIN;
    for(int i = 1; i < N; i++){
        diam = max(diam, maxLength(i, 0, adj_list) );
    } 
    cout << "Diameter -> " << diam;
}