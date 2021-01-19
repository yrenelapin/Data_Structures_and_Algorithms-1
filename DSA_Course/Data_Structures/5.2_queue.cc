#include <stdio.h>
#include "3.1_Doubly_Linked_List.h"


class Queue{
private:
    LinkedList lst;
public :
    Queue();
    void enqueue(int x);
    int dequeue();
    void print();
};

Queue::Queue(){}

void Queue::enqueue(int x){
    lst.addBack(x);
}

int Queue::dequeue(){
    int x  = lst[0];
    lst.removeFront();
    return x;
}

void Queue::print(){
    printf("\n");
    lst.print();
}

int main(){
    class Queue q ;
    q.enqueue(20);
    q.enqueue(10);
    q.print();

    printf("\nDequeued: %d",q.dequeue());
    q.print();

    q.enqueue(50);
    q.print();

    printf("\nDequeued: %d",q.dequeue());
    q.print();

    printf("\nDequeued: %d",q.dequeue());
    q.print();



}