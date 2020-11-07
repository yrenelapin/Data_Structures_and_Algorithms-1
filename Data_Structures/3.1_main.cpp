#include <stdio.h>
#include<stdlib.h>
#include "3.1_Doubly_Linked_List.h"


int main(){
    class LinkedList ll;
    ll.addFront(10);
    ll.addFront(20);
    ll.addFront(3);
    ll.removeBack();
    ll.addBack(50);

    ll.print();
    printf("\n");
    ll.removeFront();
    ll.print();

 
}