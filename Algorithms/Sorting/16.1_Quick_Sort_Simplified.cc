#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr_x,int *ptr_y){
    int temp = *ptr_y ;    
    *ptr_y = *ptr_x ;
    *ptr_x = temp; 
}

/*
Time Complexity  :-  O(n^2)
Space Complexity :-  O(n)
*/

void quickSort(int *arr, int n , int *br){
    
    if (n==0) return ;
     
    if (n==1){ br[0]= arr[0]; return;}

    if (n==2){
        if (arr[0] > arr[1]){
            br[0] = arr[1];
            br[1] = arr[0];
            return;
        }

        if (arr[0] < arr[1]){
            br[0] = arr[0];
            br[1] = arr[1];
            return;
        }

    }

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
    
    // Now l = r this is the place to keep PIVOT.
    br[l] = pivot;

    int *br_new = new int[l];    
    quickSort(br,l,br_new);

    int *br_new_2 = new int[n-l-1];
    quickSort( br+l+1, n-l-1, br_new_2);

    for (int j = 0; j<l ; j++){
        br[j] = br_new[j];
    }

    for (int j = 0; j<(n-l) ; j++){
        br[j+l+1] = br_new_2[j];
    }
}


int main(){

    int data[] = {4,3,1,2,11,22,12,6};

    int N = sizeof(data)/sizeof(data[0]);

    int *arr = data;

    int *Final = new int[N];
    
    quickSort(arr,N,Final);
    
    printf("The Sorted Array is :- \n");
    for (int j = 0 ; j< N ; j++ ){
        printf("%d ",Final[j]);
    }        

}