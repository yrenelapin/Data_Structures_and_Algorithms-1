#include <stdio.h>
#include <stdlib.h>

class Node{

public: 
    int elem;   
    class Node* parent;
    class Node** children;        // Pointer to array of pointers of Node.
    int number;
    int temp ;

    Node(){
    elem = 0;
    parent = NULL;
    temp = 0;
    number =0 ;    
    }
};


class FamilyTree{

public:
    class Node Root ;
    FamilyTree(int root);
    FamilyTree(){};
    ~FamilyTree();
    void insertChild(int parent, int child);
    void relationship(int person1, int person2);
    int search_child(int x, class Node* ptr);
    class Node* search(int x);
    class Node* search_final(int x, class Node* ptr) ;

};

FamilyTree::FamilyTree(int root){
  
    Root.elem = root;    
    Root.parent = NULL;

    printf("Enter the Number of Children for this node %d:");

    scanf("%d",&Root.number);

    // Allocating Memory for the Pointer of Array of pointers to Node
    Root.children = new Node *[Root.number];

    // Allocating Memory for the Pointers to Nodes
    for (int i = 0; i<Root.number ; i++){
        Root.children[i] = new Node;
    }

    printf("Assigned number of children to root as %d",Root.number);
}


FamilyTree::~FamilyTree(){
    delete Root.children;
    delete Root.parent;
}




int FamilyTree::search_child(int x, class Node* pointer){

    int help = 0;
    
    int num_of_child =  pointer->number;

    // printf("num_of_child :-  %d\n",num_of_child);

    class Node* store = pointer;
    
    pointer = pointer->children[help];

    while ( pointer != NULL ){

        printf("pointer->elem %d",pointer->elem);

        if ( (pointer->elem) == x){
            printf("\nFound %d so returning from search",x);
            return help+1;
        }
        else {
        
            help++;
            if ( help < num_of_child  ){
                pointer = store->children[help]; }
            else { pointer = NULL; }
        
        }
        // printf("Inside While !\n");
        // printf("%d",pointer);
    }
    printf("Returning 0\n");
    return 0;
}


class Node* FamilyTree::search_final(int x, class Node* ptr){

        class Node* storing = ptr;


        // BASE CASE
        if (ptr->elem == x) return ptr;
        if (ptr == NULL) return NULL;

        printf("\nCalling search_child(%d,ptr)\n",x);
        
        int y  = search_child(x,ptr);
        
        printf("\nReceived %d from search_child\n",y);


        if (y>0){
                return (ptr->children[y-1]);
        }
        else{
            printf("Entered the Recursive part with fixed value as %d", storing->number);
            int fixed = storing->number;

            for (int i = 0 ; i< fixed ; i++ ){
                class Node* res = search_final(x,ptr->children[i]);
                if (res->elem == x){
                    printf("\nFound via Recursion");
                    return res;
                }
                else{ ptr = ptr->children[i++];  return NULL ;}
            }
        }

}


// Return the pointer to the node with element as x. 
class Node* FamilyTree::search(int x){

    printf("Searching for %d\n",x);
    return (search_final(x,&Root));

};



void FamilyTree::insertChild(int parent, int child){


    class Node* ptr = search(parent);

    ptr->children[ptr->temp]->elem = child;
    ptr->children[ptr->temp]->parent = ptr;

    
    printf("\nEnter the Number of Children for %d: ",child);
    scanf("%d",&ptr->children[ptr->temp]->number);

    // printf("Entered the Input");
    // printf("ptr->temp %d",ptr->temp);

    // Allocating Memory for the Pointer of Array of pointers to Node
    ptr->children[ptr->temp]->children = new Node *[ptr->children[ptr->temp]->number];

    // printf("Allocated Memory based on the Input");


    // Allocating Memory for the Pointers to Nodes
    for (int i = 0; i< (ptr->children[ptr->temp]->number) ; i++){
        ptr->children[ptr->temp]->children[i] = new Node;
    }

    ptr->temp++;
    
    
}




int main(){
    
    FamilyTree ft(10) ;

    ft.insertChild(10,20);
    ft.insertChild(10,30);    
    ft.insertChild(10,50);

    ft.insertChild(20,4);
    ft.insertChild(30,6);
    
    ft.insertChild(50,90);
    
    ft.insertChild(4,100);
    ft.insertChild(4,200);

    ft.insertChild(90,900);



}