/*
Subarrays with Sum as Perfect Square
Given an array A of N integers, write a program to print the start and end indices of all subarrays whose sum is a perfect square in lexicographic order.

Here, lexicographic order means, the subarray with minimum start index should be printed first. If there is more than one subarray with the same start index, prefer the one that has minimum end index among them first.
Note: There is at least one subarray with sum as perfect square.
Input

First line contains a single integer N.
Second line contains N space separated integers of A.
Output

Print the start index and the end index of each such subarray separated by a space in a new line. The printed order must be in lexicographic order.
*/


 // PREFIX SUM APPROACH

 
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