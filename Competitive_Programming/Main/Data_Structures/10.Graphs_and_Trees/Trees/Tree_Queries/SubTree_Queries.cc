#include <bits/stdc++.h>
#define tra(ele,container) for(auto& (ele): (container))
using namespace std;

/*
Consider a problem where each node is assigned a value,
and our task is to support the following queries:
• update the value of a node
• calculate the sum of values in the subtree of a node.
*/

const int MAXN = 1e5;

int n = 9;

map<int, int> tree_traversal;

int i = 1;

void dfs(int s, int e, vector< vector<int> > &adj_list, vector<int> &subtree_size) {
    
    // Storing the position of the Node in the DFS Traversal.
    tree_traversal[s] = i;
    i++;


    // Initialising the subtree_size.
    subtree_size[s] = 1;
    for (auto u : adj_list[s]) {
        if (u != e) {
            dfs(u, s, adj_list, subtree_size);
            subtree_size[s] += subtree_size[u];
        }
    }

}

// Value of node `v` is at v[v-1]
vector<int> v(n);

vector<int> prefix_sum(n);
vector<int> tree(n+1);


// O(n)
void build_prefix(){

    for (int i = 0; i < v.size() ; i++){
        if (i == 0){
            prefix_sum[0] = v[0];
        }
        else prefix_sum[i] = v[i] + prefix_sum[i-1];
    }

}


int query(int start_index, int end_index){

    if (start_index == 0){
        return prefix_sum[end_index];
    }

    if (start_index == end_index){
        return v[start_index];
    }

    return (prefix_sum[end_index] -  prefix_sum[start_index-1]) ;
}


// O(n)
void binary_indexed_tree(){
    for (int k = 1; k <= n; k++){
        int p_k = k & (-k);
        int a =  k - p_k + 1;
        int b =  k;

        // Each position k contains the sum of values in a range of the original array whose length is p(k) and that ends at position k. 
        tree[k] = query(a-1,b-1);
    }
}


/* 
Binary Indexed Trees supports two O(logn) time operations on an array:
processing a range sum query and updating a value. */


//  Calculates value of sum_q(1,k)
int sum(int k) {
    int s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}


// Function increases the array value at position k by x (x can bepositive or negative):
void add(int k, int x) {

    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}

int main(){
        
    int m; cin >> m;
    int vertex, destination;
    vector< vector<int> > adj_list(n+1);
    for (int i = 0; i < m; i++){
            cin >> vertex >> destination;
            adj_list[vertex].push_back(destination);   
            adj_list[destination].push_back(vertex);
    }


    for (int i = 0; i < n ; i++){
        cin >> v[i];
    }

    // For each node s a value subtree_size[s] is the number of nodes in its subtree.
    vector<int> subtree_size(n+1);

    int start = 1;
    dfs(start, 0, adj_list, subtree_size);

   build_prefix();
    
    cout << "Given Array \t\t";
    tra(i,v){
        cout << i << " ";
    }
    cout << endl;

    cout << "Prefix Sum Array \t";
    tra(i,prefix_sum){
        cout << i << " ";
    }
    cout << endl;

   binary_indexed_tree();

   cout << "Binary Indexed Tree \t"; 
   tra(i,tree){
       cout << i << " ";
   }
    cout << endl;
    
    // add()
    

    // Sum Query [ calculate the sum of values in the subtree of a node 1 <= v <= n ]. It should be treated as v-1
    // Let v = 4.
    int pos_node = tree_traversal[4];
    int size_node = subtree_size[4];
    int l = pos_node;
    int r = l + size_node-1;

    cout << pos_node << " " << size_node << " " <<  l << " " << r << endl;
    cout << sum(r) - sum(l-1);

    // add(5,5);

    // cout << sum(r+1) - sum(l+1);

    //cout << sum(1,0,n-1, l, r) << endl;
    

    // // Update Query [ Update the value of a Node  1 <= v <= n ]. It should be treated as v-1
    // // Update value of a Node 4. --> `3` is the pos.
    // int pos = 3; int new_val = 5;
    // update(1,0,n-1, pos, new_val);
    

    // // Sum Query
    //  pos_node = tree_traversal[4];
    //  size_node = subtree_size[4];
    //  l = pos_node-1;
    //  r = l + size_node-1;
    // cout << sum(1,0,n-1, l, r) << endl;


    /* Sample Input:
    8
    1 2
    1 3
    1 4
    1 5
    2 6
    4 7
    4 8
    4 9
    2 3 5 3 1 4 4 3 1
    */   
}