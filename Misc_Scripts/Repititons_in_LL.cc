#include <stdio.h>
#include <stdlib.h>

class Node{
private:
    int elem;
    class Node* next; 

public:
    
    Node(int x, class Node* nxt){elem = x; next = nxt;}
    Node(int x){elem = x; next = NULL;}
    Node(){next = NULL;}

friend class LinkedList;
};

class LinkedList{
    class Node* head; 
    int length;


public:
    LinkedList();
    ~LinkedList();

    void addFront(int x);
    void removeFront();

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


void LinkedList::print(){
    class Node* iter = head;
    while (iter != NULL){ 
        printf("%d ",iter->elem);
        iter = iter->next; }

};



void LinkedList::addFront(int x){
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

LinkedList::~LinkedList(){
    while (head != NULL) removeFront();
}


int main(){
    LinkedList ll;   
    ll.addFront(3);
    ll.addFront(4);
    ll.addFront(2);
    ll.addFront(1);
    ll.print();

    if (ll.Check_Repetitions()){printf("\nThe Repititions are present in the above Linked List");}
    else printf("\nThere are no Repititions in the above Linked List");

    LinkedList ll2;
    ll2.addFront(1);
    ll2.addFront(2);
    ll2.addFront(1);
    printf("\n");
    ll2.print();

    if (ll2.Check_Repetitions()){printf("\nThe Repititions are present in the above Linked List");}
    else printf("\nThere are no Repititions in the above Linked List");


}