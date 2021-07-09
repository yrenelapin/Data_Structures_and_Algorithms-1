#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* 
Idea:  
If we take each element `a` from Post Order Traversal from the END & find its position in Inorder Traversal, The elements to the left of this element `a`
are in the left sub tree of this node `a` & elements to the right of this element `a` are in the Right Sub Tree of this node `a`. 

NOTE: We should recursively call for right subtree before left subtree as we decrease index of postorder index whenever we create a new node.
Otherwise we get Segmentation Fault. To understand why this happens, just dry run a simple test case.
*/

/* Initial values of inStrt and inEnd should be 0 and len -1. They refer to the indexes of the Inorder Traversal array,
The function doesn't do any error checking for cases where inorder and preorder do not form a tree */
struct Node* buildTree(int in[], int post[], int inStrt, int inEnd, unordered_map<int, int>& mp, int &postIndex){

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder traversal using postIndex and increment postIndex */
	int curr = post[postIndex--];
	struct Node* tNode = newNode(curr);

	/* If this node has no children, i.e There are no left & right elements in the current indexed element in Inorder Traversal array*/
	if (inStrt == inEnd)
		return tNode;

	/* Else find the index of this node in Inorder traversal */
	int inIndex = mp[curr];

	/* Using index in Inorder traversal, construct left and right subtress */
	tNode->right = buildTree(in, post, inIndex + 1, inEnd, mp, postIndex);
	tNode->left = buildTree(in, post, inStrt, inIndex - 1, mp, postIndex );

	return tNode;
}

void printPostorder(struct Node* node){
	if (node == NULL)
		return;
    
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d ", node->data);
}

int main(){

    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int n = sizeof(in) / sizeof(in[0]);

	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[in[i]] = i;

    int postIndex = n-1;
	struct Node* root = buildTree(in, post, 0, n - 1, mp, postIndex);

	/* Let us test the built tree by printing Post Order traversal */
	printf("Post Order traversal of the constructed tree is \n");
	printPostorder(root);
}

// Ref: https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/