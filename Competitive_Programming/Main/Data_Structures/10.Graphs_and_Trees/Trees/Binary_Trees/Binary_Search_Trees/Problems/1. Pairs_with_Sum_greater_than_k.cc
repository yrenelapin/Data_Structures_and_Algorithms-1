#include <bits/stdc++.h>
using namespace std;

/*
Pairs with Sum Greater than K
Given an integer K and two lists of numbers representing nodes along with "null" which represents NULL in
Level-Order sequence, write a program to construct two Binary Search Trees from these lists and 
find the number of pairs whose sum is greater than K. A pair should contain one element from each tree.
*/

struct Node
{
    int data;
    struct Node *left, *right;
} * root1, *root2;

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
    while (1)
    {   
        cin >> temp;

        if (temp == "-1"){
            break;
        }

        if (temp == "null")
            root = insert_node(root, INT_MAX, queue);
        else
            root = insert_node(root, stoi(temp), queue);
    }
    root = remove_null_nodes(root);
}

vector<int> traversal1, traversal2;

void in_order_traversal(struct Node *node, int flag)
{
    if (node == NULL)
        return;
    
    in_order_traversal(node->left, flag);

    if (flag == 1)
        traversal1.push_back(node->data);
    else{
        traversal2.push_back(node->data);
    }

    in_order_traversal(node->right, flag);
}

int main()
{   
    int K;
    cin >> K;
    build_tree(root1);
    in_order_traversal(root1, 1);
    build_tree(root2);
    in_order_traversal(root2, 2);
    
    int cnt = 0;
    for(int i = 0; i < traversal1.size(); i++){
        
        int x =  K - traversal1[i];   // x + traversal1[i] > k

        int i = upper_bound(traversal2.begin(), traversal2.end(), x) - traversal2.begin();

        cnt += ( traversal2.size() - i );
    }

    cout << cnt;
    
    return 0;
}