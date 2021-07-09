#include <bits/stdc++.h>
using namespace std;

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

vector<int> levelorder;

void build_tree(struct Node **root)
{
    string temp;
    queue<Node *> queue;
    while (cin >> temp)
    {
        if (temp == "null")
            *root = insert_node(*root, INT_MAX, queue);
        else{
                levelorder.push_back(stoi(temp)); 
                *root = insert_node(*root, stoi(temp), queue);
            }       
    }
    *root = remove_null_nodes(*root);
    return;
}


map<int,int> level_store; 
int last_level = 0;
void find_levels(struct Node* node, int level){
    if (node == NULL){
        // `level-1` is stored because, for the Leaf Nodes, this call comes with `level+1`. To get actual level, we need to do -1.
        last_level = max(last_level, level-1);
        return;
    }
    else{
        level_store[node->data] = level;
        find_levels(node->left, level+1);
        find_levels(node->right, level+1);
        return ;
    }
}


int main(){

    build_tree(&root);
    find_levels(root, 0);

    for (int i : levelorder){
        if (level_store[i] == last_level){
            cout << i ;
            return 0;
        }
    }

    return 0;
}
