#include <stdio.h>
#include <stdlib.h>


int Linear_Search(int *arr, int n , int x){
    
    for (int i = 0; i<n ; i++){
        if (arr[i] == x) return 1;
    }

    return 0;

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
    
    int x ;
    printf("Which Integer you want to Search for :- ");
    scanf("%d",&x);

    if (Linear_Search(arr,N,x)){printf("Found !!");}
    else printf("Not Found");

}