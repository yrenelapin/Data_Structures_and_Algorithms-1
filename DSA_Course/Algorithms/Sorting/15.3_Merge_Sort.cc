#include <stdio.h>
#include <stdlib.h>

void merge(int * ar1, int * ar2, int n1, int n2, int *ar_final){

        int i = 0, j= 0, k = 0 ;

        while ( i<n1 && j<n2){
             if ( ar1[i] <= ar2[j] ) 
                { ar_final[k] = ar1[i]; i++; }
             else 
                 { ar_final[k] = ar2[j]; j++; }
            k++;
        }

        // Copy the remaining elements if we exit above while loop because of (j < N)
        for ( ; i<n1; i++){
            ar_final[k] = ar1[i];
            k++;
        }

        // Copy the remaining elements if we exit above while loop because of (i < N)
        for ( ; j<n2; j++){
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

Time Complexity  :- O(nlogn).
Space Complexity :- O(nlogn).
*/
void mergeSort(int *arr, int n, int *b ){

    // By Passing Start and End Positions as Input to the Merge Sort Function,
    // We can avoid creating arrays ar1, ar2.

    // Assuming n is EVEN

    if (n < 1) return;

    if (n == 1) { b[0] = arr[0]; return;}

    if (n==2){
        if (arr[0] > arr[1]){
            b[0] = arr[1];
            b[1] = arr[0];
            return;
        }

        if (arr[0] < arr[1]){
            b[0] = arr[0];
            b[1] = arr[1];
            return;
        }

    }

    // Splitting the Array 

    int ar1[n/2];
    for (int i = 0 ; i<n/2 ; i++){
        ar1[i] = arr[i];
    }

    int ar2[n- (n/2)];
    for (int i = n/2 ; i<n ; i++){
        ar2[i-(n/2)] = arr[i];
    }

    // Two Output arrays
    int br1[n/2];
    int br2[n- (n/2)];

    mergeSort(ar1,n/2, br1);

    mergeSort(ar2,(n-(n/2)), br2);

    merge(br1,br2,n/2,(n-(n/2)),b);


}



int main(){

    int data[] = {4,3,1,2,11,22,12,6};

    int N = sizeof(data)/sizeof(data[0]);

    int *arr = data;

    int *Final = new int[N];

    mergeSort(arr,N,Final);
    printf("The Sorted Array is :- \n");
    for (int j = 0 ; j< N ; j++ ){
        printf("%d ",Final[j]);
    }        

}