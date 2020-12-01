#include <stdio.h>
#include <stdlib.h>
#include "3.1_Doubly_Linked_List.h"


class Node{
private:
    int elem;
    class Node* parent;
    class Node* children; 

public:
    Node(int el, Node* par, Node *child){
        elem = el;
        parent = par;
        printf("Enter the Number of Children for Node %d",el);
        int no;
        scanf("%d",&no);
        children = (Node *)calloc(no,sizeof(Node));
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
    void CreateTree();
    void Relationship(int x, int y);
};

void Tree::CreateTree(){
    printf("Enter the Node")
    
}

int main(){

    Tree t ;
    t.CreateTree();

}
