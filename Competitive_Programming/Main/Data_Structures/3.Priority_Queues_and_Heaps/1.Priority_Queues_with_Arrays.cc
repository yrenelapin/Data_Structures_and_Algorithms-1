/* This is Incomplete. Will Complete Soon*/

#include <iostream>
#include <algorithm>
using namespace std;

class Node{
public:
    int data;
    int priority;
};

class PriorityQueue{

public:
    class Node* ptr;   // Arrays are similar to Pointers
    int length;

    PriorityQueue(){
        length = 0 ;
        ptr = NULL ;};

    ~PriorityQueue(){ delete ptr;};

    void Insert(int d, int p);
    int ExtractMax();

};

void PriorityQueue::Insert(int d, int p){

    if (length == 0)
        { ptr->data = d;
        ptr->priority = p;  
        ptr++;
        length++;}

    else{

    int maxy = ptr[0] ;
    for (int i = 0 ; i<length; i++ ){
        maxy = max(maxy, ptr[i]);
    }


    }
}

int PriorityQueue::ExtractMax(){
    return ptr[0]->data;
}

int main(){

}