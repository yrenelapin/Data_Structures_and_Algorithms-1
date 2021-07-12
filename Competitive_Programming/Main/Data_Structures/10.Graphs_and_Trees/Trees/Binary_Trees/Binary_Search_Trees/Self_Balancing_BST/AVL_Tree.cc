#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node *create_node(int data){
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = node->parent = NULL;
    return node;
}

// Understanding the below impl is easy if we draw the tree.
void leftRotate(struct Node* node){

    // Take the current node's right subtree's root ( Simply right child    ) 
    auto y = node->right;
   
    // Take the left child of the previous node (y).
    auto z = y->left;

    // Our main Node (being rotated) is going to be the Left child of y. 
    y->left = node;

    // The right child of Our main Node (being rotated) is z. 
    node->right = z;
    
    // update heights of node,y
}

void rightRotate(struct Node* node){

    auto y = node->left;
    auto z = y->right;

    y->right = node;
    node->left = z;
    
    // update heights of node,y
}

// Understanding the below impl is easy if we draw the tree.
void leftRightRotation(struct Node* node){
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

void rightLeftRotation(struct Node* node){
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

void delete_node(){

}

void balance_node(){

}

void insert_node(){

}