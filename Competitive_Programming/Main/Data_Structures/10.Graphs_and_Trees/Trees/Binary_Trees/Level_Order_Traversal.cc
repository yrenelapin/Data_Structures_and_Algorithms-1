#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers in Level-Order sequence, write a program to read input into an array and build a Complete Binary Tree.
and perform LEVEL ORDER TRAVERSAL
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


// Iterative
void levelOrderTrav_Iter(struct Node* node) {
    
    queue<struct Node*> nodeQueue;
    nodeQueue.push(node);

    while (!nodeQueue.empty()){
        auto curr_node = nodeQueue.front();
        nodeQueue.pop();
        cout << curr_node->data << " ";
        if(curr_node->left != NULL)
            nodeQueue.push(curr_node->left);
        if(curr_node->right != NULL)
            nodeQueue.push(curr_node->right);
    }
}


// -------------------------------------------------------------------------

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    struct Node* root = build_complete_bt(v,0);
    levelOrderTrav_Iter(root); cout << endl;
    return 0;
}
