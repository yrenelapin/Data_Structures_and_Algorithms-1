#include <iostream>
using namespace std;

/*
Given an integer K and a list of numbers representing nodes of an AVL tree except "null" which represents
NULL in Level-Order sequence, write a program to construct the AVL tree and delete K from it.
Note: The tree should self-balance itself after deletion.
*/

struct Node
{
    int data, height;
    Node *left, *right;
} * root;

// Calculate height
int get_height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

Node *get_new_node(int &data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *node)
{
    Node *pivot = node->left;
    Node *temp = pivot->right;
    pivot->right = node;
    node->left = temp;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    pivot->height = max(get_height(pivot->left), get_height(pivot->right)) + 1;
    return pivot;
}

Node *leftRotate(Node *node)
{
    Node *pivot = node->right;
    Node *temp = pivot->left;
    pivot->left = node;
    node->right = temp;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    pivot->height = max(get_height(pivot->left), get_height(pivot->right)) + 1;
    return pivot;
}

int get_balance_factor(Node *node)
{
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

Node *insertNode(Node *node, int data)
{
    if (node == NULL)
        return (get_new_node(data));
    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node;

    // balance the tree
    node->height = 1 + max(get_height(node->left), get_height(node->right));
    int balanceFactor = get_balance_factor(node);
    if (balanceFactor > 1)
    {
        if (data < node->left->data)
        {
            return rightRotate(node);
        }
        else if (data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1)
    {
        if (data > node->right->data)
        {
            return leftRotate(node);
        }
        else if (data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

void build_tree(Node **root)
{
    string temp;
    while (cin >> temp)
    {
        if (temp != "null")
            *root = insertNode(*root, stoi(temp));
    }
    return;
}

Node *deleteNode(Node *root, int &data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    // balance the tree
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    int balanceFactor = get_balance_factor(root);
    if (balanceFactor > 1)
    {
        if (get_balance_factor(root->left) >= 0)
        {
            return rightRotate(root);
        }
        else
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balanceFactor < -1)
    {
        if (get_balance_factor(root->right) <= 0)
        {
            return leftRotate(root);
        }
        else
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

void postorder_traversal(Node *node)
{
    if (node == NULL)
        return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->data << " ";
    return;
}

int main()
{
    int k;
    cin >> k;
    build_tree(&root);
    root = deleteNode(root, k);
    postorder_traversal(root);
}