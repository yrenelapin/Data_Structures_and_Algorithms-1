#include <stdio.h>
#include "4.3_Stacks.h"

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

bool Stack::isEmpty(){
    return lst.isEmpty() ;
}

int Stack::top(){
    return lst[0];
}