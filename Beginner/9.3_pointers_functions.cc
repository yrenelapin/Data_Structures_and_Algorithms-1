#include <stdio.h>

/*Swapping without Pointers using below method is not possible.*/

int* swap(int *ptr_x,int *ptr_y){

    // *ptr_x = 10 and *ptr_y = 20

    int temp = *ptr_y ;    

    *ptr_y = *ptr_x ;

    *ptr_x = temp; 

    // It is just to show how to return pointers from functions.
    return ptr_y ;
    
}


int main(){

    int x = 10;
    int y = 20;
    int* ip;

    printf("\n (x=%d), (y=%d)",x,y);    
    
    ip = swap(&x,&y);
    
    printf("\n (x=%d), (y=%d)",x,y);
    printf("\n Value returned from swap = %d",*ip);

}