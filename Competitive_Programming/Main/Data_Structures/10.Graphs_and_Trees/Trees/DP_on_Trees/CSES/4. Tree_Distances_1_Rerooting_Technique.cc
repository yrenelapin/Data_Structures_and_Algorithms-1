/*
You are given a tree consisting of n nodes
Your task is to determine for each node the maximum distance to another node.

The below technique is also known as RE-ROOTING TECHNIQUE!
*/

#include <bits/stdc++.h>
using namespace std;

int n =  2*(1e5) + 5;
vector< vector<int> > adj_list(n+1);


// depth[i] : length of the longest simple path in subtree rooted at i that starts at i.  // we count no of edges in the path.
vector<int> depth(n); 

// ans[i] : Required answer for the node `i`
vector<int> ans(n); 

void eval_depth(int src, int par){

    for(int child : adj_list[src]){
        if(child != par){
            eval_depth(child, src);
            depth[src] = max( depth[src], 1 + depth[child]);
        }
    }

}

// We are finding the maximum distance from the node `s` whose parent is `par` & 
// the `par_ans` is the maximum distance from node `par` excluding the subtree rooted at `s`.

void dfs(int src, int par, int par_ans) {  
    
    vector<int> prefixMax, suffixMax;

    // get depth of child nodes.
    for(int child : adj_list[src]){
        if(child != par){

            prefixMax.push_back(depth[child]);
            suffixMax.push_back(depth[child]);
        }
    }

    // build prefix and suffix
    // prefixMax[i] contains the maximum among ( depth[child_1], depth[child_2], .... depth[child_i] )
    // suffixMax[i] contains the maximum among ( depth[child_i], depth[child_i+1], .... depth[child_last_child] )
    for(int i = 1; i < prefixMax.size(); i++)
        prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
    for(int i = (int)suffixMax.size() - 2; i >= 0; i--)
        suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);

    // eval ans for every child c_no
    int c_no = 0;
    for(int child : adj_list[src]){

        if(child != par){

            // To find ans for each child, we first need to ind par_ans & for it we have 2 options available

            // For 1st option, we neeed these two parts.
            int part_1 = (c_no == 0) ? INT_MIN : prefixMax[c_no - 1];
            int part_2 = (c_no == (int)suffixMax.size() - 1) ? INT_MIN : suffixMax[c_no + 1];
            
            // Maximum distance is in the subtree of the parent node itself. 
            // So, take Depth of the current subtree excluding current node & add 1.
            int op1 = 1 + max(part_1, part_2);

            // Maximum Distance is not in the subtree of the parent node. 
            // So, Go through its parent & use its maximum distance in the tree excluding the subtree rooted at current node
            int op2 = 1 + par_ans;

            int partial_ans = max( op1, op2 );
            
            dfs(child, src, partial_ans);

            c_no++;
        }
    }
 
    // eval ans for src
    // Again we just have 2 options, Go through the parent node (using par_ans) or just its depth.
    ans[src] = 1 + max(par_ans, (prefixMax.empty() ? -1 : prefixMax.back()));

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
    eval_depth(start,0);
    dfs(start, 0, -1);
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}