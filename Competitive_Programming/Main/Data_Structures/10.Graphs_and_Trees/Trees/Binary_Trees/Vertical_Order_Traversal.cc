#include <bits/stdc++.h>
using namespace std;

/*
You are given a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.

Input: The input contains N space-separated elements which include integers and #(preorder traversal).

Note: 
- The # represents that there is no node in the corresponding location of the tree.
- In this particular representation, the leaf node is also treated as a subtree with two nulls 
as its children and these nulls are also represented using #. 
*/

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

vector<int> levels(1000005);
vector<int> horlevels(1000005);

void compute_levels(struct Node* node, int level){
    if (node){
        levels[node->data] = level;
        compute_levels(node->left,level+1);
        compute_levels(node->right, level+1);
    }
}

void compute_horlevels(struct Node* node, int level){
    if (node){
        horlevels[node->data] = level;
        compute_horlevels(node->left,level-1);
        compute_horlevels(node->right, level+1);
    }
}

vector<int> nodes;
Node *create()
{
    string val;
    cin >> val;
    if (val == "#")
        return NULL;
    Node *root = newNode(stoi(val));
    nodes.push_back(stoi(val));
    root->left = create();
    root->right = create();
    return root;
}

int main(){
	struct Node* root = create();
	compute_levels(root, 1);
	compute_horlevels(root,0);
    vector<vector<int>> data;
    for(auto i :nodes){
        data.push_back( { horlevels[i], levels[i], i } ); 
    }
    sort(data.begin(), data.end());
    for(auto e : data){
        cout << e[2] << " ";
    }
}