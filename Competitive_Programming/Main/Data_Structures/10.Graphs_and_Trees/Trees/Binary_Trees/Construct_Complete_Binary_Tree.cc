#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers in Level-Order sequence, write a program to read input into an array and build a Complete Binary Tree.
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

//--------------------------------------------------------------------------

// Recursive
struct Node* build_complete_bt(vector<int> &v, int index){

    if (index >= v.size()){
        return NULL;
    }
    auto root = create_node(v[index]);
    root->left = build_complete_bt(v,2*index+1);
    root->right = build_complete_bt(v,2*index+2);
    return root;
}

// Iterative
struct Node* build_complete_bt_Iter(vector<int> &v, int index, struct Node* root){
    
    queue<struct Node*> nodeQueue;
    while (index < v.size()){

        auto node = create_node(v[index]);

        if (root == NULL){
            root = node;
        }
        else if ( nodeQueue.front()->left == NULL){
            // If left child of current node is available, use it. 
            nodeQueue.front()->left = node;
        }
        else{
            // If left child of current node is already used, use the right child & pop the parent node from Queue. 
             nodeQueue.front()->right = node;
             nodeQueue.pop();
        }
    
        nodeQueue.push(node);
        index++;

    }

    return root;
}

//--------------------------------------------------------------------------

void preOrderTrav(struct Node* node) {
    if (node != NULL){
        cout << node->data << " ";
        preOrderTrav(node->left);
        preOrderTrav(node->right);
    }
}

int main(){
    vector<int> v = {1,2,3,4,5};

    struct Node* root = build_complete_bt(v,0);
    //struct Node* root = build_complete_bt_Iter(v,0, NULL);
    preOrderTrav(root);
    return 0;
}
