#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers in Level-Order sequence where each number represents a node of a Binary Tree,
write a program to check if the nodes can form a Perfect Binary Tree.
*/

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node *create_node(int data){ 
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

// Recursive
struct Node* build_tree(vector<int> &v, int index){

    if (index >= v.size()){
        return NULL;
    }

    struct Node* root;
    if (v[index] != INT_MAX){
        root = create_node(v[index]);
    }
    else{
        root = NULL;
    }
    
    if (root != NULL){
        root->left = build_tree(v,2*index+1);
        root->right = build_tree(v,2*index+2);
    }
    return root;
}

//--------------------------------------------------------------------------

int depth_of_tree = 0;
// PREORDER TRAVERSAL
bool isPerfectBinary(struct Node* node, int level) {
    if (node == NULL){
        return true;
    }
    else if (node->right == NULL and node->left == NULL){
        // If it is a leaf node, all leaf nodes must be at the same level
        return (level+1 == depth_of_tree);
    }
    else if (node->right == NULL or node->left == NULL){
      return false;
    }
    else{
        auto left_check = isPerfectBinary(node->left, level+1);
        auto right_check = isPerfectBinary(node->right, level+1);
        return left_check and right_check;
    }
}

// Since we are building a complete binary tree,
// for finding depth, checking `left` nodes is sufficient! 
int depth(struct Node* node){
    int d = 0;
    while(node != NULL){
        d++;
        node = node->left;
    }
    return d;
}

int main(){
    vector<int> v; string tmp;
    while( cin >> tmp ){
        if (tmp != "null"){
            v.push_back(stoi(tmp));
        }
        else{
            v.push_back(INT_MAX);
        }
    }

    // Method 1
    // int N = v.size();
    // if ( ceil(log2(N+1)) == floor(log2(N+1)) ){
    //     cout << "True";
    // }
    // else{
    //     cout << "False";
    // }
    
    // Method 2
    struct Node* root = build_tree(v,0);
    depth_of_tree = depth(root);
    if ( isPerfectBinary(root, 0) ){
        cout << "True";
    }
    else{
        cout << "False";
    }
    return 0;
}
