/*
You are given a tree consisting of n nodes.
A matching is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?
*/

#include <bits/stdc++.h>
using namespace std;

int n =  2*(1e5) + 5;
vector< vector<int> > dp(n+1, vector<int>(2));

// dp[v][0] -> Maximum matching we can get from the tree rooted at `v` by not including any  adjacent edge of `v`
// dp[v][1] -> Maximum matching we can get from the tree rooted at `v` by including any one of the adjacent edge of `v`

vector< vector<int> > adj_list(n+1);

void dfs(int s, int par) {
    
    bool leaf = 1;
    for (auto child : adj_list[s]) {
        if (child != par) {
            leaf = 0;
            dfs(child, s);  // This makes sure that by the time we calculate the answer for a node, All its children answers are calculated.
        }
    }

    if (leaf){
        return;   // dp[s][0] = 0, dp[s][1] = 0.  Since there are no children for the node, It means no adjacent node except its parent.
    }

    // Constructing the prefix & suffix sums of the child nodes answers of the current node.
    vector<int> prefix, suffix;
    for (int child : adj_list[s]) {
        if (child != par) {

            // Pushing the answers of each child into the vectors.
            prefix.push_back(max(dp[child][0], dp[child][1]));
            suffix.push_back(max(dp[child][0], dp[child][1]));
        }
    }

    for(int i = 1; i <= prefix.size()-1; i++){
        prefix[i] += prefix[i-1];
    }

    for(int i = suffix.size()-2; i >= 0; i--){
        suffix[i] += suffix[i+1];
    }

    // finding the value of dp[s][0]
    dp[s][0] = suffix[0];


    // finding the value of dp[s][1] by taking maximum among all the cases where child_cno's edge is taken. 
    int c_no = 0;
    for(int child : adj_list[s]){

        if ( child == par )
            continue;
 
        int leftChildren = (c_no == 0) ? 0 : prefix[c_no - 1];
        int rightChildren = (c_no == (int)suffix.size() - 1) ? 0 : suffix[c_no + 1];
 
        dp[s][1] = max(dp[s][1], 1 + leftChildren + rightChildren + dp[child][0]);

        c_no++;
    }
    
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
    dfs(start, 0);

    cout << max(dp[1][0], dp[1][1]);
}