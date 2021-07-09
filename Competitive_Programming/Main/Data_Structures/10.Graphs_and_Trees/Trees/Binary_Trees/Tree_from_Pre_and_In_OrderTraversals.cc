#include <bits/stdc++.h>
using namespace std;

struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(char data){
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* 
Idea:  
If we take each element `a` from Pre Order Traversal & find its position in Inorder Traversal, The elements to the left of this element `a`
are in the left sub tree of this node `a` & elements to the right of this element `a` are in the Right Sub Tree of this node `a`. 
*/

/* Initial values of inStrt and inEnd should be 0 and len -1. They refer to the indexes of the Inorder Traversal array,
The function doesn't do any error checking for cases where inorder and preorder do not form a tree */
struct Node* buildTree(char in[], char pre[], int inStrt, int inEnd, unordered_map<char, int>& mp, int &preIndex){

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder traversal using preIndex and increment preIndex */
	char curr = pre[preIndex++];
	struct Node* tNode = newNode(curr);

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

void printInorder(struct Node* node){
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%c ", node->data);
	printInorder(node->right);
}

int main(){

	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
	int len = sizeof(in) / sizeof(in[0]);

	unordered_map<char, int> mp;
	for (int i = 0; i < len; i++)
		mp[in[i]] = i;
    int preIndex = 0;
	struct Node* root = buildTree(in, pre, 0, len - 1, mp, preIndex);

	/* Let us test the built tree by printing Inorder traversal */
	printf("Inorder traversal of the constructed tree is \n");
	printInorder(root);
}

// Ref: https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/