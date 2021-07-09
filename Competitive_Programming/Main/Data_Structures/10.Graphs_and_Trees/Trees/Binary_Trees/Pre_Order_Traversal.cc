#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers in Level-Order sequence, write a program to read input into an array and build a Complete Binary Tree.
and perform PRE ORDER TRAVERSAL
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
void preOrderTrav(struct Node* node) {
    if (node != NULL){
        cout << node->data << " ";
        preOrderTrav(node->left);
        preOrderTrav(node->right);
    }
}

// Iterative
void preOrderTrav_Iter(struct Node* node) {
    stack<struct Node*> nodeStack;
    nodeStack.push(node);
    while (!nodeStack.empty()){
        auto curr_node = nodeStack.top(); nodeStack.pop();
        if (curr_node != NULL){
            cout << curr_node->data << " ";
            nodeStack.push(curr_node->right);
            nodeStack.push(curr_node->left);
        }
    }
}

// -------------------------------------------------------------------------

int main(){
    vector<int> v = {1, 2, 3, 4, 5};

    struct Node* root = build_complete_bt(v,0);
    preOrderTrav(root); cout << endl;
    preOrderTrav_Iter(root); cout << endl;
    return 0;
}
