#include <stdio.h>
#include <stdlib.h>


void swap(int *ptr_x,int *ptr_y){

    int temp = *ptr_y ;    

    *ptr_y = *ptr_x ;

    *ptr_x = temp; 
}

/*
Time Complexity :- O(n^2).
Space Complexity :- O(1)
*/
void insertionSort(int *arr, int n ){
    
    for (int i = 1; i<n ; i++){

        // We assume that array is sorted till i-1
        for (int j = i; j>0 ; j--){
            
            // It executes 1+2+3+4+....n-1 Times in Worst Case.
            // So It is of order O(n^2).

            if ( arr[j-1] > arr[j] ){
                swap(&arr[j-1],&arr[j]);
            }

            else break;

        }
    }
}

int main(){

    int N;
    printf("Number of Integers in your array :- ");
    scanf("%d",&N);

    
    printf("Enter the Integers :-\n");

    int *arr = new int[N];

    for (int j = 0 ; j< N ; j++ ){
        
        int temp;
        scanf("%d",&temp);
        arr[j] = temp;
    }
    
    insertionSort(arr,N);
    
    for (int j = 0 ; j< N ; j++ ){
        printf("%d ",arr[j]);
    }        

}