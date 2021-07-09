
#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers representing nodes of a Binary Tree along with "null" which represents NULL in Level-Order sequence, 
write a program to construct a Binary Tree using this list and return the nodes from top to bottom that are visible from the 
right side view of the constructed Binary Tree.
*/

// Key Idea: They are the nodes that appear in the level order traversal at each level.

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
    while (cin >> temp)
    {
        if (temp == "null")
            *root = insert_node(*root, INT_MAX, queue);
        else
            *root = insert_node(*root, stoi(temp), queue);
    }
    *root = remove_null_nodes(*root);
    return;
}


// Recursive
void find_levels(struct Node* node, int level, int &max_level){
    
    if (node == NULL){
        return;
    }

    if (max_level < level){
        // This is the last node in the current level.
        cout << node->data << " ";
        max_level = level;
    }
     
    // Note that right subtree should be traversed first inorder for the above 3 lines to print correctly.
    // For more clarity, dry run a test case.
    
    find_levels(node->right, level+1, max_level);

    find_levels(node->left, level+1, max_level);

}

int main(){

    build_tree(&root);
    int max_level = 0;

    // Root node is anyhow visible
    cout << root->data << " ";
    find_levels(root, 0, max_level);
    return 0;
}
