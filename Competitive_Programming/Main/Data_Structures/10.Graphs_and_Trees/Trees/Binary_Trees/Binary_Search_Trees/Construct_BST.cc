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

// Recursive 
void BST_insert(struct Node* &node, struct Node* InsertNode){

    if (node == NULL){
        node = InsertNode;
    }
    else if (node->data < InsertNode->data){
        BST_insert(node->right, InsertNode);
    }
    else{
        BST_insert(node->left, InsertNode);
    }
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
 

// Iterative with Parent Pointer
struct Node* BST_insert_Iter(struct Node* &root, int value){
 
    Node* newnode = create_node(value);
 
    // Pointer to start traversing from root and
    // traverses downward path to search where the new node to be inserted
    Node* x = root;
 
    // Pointer y maintains the trailing pointer of x
    Node* y = NULL;
 
    while (x != NULL) {
        y = x;
        if (value < x->data)
            x = x->left;
        else
            x = x->right;
    }
     
     newnode->parent  = y;
    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (y == NULL)
        y = newnode;
 
    // If the new data is less then the leaf node data
    // Assign the new node to be its left child
    else if (value < y->data)
        y->left = newnode;
 
    // else assign the new node its right child
    else
        y->right = newnode;
 
    // Returns the pointer where the new node is inserted
    return y;
}

void postorder_traverse(Node *root) {
    if ( root != NULL){
        postorder_traverse(root->left);
        postorder_traverse(root->right);
        cout << root->data << " ";
        
        // if (root->parent != NULL)
        //     cout << root->data << " " << root->parent->data << endl;
        // else {
        //       cout << root->data << " " << " "  << endl;
        // }
    }
}

int main(){

    // Taking the Input.
    int temp;
    vector<int> v;
    while (cin >> temp){
        v.push_back(temp);
    }
    struct Node* root = NULL;
    
    // Creating Nodes & Inserting in a BST accordingly.
    for (int i = 0; i< v.size(); i++){
        
        //   M1 - Recursive without PARENT
        //   auto node = create_node(v[i]);
        //   BST_insert(root, node); 
         
        //   M2 - Recursive with PARENT
           root = BST_insert_p(root, v[i] );
    }
    
    // M3 - Iterative with PARENT:
    // struct Node* root = NULL;
    // root = BST_insert_Iter(root, v[0]);
    // for (int i = 1; i< v.size(); i++){
    //       BST_insert_Iter(root, v[i]);
    //  }
    
    postorder_traverse(root);
    return 0;
}