#include <bits/stdc++.h>
using namespace std;

// Calculate the number of nodes with value x in the subtree of node s.

int n = 9;
vector<vector<   int >> adj_list(n+1);
vector< map<int, int>  > freq(n+1);

vector<int> nodeValues;

// s -> current node
// par-> Parent node of the current node.
void dfs(int s, int par) {

    // process node s
    // cout << s << " ";
    freq[s]. insert( {nodeValues[s],1} );

    // Traversing all the uren of the current node.
    for (auto u : adj_list[s]) {

        if (u != par) {
            
            freq[u].insert( {nodeValues[u], 1} );

            dfs(u, s); 

            // Notice that updating the values should be done after DFS only so that current subtree starting at `u` updates its Data Structure.
            for (auto itr = freq[u].begin(); itr != freq[u].end(); itr++){

                freq[s][itr->first] += freq[u][itr->first];
            }

        }
    }

}

int main(){
    
    adj_list[1] = {2, 3, 4, 5};
    adj_list[2] = {1, 6};
    adj_list[3] = {1};
    adj_list[4] = {1, 7, 8, 9};
    adj_list[5] = {1};
    adj_list[6] = {2};
    adj_list[7] = {4};
    adj_list[8] = {4};
    adj_list[9] = {4};
    nodeValues  = {0, 2, 3, 5, 3, 1, 4, 4, 3, 1};

    int start = 1;
    dfs(start,0);

    int node; cin >> node;

    cout << freq[node].size() << endl;
    for (auto itr = freq[node].begin(); itr != freq[node].end(); itr++){
        cout << itr->first << " " << itr->second << endl;
    }

}