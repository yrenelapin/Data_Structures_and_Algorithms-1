#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){

    // Use this block of code to store an array of Integers from the user using scanf.
    int N ;
    scanf("%d",&N);
    int Arr[N];
    for (int i = 0; i<N; i++)
    {
        scanf("%d",&Arr[i]);
    }


    for (int i =0; i<N;i++){
         int s = 0;
         for (int j =i; j<N; j++){
            s+= Arr[j]; 
            int s_root = sqrt(s);
            if (s_root*s_root == s ){
              printf("%d %d \n",i,j);
            }
        }
    }
}