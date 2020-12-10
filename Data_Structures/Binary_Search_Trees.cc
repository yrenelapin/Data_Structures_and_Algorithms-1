#include <stdio.h>
#include <stdlib.h>
 
class Binary_Search_Tree  
{ 
    int data; 
    Binary_Search_Tree *left, *right; 
  
public: 
 
    Binary_Search_Tree(); 
  
    Binary_Search_Tree(int x); 
  
    Binary_Search_Tree* Insert(Binary_Search_Tree*, int x); 
  
    void Inorder(Binary_Search_Tree*); 

    bool Search(Binary_Search_Tree* , int x);
}; 
  

Binary_Search_Tree ::Binary_Search_Tree(){ 
    data = 0; 
    left = NULL;  
    right = NULL; 
}

Binary_Search_Tree ::Binary_Search_Tree(int value) 
{ 
        data = value ; 
        left =  NULL;
        right = NULL;
} 
  

Binary_Search_Tree* Binary_Search_Tree ::Insert(Binary_Search_Tree* root, int value) 
{ 
    if (!root)  
    { 
        // Insert the first node, if root is NULL. 
        return new Binary_Search_Tree(value); 
    } 
  
    // Insert data. 
    if (value > root->data)  
    { 
        root->right = Insert(root->right, value); 
    } 
    else 
    { 
        root->left = Insert(root->left, value); 
    } 
  
    // Return 'root' node, after insertion. 
    return root; 
} 
  

void Binary_Search_Tree ::Inorder(Binary_Search_Tree* root) 
{ 
    if (!root) { 
        return; 
    } 
    Inorder(root->left); 
    printf("%d ",root->data); 
    Inorder(root->right); 
} 
  
int main() 
{ 
    Binary_Search_Tree b, *root = NULL; 
    root = b.Insert(root, 50); 
    b.Insert(root, 30); 
    b.Insert(root, 20); 
    b.Insert(root, 40); 
    b.Insert(root, 70); 
    b.Insert(root, 60); 
    b.Insert(root, 80); 
  
    b.Inorder(root); 
    return 0; 
} 
  