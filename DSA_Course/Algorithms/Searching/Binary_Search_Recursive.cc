#include <stdio.h>
#include <stdlib.h>

int Binary_Search(int *arr, int start , int end, int x){
    
    if (start == end ){
         if (arr[start] == x) return 1;
         else return 0;
    }

    int m = (start+end)/2;

    if (arr[m] == x) return 1 ;
    if ( arr[m] < x) {  return (Binary_Search (arr,m+1,end,x)) ; }        
    if ( arr[m] > x) {  return (Binary_Search (arr,start,m-1,x)) ; }   
    
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

    if (Binary_Search(arr,0,N-1,x)){printf("Found !!");}
    else printf("Not Found");

}