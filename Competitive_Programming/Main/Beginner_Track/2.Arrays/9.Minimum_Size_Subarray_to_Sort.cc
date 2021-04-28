/*
Given an array A of N integers, write an efficient program to find the minimum subarray such that if we sort the subarray in non-decreasing order, the entire A will be sorted in non-decreasing order.

Input
First line contains a single integer N.
Second line contains N space separated integers A[i].

Output
Print the start index and end index of the subarray separated by a space. Print -1 if A is already sorted.
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int N ;
    scanf("%d",&N);
    int arr[N];
    for (int i = 0; i<N; i++){
        scanf("%d",&arr[i]);
    }
    int checker = 0;
    int start = 0;
    while (start <N-1 ){
        if (arr[start] > arr[start+1] ) {printf("%d ",start); checker++; break;}
        start++;
    }
    
    int end  = N-1;
    while (end > 0){
        if (arr[end] < arr[end-1]) { printf("%d ",end);checker++; break;}
        end--;
    }
    
    if (checker ==0 ){printf("%d",-1);}
    
}