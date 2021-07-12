#include <iostream>
#include <cstdlib>
#include <climits>
#include <queue>
using namespace std;

/*
Given an integer K and a list of numbers representing nodes along with "null" which represents NULL in Level-Order sequence,
write a program to construct a Binary Search Tree from this list and delete K from it using in-order predecessor.
*/
struct Node
{
    int data;
    struct Node *left, *right;
} * root;

struct Node *create_node(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

struct Node *remove_null_nodes(struct Node *root)
{
    if (root == NULL || root->data == INT_MAX)
        return NULL;

    root->left = remove_null_nodes(root->left);
    root->right = remove_null_nodes(root->right);

    return root;
}

struct Node *insert_node(struct Node *root, int value, queue<struct Node *> &queue)
{
    struct Node *new_node = create_node(value);
    if (root == NULL)
        root = new_node;
    else if (queue.front()->left == NULL)
        queue.front()->left = new_node;
    else
    {
        queue.front()->right = new_node;
        queue.pop();
    }

    if (value != INT_MAX)
        queue.push(new_node);
    return root;
}

void build_tree()
{
    string temp;
    queue<struct Node *> queue;
    while (cin >> temp)
    {
        if (temp == "null")
            root = insert_node(root, INT_MAX, queue);
        else
            root = insert_node(root, stoi(temp), queue);
    }
    root = remove_null_nodes(root);
}

void post_order_traversal(struct Node *node)
{
    if (node == NULL)
        return;
    
    post_order_traversal(node->left);
    post_order_traversal(node->right);
    cout << node->data << " ";
   
}

void deleteNode(Node *&root, int key)
{
    if (root == NULL)
        return;

    if (key < root->data)
        deleteNode(root->left, key);
    else if (key > root->data)
        deleteNode(root->right, key);
    else  
    // We found the node to be deleted i.e (key == root->data)
    {
        // Case 1: node to be deleted is a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        // Case 2: node to be deleted has two children
        else if (root->left && root->right)
        {
            // find its in-order predecessor node.
            // `predecessor` is the  largest element which is 
            // less than the current node. 
            Node *predecessor = root->left;
            // Looking for the largest element in its left subtree.
            while (predecessor->right != NULL)
                predecessor = predecessor->right;

            // Replace the current node with the predecessor.
            root->data = predecessor->data;

            // recursively delete the predecessor.
            deleteNode(root->left, predecessor->data);
        }

        // Case 3: node to be deleted has only one child
        else
        {
            // If left child exists, Take it else, use right child
            Node *child = (root->left) ? root->left : root->right;
            Node *node_to_delete = root;

            root = child;
            delete node_to_delete;
        }
    }
}


//-----------------------------------------------------------------------------------------------

/*

- If we are buliding the Binary Search Tree from the Scratch using a given list of numbers representing nodes, 
by inserting nodes into it from left-side of the lis with the first number in the list is root.
- We can use below approach using SUCCESSOR if we are asked to do so using Successors 
for deleting the node since we have Parent pointer also.
- Now since we are building the BST using the given LEVEL ORDER TRAVERSAL, we cant have parent pointer easily.
So we use diff approach as shown above. 



// Replaces subtree located at node1 with subtree located at node2
void BST_transplant(struct Node* root, struct Node* node1, struct Node* node2 ){
    if (node1->parent == NULL){
        root = node2;
    }
    else if (node1 == node1->parent->left){
        node1->parent->left = node2;
    }
    else{
        node1->parent->right = node2;
    }

    if (node2 != NULL){
        node2->parent = node1->parent;
    }
}

void BST_delete(struct Node* root, struct Node* node){

    if (node->left == NULL){
        BST_transplant(root, node, node->right);
    }
    else if (node->right == NULL){
        BST_transplant(root, node, node->left);
    }
    else{
        auto successor = minimum(node->right);
        if (successor->parent != node){
            BST_transplant(root, successor, successor->right);
            successor->right = node->right;
            successor->right->parent = successor;
        }
        BST_transplant(root, node, successor);
        successor->left = node->left;
        successor->left->parent = successor;
    }
}

// Recursive
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

*/
//-----------------------------------------------------------------------------------------------

int main()
{   
    int K;
    cin >> K;
    build_tree();
    deleteNode(root,K);
    // auto node = BST_search(root, K)l
    // BST_delete(root, node);
    post_order_traversal(root);
    return 0;
}