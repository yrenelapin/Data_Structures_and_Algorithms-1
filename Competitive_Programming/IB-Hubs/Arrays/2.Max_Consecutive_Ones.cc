/*
Max Consecutive Ones
Given a Binary array A of N length, write a program to find the maximum number of consecutive 1s in A.

Input
First line contains a single integer N.
Second line contains N space separated integers of A.

Output
Print a single integer representing the maximum consecutive 1s in A.
*/


// LINEAR APPROACH


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int N ;
    scanf("%d",&N);
    int Arr[N];
    for (int i = 0; i<N; i++)
    {scanf("%d",&Arr[i]);}
    int current = 0 ;
    int max = 0 ;

    
    for (int j =0 ; j<N ; j++)
    { if (Arr[j] == 1) {current+=1;}
      else { if (current> max) { max =  current;current = 0; }
             else {current = 0 ;}    
    }
}   if (current > max) {printf("%d",current); return 0; } 
    printf("%d",max);   
}
