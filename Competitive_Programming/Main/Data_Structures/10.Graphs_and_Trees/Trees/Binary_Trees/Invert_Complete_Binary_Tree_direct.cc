#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

struct Node* make_bt(vector<int> &v, int index){
    if (index >= v.size()){
        return NULL;
    }
    auto node = create_node(v[index]);
    
    // Inverting the nodes while making the Binary Tree Itself.
    node->right = make_bt(v, 2*index + 1);
    node->left = make_bt(v, 2*index + 2);
    return node;
}

void post_order_traversal(struct Node *node)
{
    if (node != NULL){
        post_order_traversal(node->left);
        post_order_traversal(node->right);
        cout << node->data << " ";
    }
}

int main()
{
    int temp;
    vector<int> v;
    while (cin >> temp){
        v.push_back(temp);
    }
    
    struct Node* root = make_bt(v,0);
    post_order_traversal(root);
    return 0;
}
