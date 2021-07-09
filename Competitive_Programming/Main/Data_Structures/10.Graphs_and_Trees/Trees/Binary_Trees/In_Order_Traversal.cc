#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers in Level-Order sequence, write a program to read input into an array and build a Complete Binary Tree.
and perform IN ORDER TRAVERSAL
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

struct Node* build_complete_bt(vector<int> &v, int index){

    if (index >= v.size()){
        return NULL;
    }

    auto root = create_node(v[index]);
    root->left = build_complete_bt(v,2*index+1);
    root->right = build_complete_bt(v,2*index+2);
    return root;
}

// -------------------------------------------------------------------------

// Recursive
void inOrderTrav(struct Node* node) {
    if (node != NULL){
        inOrderTrav(node->left);
        cout << node->data << " ";
        inOrderTrav(node->right);
    }
}

// Iterative
void inOrderTrav_Iter(struct Node* node) {
    stack<struct Node*> nodeStack;
    while ( node != NULL or !nodeStack.empty()){

        while (node != NULL){  // Store the current node & traverse the left subtree.
            nodeStack.push(node);
            node = node->left;
        }
        
        auto curr_node = nodeStack.top(); nodeStack.pop();
        cout << curr_node->data << " "; 
         
        node = curr_node->right;  // Traverse the right subtree.
    }
}


// -------------------------------------------------------------------------

int main(){
    vector<int> v = {1, 2, 3, 4, 5};

    struct Node* root = build_complete_bt(v,0);
    inOrderTrav(root); cout << endl;
    inOrderTrav_Iter(root); cout << endl;
    return 0;
}
