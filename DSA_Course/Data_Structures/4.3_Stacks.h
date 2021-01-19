#include <stdio.h>
#include "2.1_Linked_List.h"

class Stack{
private:
    LinkedList lst;

public:
    Stack();
    void push(int x);
    int pop();
    void print();
    bool isEmpty();
    int top();
};
