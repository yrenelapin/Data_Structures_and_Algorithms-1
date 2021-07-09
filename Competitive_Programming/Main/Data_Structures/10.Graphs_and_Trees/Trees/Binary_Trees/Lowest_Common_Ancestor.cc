#include <bits/stdc++.h>
using namespace std;

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

int M, N;

// We are checking for LCA of M,N in the subtree rooted at `node`
struct Node* lowest_common_ancestor(struct Node *node){

   if (node == NULL){
       return NULL;
   }

   // One of the nodes is root of the current subtree itself, which means the node itself is LCA.
   if ( (node->data == M) or (node->data == N) ){
       return node;
   }
   
   // Finding the LCA in the subtree rooted at each child of the current node.
   auto lnode = lowest_common_ancestor(node->left);
   auto rnode = lowest_common_ancestor(node->right);
   
   // There is a LCA for both the given nodes in both the subtrees, 
   // It means that both nodes (M,N) are in different subtrees (1 in left & 1 in right), It inturn means the node itself is the actual LCA 
   if (lnode != NULL and rnode != NULL){
       return node;
   }

   // There is LCA in left subtree but there is no LCA in the right subtree, 
   // It means both the nodes are in the left subtree & so the LCA is also in the left subtree & it is lnode from above computation.
   else if (lnode != NULL){
       return lnode;
   }
   else{
        // Similarly, if both nodes are in right subtree
       return rnode;
   }

}

int main()
{
    cin >> M >> N;
    build_tree();
    cout << lowest_common_ancestor(root)->data;
    return 0;
}
