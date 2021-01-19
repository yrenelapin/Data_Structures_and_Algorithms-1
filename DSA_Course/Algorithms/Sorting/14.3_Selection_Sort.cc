#include <stdio.h>
#include <stdlib.h>


void swap(int *ptr_x,int *ptr_y){

    int temp = *ptr_y ;    

    *ptr_y = *ptr_x ;

    *ptr_x = temp; 
}

/*
Time Complexity :- O(n^2).
Space Complexity :- O(1).
*/
void selectionSort(int *arr, int n ){
    
    for (int i = 0; i<n ; i++){

        int min_index = i;

        // Runs (n-2) + (n-3) +....+1 so O(n^2)
        for (int j = i+1; j<n ; j++){
            if ( arr[j] < arr[min_index] ){
                min_index = j;
            }
        }
        swap(&arr[i],&arr[min_index]);

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
    
    selectionSort(arr,N);
    
    for (int j = 0 ; j< N ; j++ ){
        printf("%d ",arr[j]);
    }        

}