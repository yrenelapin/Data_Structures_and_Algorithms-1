/*
Given a list of numbers representing nodes of a Binary Tree along with "null" which represents NULL in Level-Order sequence, write a program to construct a Binary Tree using this list and find the maximum sum path.

The path should be unidirectional. That means once a path goes through a node, it cannot come back to the same node again.

Note: The path can start from any node, and it need not pass through root.
*/

// Note: When all Nodes are Negative, We directly print the maximum Node value.


// Idea: Traverse the Tree from Bottom to top & keep modifying the values of nodes such a way that we store the maximum node path from that
// particular node in the subtree rooted at that particular node.

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
bool solved = 0;
void build_tree(struct Node **root)
{   bool neg = 1;
    vector<int> input;
    string temp;
    queue<Node *> queue;
    while (cin >> temp){
        if (temp == "null")
            *root = insert_node(*root, INT_MAX, queue);
        else
            { *root = insert_node(*root, stoi(temp), queue);
              int curr =  stoi(temp);
                input.push_back(curr);
                if (curr >= 0){
                    neg = 0;
                }
            }
    }
    
    if (neg == 1){
        solved = 1;
        sort(input.rbegin(), input.rend());
        std::cout << input[0] << std::endl;
        return;
    }
    
    *root = remove_null_nodes(*root);
    return;
}

vector<int> store;
void postOrderTrav(struct Node* node) {
    
    if (node != NULL){
        
        // Just storing the initial node values. It can be done even while reading input.
        store.push_back(node->data);
        
        postOrderTrav(node->left);
        postOrderTrav(node->right);
        
        // Processsing the Node.

        if (node->left != NULL and node->right != NULL){
            store.push_back(node->data + node->left->data + node->right->data);
            node->data += max({0LL, node->left->data, node->right->data}) ;
        }
        else if (node->left != NULL){
            node->data += max(0LL, node->left->data);
        }
        else if (node->right != NULL){
             node->data += max(0LL,node->right->data);
        }
        else{
            node->data = max(0LL, node->data);
        }
        
        store.push_back(node->data);
        
    }
 
}

signed main(){
    build_tree(&root);
    if (solved) return 0;
    postOrderTrav(root);
    sort(store.rbegin(), store.rend());
    std::cout << store[0] << std::endl;
    return 0;
}