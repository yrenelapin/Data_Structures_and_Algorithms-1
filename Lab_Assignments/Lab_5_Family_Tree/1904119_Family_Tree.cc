#include <stdio.h>
#include <stdlib.h>
#include "2.1_Linked_List.h"


class Node{
private:
    int elem;
    class Node* parent;
    class Node* children; 

public:
    Node(int el, Node* par, Node *child){
        elem = el;
        parent = par;
        children = child;
    }
    Node(int el){
        elem = el;
        parent = NULL;
        children = NULL;
    }
    
friend class Tree;
};

class Tree{
public:
    void insertChild(int val, int pos);
    int numberOfChildren(Node* node);
    bool isRoot();
    bool isLeaf();
    void Relationship(int x, int y);
};

void Tree::insertChild(int val, int pos){

    
}



