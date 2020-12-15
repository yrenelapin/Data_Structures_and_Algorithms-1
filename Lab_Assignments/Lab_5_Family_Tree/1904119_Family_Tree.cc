/*
Author  : Sanjay Marreddi
Roll No : 1904119
Date    : 7th December 2020             

This file contains code for Implementation of Family Tree ADT and a function to find Relationship between two humans in the Tree.
*/

#include <stdio.h>
#include <cstring>
#include <stdlib.h>


// First, Let us Implement a Doubly LinkedList for using in our FamilyTree Class.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Node{
private:
    class Node* prev;
    int elem;
    class Node* next;
    
public :
    Node(int x, class Node* prv, class Node* nxt);
    Node(int x);
    Node();

// It gives access to only LinkedList
friend class LinkedList;
};


class LinkedList{
    class Node* head;
    class Node* tail;
    int length;


public:
    LinkedList();
    ~LinkedList();

    int operator [] (int indx);
    void addFront(int x);
    void addBack(int x);
    void removeFront();
    int len();
    int element(int indx);
    bool isEmpty();
    void print();

 
};


#define ERROR 0;


Node::Node(int x, class Node* prv, class Node* nxt){elem = x; prev=prv; next = nxt;}
Node:: Node(int x){elem = x; prev = NULL; next = NULL;}
Node:: Node(){prev= NULL; next = NULL;}

bool LinkedList::isEmpty(){
    return (head == NULL);
}


int LinkedList:: operator [] (int indx){
    return element(indx);
}


int LinkedList::element(int indx){
    if (indx > length-1) return ERROR ;

    class Node* iter = head;
    while (iter != NULL){
         if  (indx==0) return iter->elem;
         iter = iter->next;
         indx--;
    }

    return ERROR ;

}

int LinkedList::len(){
    return length;
}

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    length = 0;

}

LinkedList::~LinkedList(){
    while (head != NULL) removeFront();
}

void LinkedList::print(){
    class Node* iter = head;
    while (iter != NULL){ printf("%d ",iter->elem); iter = iter->next;}

};

void LinkedList::addFront(int x){
    if (head== NULL){ head = new Node(x,NULL,NULL);
                     tail = head; // Since only one element exists, Head & Tail points to same Node
    }
    else {
        head = new Node (x,NULL,head);
        head->next->prev = head;
    }
    length++;
}

// In a Doubly Linked List, We can do in a Symmetric Manner.
void LinkedList::addBack(int x){
    if (tail== NULL) { 
        tail = new Node(x,NULL,NULL);
        head = tail;
    }
    else {
    tail = new Node (x, tail, NULL);
    tail->prev->next= tail;
    }
    length++;
}


void LinkedList::removeFront(){

    if (head==NULL) return ;

    class Node* temp = head;
    head= head->next;
    if (head == NULL) tail = NULL;
    else  head->prev = NULL;

    delete temp;

    length--;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Now, We will Implement a Node Class for our Family Tree Class.

class Node_for_Tree{

public :

    // Name of the human which is represented as Integer.
    int name;

    // Pointer to children of the current Node_for_Tree.
    class Node_for_Tree* children;

    // Pointer to siblings of the current Node_for_Tree.
    class Node_for_Tree* siblings;

    // Keeps track of number of children for the current Node_for_Tree.
    int number_of_children;

    // Lineked List of Ancestors of the current Node_for_Tree.
    class LinkedList ancestors;

    // Constructor for Initializing the Node_for_Tree.
    Node_for_Tree();
};


Node_for_Tree::Node_for_Tree(){
    name = 0;
    number_of_children = 0;
    children = NULL;
    siblings = NULL;
}


// Implementation of FamilyTree using our above Node_for_Tree Class.
class FamilyTree{
    
    // Pointer to the ROOT Node_for_Tree.
    class Node_for_Tree* Root;

    // depth of the Node_for_Tree
    int depth = 0;

public:

    // Constructor for Initializing the FamilyTree.
    FamilyTree(int root);

    // Destructor for clearing the allocated Memory.
    ~FamilyTree();

    void insertChild(int parent, int child);
    void relationship(int human1, int human2);
    class Node_for_Tree* search(int x);

    class Node_for_Tree* Recursive_Search(int x, Node_for_Tree* ptr);
};


FamilyTree::FamilyTree(int root){

    // Dynamic Memory Allocation for one Node_for_Tree and assigning it to Root Node_for_Tree
    Root = new Node_for_Tree;

    Root->name = root;

}

FamilyTree::~FamilyTree(){

    // Freeing the Dynamic Memory allocated.
    delete Root;
}


/*
Recursive_Search : It searches for the given Integer in the Tree using the Pointer Provided in a recursive Manner.
Input : Int, Node_for_Tree*
Output : Node_for_Tree*
*/
class Node_for_Tree* FamilyTree::Recursive_Search(int x, Node_for_Tree*ptr){

    Node_for_Tree* temp = ptr;

    // Base Case of Recursion.
    if (temp==NULL) return NULL;
    if (temp->name == x) return temp;
    
    // Recursive Step.
    else{
        // Searching for x in the siblings of the `temp` pointer.
        Node_for_Tree *temp_sib = Recursive_Search(x,temp->siblings);
     

        // If x is not present in the siblings, We check in its child.  
        if (temp_sib == NULL){
            temp_sib = Recursive_Search(x, temp->children);
            depth++;
            
            if (temp_sib == 0 ){depth = 0 ;} 
        } 
        return temp_sib;
    }
}

Node_for_Tree* FamilyTree::search(int x){

    // Searching always starts from Root Node_for_Tree.
    return (Recursive_Search(x,Root)); 
}



/*
insertChild : It takes two integers which represents two Individuals & Inserts 2nd Integer as a Child under the 1st Integer.
Input : 2 Integers
*/ 
void FamilyTree::insertChild(int parent, int child){

    // Searching for the parent Node using our `search` function
    Node_for_Tree* iter = search(parent);

    if (iter==NULL) printf("Cannot Insert %d, since no Parent is Found with %d.\n",child,parent);

    else{

        // If the Parent Node_for_Tree has No children initially :  
        if ( iter->number_of_children == 0){

            // Create a New Node_for_Tree for the child
            Node_for_Tree* child_temp = new Node_for_Tree;
            child_temp->name = child;

            if (iter != Root){

                // We are Inserting Ancestors of parent into ancestors of child 
                for (int i = 0 ; i< iter->ancestors.len(); i++ ){
                child_temp->ancestors.addBack(iter->ancestors[i]) ;
            }
            }

            // Keeping track of ancestors for each child.
            child_temp->ancestors.addFront(iter->name);

            // Pointing the parent node_for_Tree to the created child node_for_Tree
            iter->children = child_temp;

            // Since a Child Node_for_Tree is added, Increment the count of Number of Children
            (iter->number_of_children)++;
        }

        // If the Parent Node_for_Tree has Children Initially :
        else{

            // Create a New Node_for_Tree for the current child    
            Node_for_Tree* child_temp = new Node_for_Tree;
            child_temp->name = child;
            
            // Pointing this new child to the previous child of the same parent
            child_temp->siblings = iter->children;

            if (iter != Root){

            // We are Inserting Ancestors of parent into ancestors of child 
            for (int i = 0 ; i< iter->ancestors.len(); i++ ){
            child_temp->ancestors.addBack(iter->ancestors[i]) ;
            }
            }

            // Keeping track of ancestors for each child.
            child_temp->ancestors.addFront(iter->name);

            // Pointing the parent node_for_Tree to the currently created child node_for_Tree
            iter->children = child_temp;

             // Since a Child Node_for_Tree is added, Increment the count of Number of Children
            (iter->number_of_children)++;
        }


    }

}


// Returns minimum Integer among provided Integers.
int min(int a, int b) { return (a < b) ? a : b ;  } 

/*
relationship : It takes two Integers which are representing two Individuals and prints out their Relationship in the Family Tree.
Input        : 2 Integers
*/
void FamilyTree::relationship(int human1, int human2){

    //printf("relationship(%d,%d)\n",human1,human2);
    // Finding the Depth of the `human1` in the Tree
    depth = 0;
    Node_for_Tree* iter1 = search(human1);
    int depth1 = depth;

    // Finding the Depth of the `human2` in the Tree
    depth = 0;
    Node_for_Tree* iter2 = search(human2);
    int depth2 = depth;


    if ( (iter1  == NULL) || (iter2 == NULL) ){
        printf("(%d,%d) are not having any Relationship !",human1,human2);
        return;
    }


    // Checking for Parent- Child & Grand Parent type Relationships using their Ancestor Lists & Depths.

    int len1 = iter1->ancestors.len();
    int len2 = iter2->ancestors.len();

    if (len1 >= len2){
        for (int i = 0 ; i <len1 ; i++){
            if ( iter1->ancestors[i] == iter2->name) { 
                if ( depth1 - depth2 == 1) {printf("(%d, %d) are having `Parent-Child` Relationship\n",human1,human2); return;}
                if ( depth1 - depth2 == 2) { printf("(%d, %d) are having `Grand Parent` Relationship\n",human1,human2); return;}
                if ( depth1 - depth2 >= 3) { printf("(%d, %d) are having `%dth Great Grand Parent` Relationship\n",human1,human2,(depth1-depth2-2)); return;}   
            }
        }
    }

    if (len2 > len1){    
        for (int i = 0 ; i <len2 ; i++){
            if ( iter2->ancestors[i] == iter1->name){  
                if ( depth2 - depth1 == 1) {printf("(%d, %d) are having `Parent-Child` Relationship\n",human1,human2); return;}
                if ( depth2 - depth1 == 2) { printf("(%d, %d) are having `Grand Parent` Relationship\n",human1,human2); return;}
                if ( depth2 - depth1 >= 3) { printf("(%d, %d) are having `%d-th Great Grand Parent` Relationship\n",human1,human2,(depth2-depth1-2)); return;}
            }
        }
    }

    int latest_common_ancestor = 0;
    int helper = 0;

    // Finding the common Ancestor which is closest.
    for (int i =0; i<len1; i++){    
        if (helper>0) break;
        for (int j= 0; j<len2; j++){
            if (iter1->ancestors[i] == iter2->ancestors[j]) {latest_common_ancestor = iter1->ancestors[i]; helper ++ ; break;}
        }
    }

    if (latest_common_ancestor > 0){

        // Modifying the depths based on the Latest Common Ancestor so that we can use Reference Matrix.
        depth = 0;
        Node_for_Tree* iter1 = search(latest_common_ancestor);
        int depth_CA = depth;
        depth1 = depth1 - depth_CA;
        depth2 = depth2 - depth_CA;
            
    }

    // Using the Given Matrix for Reference of Relationships and printing the Relationships based on the depths.

    if (depth1 == 1 && depth2 ==1 ){printf("(%d, %d) are having `Sister or Brother` Relationship\n",human1,human2);}

    if (  (depth1 == 1  && depth2 >= 2 ) || ( depth2 == 1 && depth1 >=2 )  ) {

            int temp  = abs(depth2- depth1);

            if (temp == 1) {printf("(%d, %d) are having `Nephew or Niece` Relationship\n",human1,human2);}
            if (temp == 2) {printf("(%d, %d) are having `Grand-Nephew or Niece` Relationship\n",human1,human2);}
            if (temp >= 3) {printf("(%d, %d) are having `%d-th Great Grand-Nephew or Niece` Relationship\n",human1,human2,temp-2);}

    }
  
    if ( (depth1 == depth2) && (depth1 >=2) ){printf("(%d, %d) are having `%d-th Cousin` Relationship\n",human1,human2,depth1-1);}
  
    if ( depth1 > 1 && depth2 >1 && (depth1 != depth2) ){
        int m = min(depth1,depth2);
        m--;
        int diff =  abs(depth2 - depth1);
        printf("(%d, %d) are having `%d-th Cousin,%d-Removed` Relationship\n",human1,human2,m,diff);

    }
   
}

int main(){
    class FamilyTree ft(10);
  
    ft.insertChild(10,20);
    ft.insertChild(10,30);    
    ft.insertChild(10,50);

    ft.insertChild(20,4);
    ft.insertChild(30,6);
    ft.insertChild(50,90);
    
    ft.insertChild(4,100);
    ft.insertChild(4,200);
    
    ft.insertChild(6,600);
    ft.insertChild(6,120);
    ft.insertChild(6,240);

    ft.insertChild(120,2);
    ft.insertChild(2,3);
    ft.insertChild(3,1);
    ft.insertChild(3,9);
    ft.insertChild(1,0);

    ft.insertChild(90,900);
    ft.insertChild(900,12);

    ft.insertChild(1000,111);

    ft.relationship(10,20);
    ft.relationship(4,200);
    ft.relationship(6,240);
    ft.relationship(1,0);
    ft.relationship(12,900);


    ft.relationship(20,50);
    ft.relationship(120,240);
    ft.relationship(9,1);


    ft.relationship(10, 4);
    ft.relationship(90,12);
    ft.relationship(2,1);


    ft.relationship(10,200);
    ft.relationship(10,600);
    ft.relationship(10,2);
    ft.relationship(10,3);
    ft.relationship(10,1);
    ft.relationship(10,0);
   
    
    ft.relationship(4,6);
    ft.relationship(100,600);
    ft.relationship(2,12);

    ft.relationship(4,30);
    ft.relationship(20,6);
    ft.relationship(30,100);
    ft.relationship(30,12);
    
    ft.relationship(100,6);
    ft.relationship(200,3);
    ft.relationship(200,1);
    ft.relationship(12,1);
    ft.relationship(12,0);

    ft.relationship(1000,111);
}