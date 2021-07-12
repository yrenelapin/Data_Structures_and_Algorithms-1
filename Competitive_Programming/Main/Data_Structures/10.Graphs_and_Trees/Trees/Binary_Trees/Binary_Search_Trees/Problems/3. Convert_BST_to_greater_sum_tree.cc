#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
Convert BST to Greater Sum Tree
Greater Sum Tree is a tree in which every node holds the sum of all nodes that are
greater than or equal to the node.

Given a list of numbers representing nodes along with "null" which represents NULL 
in Level-Order sequence, write a program to build a Binary Search Tree using this list and 
convert it to Greater Sum Tree.
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

void build_tree(struct Node* &root)
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

vector<int> traversal;

void in_order_traversal(struct Node *node)
{
    if (node == NULL)
        return;
    
    in_order_traversal(node->left);
    traversal.push_back(node->data);
    in_order_traversal(node->right);
}


void pre_order_traversal(struct Node *node, vector<int>&prefix)
{
    if (node == NULL)
        return;
    
    int n = prefix.size();
    int currans = node->data;
    int pos = lower_bound(traversal.begin(), traversal.end(), node->data) - traversal.begin();
    currans += ( prefix[n-1] - prefix[pos] );
    cout << currans << " ";
    pre_order_traversal(node->left, prefix);
    pre_order_traversal(node->right, prefix);
}


signed main()
{   
    build_tree(root);
    in_order_traversal(root);

    int n = traversal.size();
    vector<int> prefix(n);
    prefix[0] = traversal[0];
    for(int i = 1; i < n ; i++){
        prefix[i] = (traversal[i] + prefix[i-1]); 
    }
    
    pre_order_traversal(root, prefix);

    return 0;
}