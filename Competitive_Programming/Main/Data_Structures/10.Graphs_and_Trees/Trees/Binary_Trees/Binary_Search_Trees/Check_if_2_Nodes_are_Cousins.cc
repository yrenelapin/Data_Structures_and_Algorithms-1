/*
Two nodes are said to be cousins if they are on the same level (distance from root) but with different parent nodes.

Given two integers M, N and a list of numbers representing nodes of a tree expect "null" which represents NULL in Level-Order sequence,
write a program to construct the Binary Search Tree from the list and check if M and N are cousins.
*/

// Level order traversal ignoring the nulls can be used as the order in which the nodes are inserted into the BST & 
// one can build BST using `insert`, if we know that the given Level Order traversal corresponds to a BST already and
// all the elements in the BST are UNIQUE.
// If the Level Order of a BST is given where the nodes can have same elements (i.e, Non unique values), 
// we cant construct the BST using `insert`. We need to use the general way of constructing a BINARY TREE from given LEVEL order Traversal.


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node *create_node(int data){
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = node->parent = NULL;
    return node;
}


// Recursive with Parent Pointer
struct Node* BST_insert_p(struct Node* node, int value){

    // If the tree is empty, return a new Node.
    if (node == NULL) 
        return create_node(value);
 
    if (value < node->data){

        auto lchild = BST_insert_p(node->left, value);
        node->left  = lchild;
 
        // Set parent of root of left subtree
        lchild->parent = node;
    }

    else if (value > node->data){

        auto rchild = BST_insert_p(node->right, value);
        node->right  = rchild;
 
        // Set parent of root of right subtree
        rchild->parent = node;
    }
 
    /* return the (unchanged) Node pointer */
    return node;
}
 

map<int, int> levels;

void eval_levels(Node *root, int level) {
    if ( root != NULL){
        
        levels[root->data] =  level;
        eval_levels(root->left, level+1);
        eval_levels(root->right, level+1);

    }
}

struct Node* BST_search_Iter(struct Node* node, int value){

    if (node == NULL){
        return NULL;
    }
    while(node != NULL){

        if (node->data == value){
            return node;
        }
        else if (node->data < value){
            node = node->right;
        }
        else{
            node = node->left;
        }

    }
    return NULL; 
}


int main(){
    int t; cin >> t;
    int m, n;
    while(t--){
        cin >>  m >> n ;
        string temp;
        vector<int> v;
        while (1){
            cin >> temp;
            if (temp == "-1"){
                break;
            }
            if (temp != "null")
                v.push_back(stoi(temp));
         }

        struct Node* root = NULL;
        
        // Creating Nodes & Inserting in a BST accordingly.
        for (int i = 0; i< v.size(); i++){
            root = BST_insert_p(root, v[i] );
        }

        eval_levels(root, 0);
         
        auto parm = BST_search_Iter(root, m);
        auto parn = BST_search_Iter(root, n);
       
        int pm;
        if (parm->parent != NULL){
            pm = parm->parent->data;
        }
        else{
            pm = -1;
        }
        
        int pn;
        if (parn->parent != NULL){
            pn = parn->parent->data;
        }
        else{
            pn = -1;
        }

        if ( levels[m] == levels[n]  and pm != pn ){
            cout << 1 << endl;
        } 
        else{
            cout << 0 << endl;
        }

        levels.clear();
    }
 
    return 0;
}