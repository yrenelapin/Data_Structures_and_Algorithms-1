#include <bits/stdc++.h>
using namespace std;

/*
You are given a list of values representing nodes along in the pre-order sequence of a binary tree, 
write a program to return the zigzag level order traversal of its node's values.
(i.e., from left to right, then right to the left for the next level and alternate between).

Input: The input contains N space-separated elements which include integers and #.

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
map<int,vector<int>> levelstore; 

// Iterative
void levelOrderTrav_Iter(struct Node* node) {
    queue<struct Node*> nodeQueue;
    nodeQueue.push(node);
    while (!nodeQueue.empty()){
        auto curr_node = nodeQueue.front();
        nodeQueue.pop();
        levelstore[levels[curr_node->data]].push_back(curr_node->data);
        if(curr_node->left != NULL)
            nodeQueue.push(curr_node->left);
        if(curr_node->right != NULL)
            nodeQueue.push(curr_node->right);
    }
}

void compute_levels(struct Node* node, int level){
    if (node){
        levels[node->data] = level;
        compute_levels(node->left,level+1);
        compute_levels(node->right, level+1);
    }
}

Node *create()
{
    string val;
    cin >> val;
    if (val == "#")
        return NULL;
    Node *root = newNode(stoi(val));
    root->left = create();
    root->right = create();
    return root;
}

int main(){
	struct Node* root = create();
	compute_levels(root, 1);
	
    levelOrderTrav_Iter(root);
    
    for(auto i: levelstore){
        if (i.first%2 == 1){
            for(auto j : i.second){
                cout << j << " ";
            }
        }
        else{
            reverse(i.second.begin(), i.second.end());
            for(auto j : i.second){
                cout << j << " ";
            }
        }
    }
}
