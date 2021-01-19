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
void quickSort(int *arr, int s , int n){
    
    if ((n ==1) || (n==0)) return ;

    int pivot = arr[s];
    
    int i = s;
    int j = n-1;

    // We continue till no Crossing happens 
    while (i <= j){
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j-- ;
        if (i < j) { swap(&arr[i],&arr[j]); }
        // printf("I am Inside !\n");
    }

    quickSort(arr, s,i);
    quickSort(arr,i, n-i);


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

    printf("Before Sorting : \n");
    for (int j = 0 ; j< N ; j++ ){
        printf("%d ",arr[j]);
    }    

  
    quickSort(arr,0,N);
    
    printf("After Sorting : \n");

    for (int j = 0 ; j< N ; j++ ){
        printf("%d ",arr[j]);
    }        

}

/*
Finding the Median of Array of Faster atleast O(n) 
and then take it as PIVOT so that we can do Quick Sort in O(nlogn).
But we dont use this since the Algo is Complicated for MEDIAN to make it in O(n).

Randomly finding the PIVOT works in most of the Cases !!
*/