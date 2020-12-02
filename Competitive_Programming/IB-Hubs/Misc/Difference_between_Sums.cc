
#include <stdio.h>
#include <stdlib.h>

int ind = 0;
int sum_of_comb[10^5];
int count = 0;

void combinationUtil(int arr[], int n, int r, 
                     int index, int data[], int i); 
  
// The main function that prints all combinations of  
// size r in arr[] of size n. This function mainly 
// uses combinationUtil() 
void printCombination(int arr[], int n, int r) 
{ 
    // A temporary array to store all combination 
    // one by one 
    int data[r]; 
  
    // Print all combination using temprary array 'data[]' 
    combinationUtil(arr, n, r, 0, data, 0); 
} 
  
/* arr[]  ---> Input Array 
   n      ---> Size of input array 
   r      ---> Size of a combination to be printed 
   index  ---> Current index in data[] 
   data[] ---> Temporary array to store current combination 
   i      ---> index of current element in arr[]     */
void combinationUtil(int arr[], int n, int r, int index, 
                     int data[], int i) 
{ 
    // Current cobination is ready, print it 
    if (index == r) { 
        int sum = 0;
        for (int j = 0; j < r; j++) 
            { // printf("%d ", data[j]);
            sum+=data[j];}
        
        sum_of_comb[ind] = sum;
        ind++;
        count++;
        // printf("\n"); 
        return; 
    } 
  
    // When no more elements are there to put in data[] 
    if (i >= n) 
        return; 
  
    // current is included, put next at next location 
    data[index] = arr[i]; 
    combinationUtil(arr, n, r, index + 1, data, i + 1); 
  
    // current is excluded, replace it with next 
    // (Note that i+1 is passed, but index is not 
    // changed) 
    combinationUtil(arr, n, r, index, data, i + 1); 
} 
   
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 



int main(){
    int N;
    scanf("%d",&N);
    int K;
    scanf("%d",&K);
    int A[N];
    for (int i = 0 ; i<N ; i++){
        scanf("%d",&A[i]);
    }
    printCombination(A, N, K); 
    mergeSort(sum_of_comb, 0, count - 1);
    printf("%d",sum_of_comb[count-1]-sum_of_comb[0]);
}
