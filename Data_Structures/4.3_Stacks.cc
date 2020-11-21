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
};

Stack::Stack(){}

void Stack::push(int x){
    lst.addFront(x);
}

int Stack::pop(){
    int x  = lst[0];
    lst.removeFront();
    return x ;
}

void Stack::print(){
    printf("\n");
    lst.print();
}

int main(){
    class Stack stk;
    stk.push(10);
    stk.push(20);
    stk.print();

    printf("\n Popped: %d",stk.pop());
    stk.print();

    stk.push(30);
    stk.print();

    printf("\n Popped: %d",stk.pop());
    stk.print();

    printf("\n Popped: %d",stk.pop());
    stk.print();
}