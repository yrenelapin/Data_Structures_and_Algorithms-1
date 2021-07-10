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
The function doesn't do any error checking for cases where inorder and postorder do not form a tree */
struct Node* buildTree(   vector<int> &in , vector<int> &post, int inStrt, int inEnd, unordered_map<int, int>& mp, int &postIndex){

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from postorder traversal using postIndex and decrement postIndex */
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

void printPreorder(struct Node* node){
	if (node != NULL){
	    printf("%d ", node->data);
    	printPreorder(node->left);
    	printPreorder(node->right);
	}
}

int main(){
   vector<int> in, post;
   int temp;
   while(1){
       cin >> temp;
       if (temp == -1){
           break;
       }
       in.push_back(temp);
   }
   
     while(1){
       cin >> temp;
       if (temp == -1){
           break;
       }
       post.push_back(temp);
    }
       
	int len = in.size();

	unordered_map<int, int> mp;
	for (int i = 0; i < len; i++)
		mp[in[i]] = i;
		
    int postIndex = len-1;
	struct Node* root = buildTree(in, post, 0, len - 1, mp, postIndex);

	printPreorder(root);
}

// Ref: https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/