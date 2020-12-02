#define counter = 0 ;

int Nodes_with_two_Children(Node * node_ptr){

    Node * iter = node_ptr ;

    if (iter->noofChildren == 0) {return 0;}

    if ( (iter->noOfChildren == 2) && (iter == root) ) { counter++; }
    
    class Linkedlist* child = iter->children; 

    Node * ptr = child->head;

    while (ptr != NULL) {

        if ( ptr->noOfChildren == 2 ) { counter++ ; }

        int temp = Nodes_with_two_Children(ptr);

        ptr = ptr ->next;
    }

    return counter;
}

// We should call the Function initially with ROOT node Pointer.
int main(){
    Nodes_with_two_Children (root);
}
