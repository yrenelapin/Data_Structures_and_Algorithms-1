/*
Author  : Sanjay Marreddi
Roll No : 1904119
Date    : 22nd November 2020             

This file contains code for Implementation of Circular Linked List ADT.
*/

#include <stdio.h>
#include <stdlib.h>

/*
Defining a class for NODE which stores an Integer & pointer to the next node.
*/
class Node{

private:
    int elem;
    class Node* next;                              

public:
    Node(int x, class Node* nxt){elem = x; next = nxt;}

// It gives access of its Private Members to "Circular_LinkedList" class only.
friend class Circular_LinkedList;
};

/*
Defining a class for Circular LinkedList which Implements add,remove,print & isempty functions
*/
class Circular_LinkedList{

private:
    class Node* start; 
    int length;

public:
    Circular_LinkedList();
    ~Circular_LinkedList();

    void add (int x );
    int remove();
    void isEmpty();

    void print();

};


Circular_LinkedList::Circular_LinkedList(){
    start = NULL;
    length =0; }


/*
Freeing the Allocated Memory using the Destructor
*/
Circular_LinkedList::~Circular_LinkedList(){
    class Node* iter = start;
    do { 
        class Node* temp = iter;
        delete temp;
        iter = iter->next;
        }
        while (iter != start) ;
}


/*
Adding an Integer to the List with Constant Time Complexity i.e. O(1)
*/
void Circular_LinkedList::add(int x){
    
    // Creating the First Node
    if (start== NULL){
    start = new Node (x,start);
    start->next = start;
    length++;}

    else {

        // Creating the Second Node
        if (length ==1)
        {
        Node * New_one = new Node (x,start);
        
        start->next = New_one ;
        
        length++; }


        // Creating the Nodes from 3rd Node by inserting at the Second Node Position     
        else {

            Node * New_one = new Node (x,start->next);
            start->next = New_one;
            length++; 
        }

        
    }

};


/*
Removing an Integer from the List with Constant Time Complexity i.e. O(1)
*/
int Circular_LinkedList::remove(){

    if (length==0) return 0;

    if (length ==1){    
        Node* temp = start;
        delete temp;
        start= NULL;
        length--;
        return 0;

    }

    // if (length>= 2) We Delete the Second Node 
    class Node* temp = start->next;
    start->next = temp->next;
    delete temp;
    length--;
    return 0 ;
};


/*
Checks whether the List is Empty or not.
*/
void Circular_LinkedList::isEmpty(){
    if (start==NULL) printf("\nThe List is Empty now!\n");
    else printf("\nThe List is not Empty now!\n");
}


/*
Prints all the Elements of the Circular Linked List
*/
void Circular_LinkedList::print(){

    class Node* iter = start;
    do { 
        printf("%d ",iter->elem);
        iter = iter->next;
        }
        while (iter != start) ;

};


int main(){

    Circular_LinkedList cll;

    cll.isEmpty();
    
    cll.add(10);
    cll.print();
    printf("\nRemoving the first element\n");
    cll.remove();

    cll.add(90);
    cll.add(20);
    cll.add(80);
    cll.print();
    printf("\n");
    
    printf("Removing the Second element\n");
    cll.remove();
    cll.print();
    printf("\n");
    
    cll.add(30);
    cll.add(40);
    cll.add(50);
    cll.print();
    cll.isEmpty();

    printf("Removing the Second element\n");    
    cll.remove();
    cll.print();
    printf("\n");
}