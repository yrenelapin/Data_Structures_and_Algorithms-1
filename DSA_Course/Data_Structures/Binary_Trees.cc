#include <stdio.h>
#include <stdlib.h>

int store_preorder[100];
int c = 0 ;

class Node{

public:

    int elem;
    class Node* left;
    class Node* right;

    Node(int val){
        elem = val ; 
        left =  NULL;
        right = NULL;
    }

friend class BinaryTree;
};



class BinaryTree{
public:
    class Node* Root;

    BinaryTree(int root);
    ~BinaryTree();

    void Pre_Order(Node * ptr);      
    void pre(Node *ptr);

};

BinaryTree::BinaryTree(int root){
    Root = new Node(root);
}
BinaryTree::~BinaryTree(){
    delete Root;
}

void BinaryTree::Pre_Order(Node* ptr){
    if (ptr == NULL) return;
    store_preorder[c] = ptr->elem;
    c++;
    printf("%d ",ptr->elem);
    Pre_Order(ptr->left);
    Pre_Order(ptr->right);
}


void BinaryTree::pre(Node *ptr){

    for (int i = 0; i< c ; i++){
        if ( store_preorder[i] == ptr->elem){
            printf("Rank of the Node %d is %d\n",ptr->elem, i+1);
        }
    }
}


int main(){

    class BinaryTree bt(60);
    bt.Root->left = new Node(10);
    bt.Root->right = new Node(50);
    bt.Root->left->left = new Node(70);
    bt.Root->left->right = new Node(30);

    printf("The Pre Order Traversal is as follows :\n");
    bt.Pre_Order(bt.Root);
    printf("\n");

    bt.pre(bt.Root);
    bt.pre(bt.Root->left);
    bt.pre(bt.Root->right);
    
}