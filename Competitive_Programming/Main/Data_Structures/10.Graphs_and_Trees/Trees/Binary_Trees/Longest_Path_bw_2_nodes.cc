/*
Given a list of numbers representing nodes of a Binary Tree along with "null" which represents NULL in Level-Order sequence, 
write a program to construct a Binary Tree using this list and find the longest path between any two nodes.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} *root = NULL;

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
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

void build_tree(struct Node **root)
{
    string temp;
    queue<Node *> queue;
    while (cin >> temp){
        if (temp == "null")
            *root = insert_node(*root, INT_MAX, queue);
        else
            *root = insert_node(*root, stoi(temp), queue);
    }
    *root = remove_null_nodes(*root);
    return;
}

// We are computing the Longest path from a given node
// to all the nodes in the subtree rooted at that node.
// that is we are finding the depth of the subtree rooted at that node.
int get_longest_path(struct Node *root, int &ans){
    
    if (root == NULL)
        return 0;
        
    int left = get_longest_path(root->left, ans);
    int right = get_longest_path(root->right, ans);
    
    // We are updating the required value for every node in a POSTORDER manner.
    // For a given node, If we know the depths of its two children
    // longest path in the subtree rooted at that node is 
    // `depth[left]+ depth[right]`
    ans = max(ans, left + right);

    // Return the Longest path of the subtree rooted at given node.
    return 1 + max(left, right);
}

signed main(){
    build_tree(&root);
    int ans = 0;
    get_longest_path(root, ans);
    cout << ans;
    return 0;
}
