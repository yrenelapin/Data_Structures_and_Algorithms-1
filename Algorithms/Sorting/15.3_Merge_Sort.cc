#include <stdio.h>
#include <stdlib.h>

void merge(int * ar1, int * ar2, int n, int *ar_final){

        int i = 0, j= 0, k = 0 ;

        while ( i<n && j<n){
             if ( ar1[i] <= ar2[j] ) { ar_final[k] = ar1[i]; i++; }
             else 
                 { ar_final[k] = ar2[j]; j++; }
            k++;
        }

        // Copy the remaining elements 
        for ( ; i<n; i++){
            ar_final[k] = ar1[i];
            k++;
        }

        // Copy the remaining elements 
        for ( ; j<n; j++){
            ar_final[k] = ar2[j];
            k++;
        }


}


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
void mergeSort(int *arr, int n, int *b ){
    

    // By Passing Start and End Positions as Input to the Merge Sort Function,
    // We can avoid creating arrays ar1, ar2.

    // Assuming n is EVEN

    if (n==1){
        b[0]= arr[0];
    }

    if (n==2){
        if (arr[0] > arr[1]){
            b[0] = arr[1];
            b[1] = arr[0];
        }

        if (arr[0] < arr[1]){
            b[0] = arr[0];
            b[1] = arr[1];
        }

    }

    int * ar1 = new int[n/2];
    for (int i = 0 ; i<n/2 ; i++){
        ar1[i] = arr[i];
    }

    int * ar2 = new int[n/2];
    for (int i = n/2 ; i<n ; i++){
        ar2[i] = arr[i];
    }

    // Two Output arrays
    int * br1 = new int[n/2];
    int * br2 = new int[n/2];

    mergeSort(ar1,n/2, br1);
    mergeSort(ar2,n/2, br2);

    int * br = new int[n];
    merge(br1,br2,n,br);


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
    
    int *Final = new int[N];

    mergeSort(arr,N,Final);
    
    for (int j = 0 ; j< N ; j++ ){
        printf("%d ",Final[j]);
    }        

}