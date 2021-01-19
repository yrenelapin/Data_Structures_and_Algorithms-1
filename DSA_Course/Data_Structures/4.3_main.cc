#include "4.3_Stacks.h"

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