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
If we take each element `a` from Pre Order Traversal & find its position in Inorder Traversal, The elements to the left of this element `a`
are in the left sub tree of this node `a` & elements to the right of this element `a` are in the Right Sub Tree of this node `a`. 
*/

/* Initial values of inStrt and inEnd should be 0 and len -1. They refer to the indexes of the Inorder Traversal array,
The function doesn't do any error checking for cases where inorder and preorder do not form a tree */
struct Node* buildTree(   vector<int> &in , vector<int> &pre, int inStrt, int inEnd, unordered_map<int, int>& mp, int &preIndex){

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder traversal using preIndex and increment preIndex */
	int curr = pre[preIndex++];
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

void printPostorder(struct Node* node){
	if (node != NULL){
    	printPostorder(node->left);
    	printPostorder(node->right);
        printf("%d ", node->data);
	}
}

int main(){
   vector<int> in, pre;
   int temp;
   while(1){
       cin >> temp;
       if (temp == -1){
           break;
       }
       pre.push_back(temp);
   }
   
     while(1){
       cin >> temp;
       if (temp == -1){
           break;
       }
       in.push_back(temp);
    }
       
	int len = in.size();

	unordered_map<int, int> mp;
	for (int i = 0; i < len; i++)
		mp[in[i]] = i;
		
    int preIndex = 0;
	struct Node* root = buildTree(in, pre, 0, len - 1, mp, preIndex);

	printPostorder(root);
}

// Ref: https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/