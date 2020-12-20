#include <stdio.h>
#include <stdlib.h>


int Binary_Search(int *arr, int n , int x){
    
    int start = 0;
    int end = n-1;

    while ( start <= end){
        
        int m = (start + end)/2 ;
        if (arr[m] == x) return 1 ;
        if ( arr[m] > x) { end = m-1;}        
        if ( arr[m]  < x) { start = m+1;}

    } 

    return 0 ;
}

int main(){

    int N;
    printf("Number of Integers in your array :- ");
    scanf("%d",&N);

    
    printf("Enter the Integers in a Sorted Increasing Order:-\n");

    int *arr = new int[N];

    for (int j = 0 ; j< N ; j++ ){
        
        int temp;
        scanf("%d",&temp);
        arr[j] = temp;
    }
    
    int x ;
    printf("Which Integer you want to Search for :- ");
    scanf("%d",&x);

    if (Binary_Search(arr,N,x)){printf("Found !!");}
    else printf("Not Found");

}