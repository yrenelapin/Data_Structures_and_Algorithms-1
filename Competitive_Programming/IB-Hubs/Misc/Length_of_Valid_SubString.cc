#include <iostream> 
using namespace std; 
#include <string.h>


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

// It prints all the elements of the List
void LinkedList::print(){
    class Node* iter = head;
    while (iter != NULL){ 
        printf("%d ",iter->elem);
        iter = iter->next; }

};



/*
The new operator is an operator which denotes a request for memory allocation on the Heap. 
If sufficient memory is available, new operator initializes the memory and returns the address of the newly allocated and
initialized memory to the pointer variable. When you create an object of class using new keyword(normal new).

- The memory for the object is allocated using operator new from heap.
- The constructor of the class is invoked to properly initialize this memory.
*/
void LinkedList::addFront(int x){
    // It creates a node with element as x and pointer as "head" pointer (which has address of initial 1st element)

    // Now "head" is assigned the Address of the New Node using "new"
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

// We basically use Destructors for Freeing the Memory before exiting the Class.
LinkedList::~LinkedList(){
    while (head != NULL) removeFront();
}

int LinkedList::returnFront(){
    if (head == NULL) return 0 ;
    return head->elem;
}

bool LinkedList::isEmpty(){
    return (head == NULL);
}

/*
Returns the element at given Index.
*/
int LinkedList::element(int indx){
    if (indx > length-1) return 0 ;

    class Node* iter = head;
    while (iter != NULL){
         if  (indx==0) return iter->elem;
         iter = iter->next;
         indx--;
    }

    return 0 ;

}


int LinkedList:: operator [] (int indx){
    return element(indx);
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




int numberofsymb = 1;
char opensymb[] = "("  ;
char closesymb[] = ")" ;

bool isOpenBracket(char ch){
    for (int i =0; i<numberofsymb; i++){
        if (opensymb[i] == ch) return true ;
    }
    return false;
}

int isCloseBracket(char ch){
    for (int i =0; i<numberofsymb; i++){
        if (closesymb[i] == ch) return i+1 ;
    }
    return 0;
}

int counter = 0;

bool ParenthesesMatch(char ar[], int len)
{

    class Stack stk;
    for(int i=0; i<len; i++){

        if (isOpenBracket(ar[i])) stk.push(ar[i]);

        int y = isCloseBracket(ar[i]);

        if (y>0){

            if (stk.isEmpty()) return false ;
            if ( stk.top() == opensymb[y-1]) { stk.pop(); counter++; }
                else return false; 
        }

    }
    if (stk.isEmpty()) return true;
    else counter--;
    return false;

}

int max(int a, int b) { return (a > b) ? a : b ;  } 

int main(){

    string ar;
    cin >> ar;
 
    int result  = 0;
    for (int i = 0; i<ar.size() ; i++){
        for (int l = 1 ; l<= ar.size()-i; l++){

            string s = ar.substr(i,l);

            char* char_arr;
            string str_obj(s);
            char_arr = &str_obj[0];
            cout << s << " ";
        
            if (ParenthesesMatch(char_arr,s.size())){}
           
            int doub = 2*counter;

            cout << doub << "\n";

            result = max(result,doub);
            counter = 0 ;

        }
    }
    printf("%d",result);
}