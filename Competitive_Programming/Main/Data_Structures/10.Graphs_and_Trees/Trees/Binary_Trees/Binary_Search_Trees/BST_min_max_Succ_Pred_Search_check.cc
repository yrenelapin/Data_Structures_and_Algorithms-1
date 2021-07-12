#include<bits/stdc++.h>
using namespace std;

// Given a list of numbers representing nodes, 
// We constructed the Binary Search Tree by inserting nodes into it from left-side of the list.
// Note: The first number in the list is root.

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


struct Node*  minimum(struct Node* node){
    while(node->left != NULL){
        node = node->left;
    }   
    return node;
}

struct Node*  maximum(struct Node* node){
    while(node->right != NULL){
        node = node->right;
    }
    return node;
}

// Successor of a node is the smallest node greater than the given node.
struct Node* successor(struct Node* node){   

    if (node->right != NULL){
        return minimum(node->right);
    }
    else{
        // If node has no right child: 

        // 1. If it is the Left child of its parent, ans is just its parent.
        auto y = node->parent;  

        // 2. If it is the right child of its parent, we go up until we find a node which is left child of its parent.  
        while(y != NULL and y->right == node){
            node = y;
            y = y->parent;
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
        auto y = node->parent;  

        // 2. If it is the left child of its parent, we go up until we find a node which is right child of its parent.  
        while(y != NULL and y->left == node){
            node = y;
            y = y->parent;
        }

        return y;
    }
}

// Recursive, returns pointer to the node with given value.
struct Node* BST_search(struct Node* node, int value){

    if (node == NULL or node->data == value){
        return node;
    }
    else if (node->data < value){
        return BST_search(node->right, value);
    }
    else{
        return BST_search(node->left, value);
    }
}

// Iterative, returns pointer to the node with given value.
struct Node* BST_search_Iter(struct Node* node, int value){

    if (node == NULL){
        return NULL;
    }
    while(node != NULL){

        if (node->data == value){
            return node;
        }
        else if (node->data < value){
            node = node->right;
        }
        else{
            node = node->left;
        }

    }
    return NULL; 
}


// Recursive with Parent Pointer
struct Node* BST_insert_p(struct Node* node, int value){

    // If the tree is empty, return a new Node.
    if (node == NULL) 
        return create_node(value);
 
    if (value < node->data){

        auto lchild = BST_insert_p(node->left, value);
        node->left  = lchild;
 
        // Set parent of root of left subtree
        lchild->parent = node;
    }

    else if (value > node->data){

        auto rchild = BST_insert_p(node->right, value);
        node->right  = rchild;
 
        // Set parent of root of right subtree
        rchild->parent = node;
    }
 
    /* return the (unchanged) Node pointer */
    return node;
}
 

bool isBST(struct Node* node, int min, int max){
    
    // An empty binary tree is BST too!
    if (node == NULL){
        return true;
    }

    //  Check if current node's data is within range.
    if (node->data < min or node->data > max){
        return false;
    }

    // We have added +1, -1 since we are assuming all elements to be unique in our BST.
    return isBST(node->left, min, node->data-1) and isBST(node->right, node->data+1, max );

}

int main(){

    // Taking the Input.
    int temp;

    // Example from iB-Hubs Slides
    vector<int> v = {6,2,7,1,4,8,3,5}; 

    struct Node* root = NULL;
    
    // Creating Nodes & Inserting in a BST accordingly.
    for (int i = 0; i< v.size(); i++){
        root = BST_insert_p(root, v[i] );
    }

    // Testing

    cout << successor(root->left)->data << endl;
    cout << successor(root->right)->data << endl;
    cout << predecessor(root->left)->data << endl;
    cout << predecessor(root->right)->data << endl;

    cout << BST_search(root, 4)->parent->left->data << endl;
    cout << BST_search_Iter(root, 5)->parent->data << endl;

    return 0;
}