#include <stdio.h>
#include <stdlib.h>

#define ERROR 0;


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



public:
    int length;
    LinkedList();
    ~LinkedList();

    // Operator Overloading
    int operator [] (int indx);

    void addFront(int x);
    void addBack(int x);
    void removeFront();
    void removeBack();
    void add(int x);
    void remove();
    int len();
    bool search(int x);
    int element(int indx);

    int returnFront();
    int returnBack();
    bool isEmpty();

    void print();

    int Insert(int x ,int indx); // Insert x at Index 'indx'
};



Node::Node(int x, class Node* prv, class Node* nxt){elem = x; prev=prv; next = nxt;}
Node:: Node(int x){elem = x; prev = NULL; next = NULL;}
Node:: Node(){prev= NULL; next = NULL;}


int LinkedList::returnFront(){
    if (head == NULL) return ERROR ; 
    return head->elem;
}

int LinkedList::returnBack(){
    if (tail == NULL) return ERROR ;
    return tail->elem;
}

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

void LinkedList::add(int x){
    addFront(x);
}

void LinkedList::remove(){
    removeFront();
}


int LinkedList::len(){
    return length;
}

bool LinkedList::search (int x){
    class Node* iter = head;
    while (iter != NULL)
        {   if (iter->elem == x) return true;
            iter = iter->next;
        }
        return false ;    
}

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    length = 0;

}

LinkedList::~LinkedList(){
    while (head != NULL) removeFront();
    // { class Node *iter = head; 
    //     head = iter->next;
    //     delete iter;
    // }
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

// Notice that Front & Back functions are symmetrical now !!

void LinkedList::removeBack(){

    if (tail==NULL) return ;

    class Node* temp = tail;
    tail =  tail->prev;
    if (tail == NULL) head = NULL;
    else  tail->next = NULL;    
    delete temp;

    length--;

}

int LinkedList::Insert(int x , int indx){
  
   if (indx > length) return ERROR ;

    class Node* iter = head;
    
    while (iter != NULL){
         if  (indx==0) {
            Node* New_Node = new Node(x,iter->prev,iter);     
            iter->prev->next = New_Node;
            iter->prev = New_Node;
            return 1;
            }


         iter = iter->next;
         indx--;
    }

    return ERROR ;

}