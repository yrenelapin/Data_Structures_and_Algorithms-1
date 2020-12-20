#include <stdio.h>
#include <stdlib.h>


void swap(int *ptr_x,int *ptr_y){

    int temp = *ptr_y ;    

    *ptr_y = *ptr_x ;

    *ptr_x = temp; 
}

/*
Worst Case

Time Complexity :- O(n^2).
Space Complexity :- O(1).
*/
void bubbleSort(int *arr, int n ){
    
    // We need n Passes.
    for (int i = 0; i<n ; i++){
        
        bool flag = false;

        // It runs (n-1) + (n-2) +(n-3) +...+1 So O(n^2)
        for (int j = 0 ; j<n-i-1 ; j++){
            if ( arr[j] > arr[j+1] ){
                swap(&arr[j],&arr[j+1]);
                flag = true;
            }
        }

        if (flag == false) break;  // This is helpful in best case. That is Array is sorted in beginning itself. In this case O(n) is Time Complexity
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
    
    bubbleSort(arr,N);
    
    for (int j = 0 ; j< N ; j++ ){
        printf("%d ",arr[j]);
    }        

}