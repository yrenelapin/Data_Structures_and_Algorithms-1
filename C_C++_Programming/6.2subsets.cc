#include <stdio.h>

/*
Draw the box Representation of Recursive Call for Better Understanding of whats going on behind the scene !
*/

void print_subset(int ar[] , int info[], int ar_size){

    printf("\n");

    int i ;
    int bool_not_empty = 0;

    for (i=0;i<ar_size; i++){   
        
        if (info[i]== 1){ 
        printf("%d, ", ar[i]);
        bool_not_empty = 1 ;}
    }

    if (bool_not_empty==0) 
        printf("Empty");
}



void subsets(int ar[], int ar_size , int ar_beg, int info[]){

    printf("\nRecursive call : ar_beg = %d", ar_beg);

    if (ar_beg == ar_size){                 // Base Case
        print_subset(ar,info,ar_size);
        return ;
    }

    info[ar_beg] = 0 ;      
    printf("\n %d not included",ar[ar_beg]);
    subsets(ar, ar_size , ar_beg+1, info);

    info[ar_beg] = 1;
    printf("\n %d  included",ar[ar_beg]);
    subsets(ar, ar_size , ar_beg+1, info);

    return;
}


int main()
{
    const int ar_size = 2;

    int ar[ar_size] = {1,2};
    int info[ar_size];          // The array "info" has Information whether to include it in Subset or not in current Index

    subsets(ar,ar_size,0, info);
}


