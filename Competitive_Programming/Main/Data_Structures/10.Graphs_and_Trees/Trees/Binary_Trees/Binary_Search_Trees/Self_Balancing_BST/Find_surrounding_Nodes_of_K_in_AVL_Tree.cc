#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer K and a list of numbers representing nodes, 
write a program to construct an AVL tree by inserting nodes into it from left-side of the list and find K's parent and children.

Print three space separated integers representing Parent, left child, and right child of K. 
If any of the nodes don't exist print -1 in place of it.
*/

struct Node
{
    int data, height;
    Node *left, *right;
} * root;

Node *get_new_node(int &data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int get_height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
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

Node *insert(Node *node, int &data)
{
    if (node == NULL)
        return (get_new_node(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(get_height(node->left), get_height(node->right));
    int balanceFactor = get_balance_factor(node);

    if (balanceFactor > 1)
    {
        if (data < node->left->data)
            return rightRotate(node);

        else if (data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balanceFactor < -1)
    {
        if (data > node->right->data)
            return leftRotate(node);

        else if (data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

void build_tree()
{
    int temp;
    while (cin >> temp)
        root = insert(root, temp);

    return;
}

Node *get_parent_node(Node *root, int &k)
{
    if (root->left != NULL && root->left->data == k)
    {
        return root;
    }
    if (root->right != NULL && root->right->data == k)
    {
        return root;
    }
    if (root->right != NULL && root->data <= k)
        return get_parent_node(root->right, k);
    else
        return get_parent_node(root->left, k);
}

int main()
{
    int k;
    cin >> k;
    build_tree();
    if (root->data == k)
    {
        printf("%d %d %d", -1, root->left ? root->left->data : -1, root->right ? root->right->data : -1);
    }
    else
    {
        Node *parent = get_parent_node(root, k);
        Node *pivot = (parent->left && parent->left->data == k) ? parent->left : parent->right;
        printf("%d %d %d", parent->data, pivot->left ? pivot->left->data : -1, pivot->right ? pivot->right->data : -1);
    }
    return 0;
}
