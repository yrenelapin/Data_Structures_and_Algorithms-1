#include <stdio.h>
#include <stdlib.h>
#include "2.1_Linked_List.h"

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

// int main(){
//     LinkedList ll;   // Equivalent to `class LinkedList ll;` 
//     ll.addFront(10);
//     ll.addFront(20);
//     ll.addFront(3);

//     ll.print();

//     if (ll.search(20)){printf("\nYes ! %d  is there in the list",20);}
    
//     // Getting ith Element
//     printf("\n%d \n",ll.element(1));

//     // Better Notation using Operator Overloading
//     printf("%d \n",ll[1]);

//     ll.removeFront();
//     printf("%d",ll.element(1));

// }