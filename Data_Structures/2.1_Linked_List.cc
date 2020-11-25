#include <stdio.h>
#include <stdlib.h>

class Node{
private:
    int elem;
    class Node* next;  // Pointer to the Next Node

public:
    // Defining multiple constructors of the same Class.
    Node(int x, class Node* nxt){elem = x; next = nxt;}
    Node(int x){elem = x; next = NULL;}
    Node(){next = NULL;}

// It gives access of its Private Members to "LinkedList" class only.
friend class LinkedList;
};

class LinkedList{
    class Node* head;  // "Node* head;" This is Equivalent  
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

    bool Check_Repetitions();

};


bool LinkedList::Check_Repetitions(){

    class Node* iter = head;
    class Node* iter2 = head; 

    while (iter != NULL){ 
        
        int count = 0;
        
        while (iter2 != NULL){

            if (iter->elem == iter2->elem) count++;

            if (count >=2 ) return true;
            
            iter2 = iter2->next; 
            }
        iter2 = head;

    iter = iter->next;
    }

    return false;

};

// It prints all the elements of the List
void LinkedList::print(){
    class Node* iter = head;
    while (iter != NULL){ 
        printf("%d ",iter->elem);
        iter = iter->next; }

};



/*
The new operator is an operator which denotes a request for memory allocation on the Heap. 
If sufficient memory is available, new operator initializes the memory and returns the address of the newly allocated and
initialized memory to the pointer variable. When you create an object of class using new keyword(normal new).

- The memory for the object is allocated using operator new from heap.
- The constructor of the class is invoked to properly initialize this memory.
*/
void LinkedList::addFront(int x){
    // It creates a node with element as x and pointer as "head" pointer (which has address of initial 1st element)

    // Now "head" is assigned the Address of the New Node using "new"
    head = new Node (x,head);
    length++;
}



void LinkedList::removeFront(){

    if (head==NULL) return ;

    class Node* temp = head;
    head= head->next;
    delete temp;

    length--;

}

LinkedList::LinkedList(){
    head = NULL;
    length = 0;

}

// We basically use Destructors for Freeing the Memory before exiting the Class.
LinkedList::~LinkedList(){
    while (head != NULL) removeFront();
}

int LinkedList::returnFront(){
    if (head == NULL) return 0 ;
    return head->elem;
}

bool LinkedList::isEmpty(){
    return (head == NULL);
}

/*
Returns the element at given Index.
*/
int LinkedList::element(int indx){
    if (indx > length-1) return 0 ;

    class Node* iter = head;
    while (iter != NULL){
         if  (indx==0) return iter->elem;
         iter = iter->next;
         indx--;
    }

    return 0 ;

}


int LinkedList:: operator [] (int indx){
    return element(indx);
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

int main(){
    LinkedList ll;   // Equivalent to `class LinkedList ll;` 
    ll.addFront(10);
    ll.addFront(20);
    ll.addFront(3);
    ll.addFront(20);
    ll.print();

    if (ll.search(20)){printf("\nYes ! %d  is there in the list",20);}
    
    // Getting ith Element
    printf("\n%d \n",ll.element(1));

    // Better Notation using Operator Overloading
    printf("%d \n",ll[1]);

    ll.removeFront();
    printf("%d",ll.element(1));

    LinkedList ll1;   
    ll1.addFront(3);
    ll1.addFront(1);
    ll1.addFront(2);
    ll1.addFront(1);
    ll1.print();

    if (ll.Check_Repetitions()){printf("\nThe Repititions are present in the above Linked List");}
    else printf("\nThere are no Repititions in the above Linked List");

    LinkedList ll2;
    ll2.addFront(3);
    ll2.addFront(2);
    ll2.addFront(1);
    printf("\n");
    ll2.print();

    if (ll2.Check_Repetitions()){printf("\nThe Repititions are present in the above Linked List");}
    else printf("\nThere are no Repititions in the above Linked List");
}