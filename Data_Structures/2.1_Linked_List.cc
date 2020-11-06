#include <stdio.h>
#include<stdlib.h>

class Node{
private:
    int elem;
    class Node* next;

public :
    Node(int x, class Node* nxt){elem = x; next = nxt;}
    Node(int x){elem = x; next = NULL;}
    Node(){next = NULL;}

// It gives access to only LinkedList
friend class LinkedList;
};

class LinkedList{
    class Node* head;
    int length;


public:
    LinkedList();
    ~LinkedList();

    // Operator Overloading
    int operator [] (int indx);

    void addFront(int x);
    void removeFront();
    void add(int x);
    void remove();

    int len();
    bool search(int x);
    int element(int indx);

    int returnFront();
    bool isEmpty();

    void print();

};

int LinkedList::returnFront(){
    if (head == NULL) return 0 ;
    return head->elem;
}

bool LinkedList::isEmpty(){
    return (head == NULL);
}


int LinkedList:: operator [] (int indx){
    return element(indx);
}


int LinkedList::element(int indx){
    if (indx > length) return 0 ;

    class Node* iter = head;
    while (iter != NULL){
         if  (indx==0) return iter->elem;
         iter = iter->next;
         indx--;
    }

    return 0 ;

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
    head = new Node (x,head);
    length++;

    // class Node* temp = head;
    // head = new Node;
    // head->elem = x ;
    // head->next = temp;

}



void LinkedList::removeFront(){

    if (head==NULL) return ;

    class Node* temp = head;
    head= head->next;
    delete temp;

    length--;

}


int main(){
    class LinkedList ll;
    ll.addFront(10);
    ll.addFront(20);
    ll.addFront(3);

    ll.print();

    if (ll.search(20)){printf("\nYes ! it is there in the list \n");}
    if (!ll.search(30)){printf("\nNo ! it is not there in the list \n");}

    // Getting ith Element
    printf("%d \n",ll.element(1));

    // Better Notation using Operator Overloading
    printf("%d \n",ll[1]);

    ll.removeFront();
    printf("%d",ll.element(1));

}