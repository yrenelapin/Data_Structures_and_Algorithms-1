#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers in Level-Order sequence, write a program to read input into an array and build a Complete Binary Tree.
and perform POST ORDER TRAVERSAL
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
void postOrderTrav(struct Node* node) {
    if (node != NULL){
        postOrderTrav(node->left);
        postOrderTrav(node->right);
        cout << node->data << " ";
    }
}

struct Node* peek(stack<struct Node*>  stack){
    if (stack.empty())
        return NULL;
    return stack.top();  // Performinf .top() on empty stack returns error!
}
 

// Iterative
void postOrderTrav_Iter(struct Node* node) {

    stack<struct Node*> stack; 

    if (node == NULL)
        return;

    do{
        // Move to leftmost node
        while (node){

            // Push node's right child and then node to stack.
            if (node->right)
                stack.push(node->right);
            stack.push(node);
 
            // Set node as node's left child
            node = node->left;
        }
 
        // Pop an item from stack and set it as node    
        node = stack.top(); stack.pop();
 
        // If the popped item has a right child and the right child is not
        // processed yet ( It means its still in the stack ), then make sure right child is processed before node
        if ( node->right && peek(stack) == node->right){
                stack.pop();        // remove right child from stack
                stack.push(node);   // push node back to stack
                node = node->right; // change node so that the right child is processed next
        }

        else{
            printf("%d ", node->data);
            node = NULL;
        }

    } while (!stack.empty());

}

// -------------------------------------------------------------------------

int main(){
    vector<int> v = {1, 2, 3, 4, 5};

    struct Node* root = build_complete_bt(v,0);
    postOrderTrav(root); cout << endl;
    postOrderTrav_Iter(root); cout << endl;
    return 0;
}
