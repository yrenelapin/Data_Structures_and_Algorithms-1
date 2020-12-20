#include <stdio.h>
#include <stdlib.h>


void swap(int *ptr_x,int *ptr_y){

    int temp = *ptr_y ;    

    *ptr_y = *ptr_x ;

    *ptr_x = temp; 
}

/*
Time Complexity :- O(n^2).
Space Complexity :- O(n).
*/
void quickSort(int *arr, int n , int *br){
    
    int pivot = arr[0];
    int l = 0;
    int r = n-1;

    for (int i = 1 ; i<n ; i++){

        if (arr[i]  <= pivot){
            br[l] = arr[i]; l++;
        }
        else{
            br[r] = arr[i]; r--;
        }}
    
    br[l] = pivot;

    // quickSort(br,l,br_new);
    // quickSort(&(br+l+1),n-l,br_new_2);
    // // We need some function that copies from br_new & br_new_2 & makes br.

    // The Given Algo is not yet Complete. We need to complete the implementation still.
     
    // This Algo is actually not at all efficient. But It was Introduced to have the Basic Trick behind Quick Sort.


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
    
    int *result = new int[N];
    
    quickSort(arr,N,result);
    
    for (int j = 0 ; j< N ; j++ ){
        printf("%d ",arr[j]);
    }        

}