#include <stdio.h>
#include <stdlib.h>
#include "3.1_Doubly_Linked_List.h"

#define ERROR 0;


Node::Node(int x, class Node* prv, class Node* nxt){elem = x; prev=prv; next = nxt;}
Node:: Node(int x){elem = x; prev = NULL; next = NULL;}
Node:: Node(){prev= NULL; next = NULL;}


int LinkedList::returnFront(){
    if (head == NULL) return ERROR ; 
    return tail->elem;
}

int LinkedList::returnBack(){
    if (head == NULL) return ERROR ;
    return head->elem;
}

bool LinkedList::isEmpty(){
    return (head == NULL);
}


int LinkedList:: operator [] (int indx){
    return element(indx);
}


int LinkedList::element(int indx){
    if (indx > length) return ERROR ;

    class Node* iter = head;
    while (iter != NULL){
         if  (indx==0) return iter->elem;
         iter = iter->next;
         indx--;
    }

    return ERROR ;

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

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    length = 0;

}

LinkedList::~LinkedList(){
    while (head != NULL) removeFront();
    // { class Node *iter = head; 
    //     head = iter->next;
    //     delete iter;
    // }
}

void LinkedList::print(){
    class Node* iter = head;
    while (iter != NULL){ printf("%d ",iter->elem); iter = iter->next;}

};

void LinkedList::addFront(int x){
    if (head== NULL){ head = new Node(x,NULL,NULL);
                     tail = head;
    }
    else {
        head = new Node (x,NULL,head);
        head->next->prev = head;
    }
    length++;
}

void LinkedList::addBack(int x){
    if (tail== NULL) { 
        tail = new Node(x,NULL,NULL);
        head = tail;
    }
    else {
    tail = new Node (x, tail, NULL);
    tail->prev->next= tail;
    }
    length++;
}


void LinkedList::removeFront(){

    if (head==NULL) return ;

    class Node* temp = head;
    head= head->next;
    if (head == NULL) tail = NULL;
    else  head->prev = NULL;

    delete temp;

    length--;

}

// Notice that Front & Back functions are symmetrical now !!

void LinkedList::removeBack(){

    if (tail==NULL) return ;

    class Node* temp = tail;
    tail =  tail->prev;
    if (tail == NULL) head = NULL;
    else  tail->next = NULL;    
    delete temp;

    length--;

}
