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