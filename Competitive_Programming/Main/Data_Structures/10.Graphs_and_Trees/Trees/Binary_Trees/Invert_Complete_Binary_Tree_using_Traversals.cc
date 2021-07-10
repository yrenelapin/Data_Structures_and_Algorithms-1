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
vector<int> post;
void postOrderTrav(struct Node* node) {
    if (node != NULL){
        postOrderTrav(node->left);
        postOrderTrav(node->right);
        post.push_back(node->data);
    }
}
vector<int> in;
void inOrderTrav(struct Node* node) {
    if (node != NULL){
        inOrderTrav(node->left);
        in.push_back(node->data);
        inOrderTrav(node->right);
    }
}
struct Node* buildTree(   vector<int> &in , vector<int> &pre, int inStrt, int inEnd, unordered_map<int, int>& mp, int &preIndex){

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder traversal using preIndex and increment preIndex */
	int curr = pre[preIndex++];
	struct Node* tNode = create_node(curr);

	/* If this node has no children, i.e There are no left & right elements in the current indexed element in Inorder Traversal array*/
	if (inStrt == inEnd)
		return tNode;

	/* Else find the index of this node in Inorder traversal */
	int inIndex = mp[curr];

	/* Using index in Inorder traversal, construct left and right subtress */
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp, preIndex );
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp, preIndex);

	return tNode;
}

void printPostorder(struct Node* node){
	if (node != NULL){
    	printPostorder(node->left);
    	printPostorder(node->right);
        printf("%d ", node->data);
	}
}

int main(){
    build_tree(&root);
    postOrderTrav(root);
    inOrderTrav(root);
    reverse(in.begin(), in.end());
    vector<int> pre = post;
    reverse(pre.begin(), pre.end());
    int len = pre.size();

    // Note that this method currently works only if all the nodes in the tree are distinct due to storing & lookup.
    // we can extend this for repeated node values using different data structure but that wont be efficient.
	unordered_map<int, int> mp;
	for (int i = 0; i < len; i++)
		mp[in[i]] = i;
		
    int preIndex = 0;
	struct Node* root = buildTree(in, pre, 0, len - 1, mp, preIndex);
	printPostorder(root);
    return 0;
}