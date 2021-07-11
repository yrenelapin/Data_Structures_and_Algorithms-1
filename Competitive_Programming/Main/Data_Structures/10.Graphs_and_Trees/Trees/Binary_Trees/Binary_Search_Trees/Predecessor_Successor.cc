#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} *root = NULL;


int minimum(struct Node* node){
    while(node->left != NULL){
        node = node->left;
    }
    return node->data;
}

int maximum(struct Node* node){
    while(node->right != NULL){
        node = node->right;
    }
    return node->data;
}

// Successor of a node is the smallest node greater than the given node.
struct Node* successor(struct Node* node){   

    if (node->right != NULL){
        return minimum(node->right);
    }
    else{
        // If node has no right child: 

        // 1. If it is the Left child of its parent, ans is just its parent.
        auto y = node.parent;  

        // 2. If it is the right child of its parent, we go up until we find a node which is left child of its parent.  
        while(y != NULL and y.right == node){
            node = y;
            y = y.parent;
        }

        return y;
    }
}

// predecessor of a node is the largest node smaller than the given node.
struct Node* predecessor(struct Node* node){   

    if (node->left != NULL){
        return maximum(node->left);
    }
    else{
        // If node has no left child: 

        // 1. If it is the right child of its parent, ans is just its parent.
        auto y = node.parent;  

        // 2. If it is the left child of its parent, we go up until we find a node which is right child of its parent.  
        while(y != NULL and y.left == node){
            node = y;
            y = y.parent;
        }

        return y;
    }
}