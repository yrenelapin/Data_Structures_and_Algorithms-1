#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right; 
    struct Node* parent;
} *root = NULL;

struct Node *create_node(int data){

    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = node->parent = NULL;
    return node;
}

Node *remove_null_nodes(Node *root)
{
    if (root == NULL || root->data == INT_MAX)
        return NULL;

    root->left = remove_null_nodes(root->left);
    root->right = remove_null_nodes(root->right);

    return root;
}

Node *insert_node(Node *root, int value, queue<Node *> &queue)
{
    Node *new_node = create_node(value);
    if (root == NULL)
        root = new_node;
    else if (queue.front()->left == NULL)
       { queue.front()->left = new_node;
          new_node->parent = queue.front();
       }
    else
    {
        queue.front()->right = new_node;
        new_node->parent = queue.front();
        queue.pop();
    }

    if (value != INT_MAX)
        queue.push(new_node);
    return root;
}

void build_tree(struct Node **root){
    int temp; 
    queue<Node *> queue;
    while (cin >> temp){
        if (temp == -1)
            *root = insert_node(*root, INT_MAX, queue);
        else{
            *root = insert_node(*root, temp, queue);
        }
    }
    *root = remove_null_nodes(*root);
    return;
}

// Recursive
void inOrderTrav(struct Node* node) {
    if (node != NULL){
        
        inOrderTrav(node->left);
       
        if (node->parent){
            cout << node->data << " " << node->parent->data << endl;
        }
        else{
              cout << node->data << endl;
        }

        inOrderTrav(node->right);
    }
}

int main(){
    build_tree(&root);
    inOrderTrav(root);
    return 0;
}