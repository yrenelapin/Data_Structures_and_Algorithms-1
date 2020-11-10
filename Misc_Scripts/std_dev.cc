/*
Author : Sanjay Marreddi
Roll No : 1904119
Date: 15th October 2020             

This file contains code for Finding Standard Deviation of Real Numbers Entered using Dynamic Memory Allocation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int Find_Average(float array[],int n){

    float average;
    int i, sum = 0 ;
    
    /* Finding the sum of all elements */
    for (i = 0; i < n; i++) {   sum = sum + array[i] ;}

    average = sum / (float)n ;

    return average ;
}

int main()
{
  
    int  i, n;
    float sum = 0,Variance, Std_Deviation ;
    float *ptr;
 
    printf("\n How many Real Numbers you had ? : ");
    scanf("%d", &n);

    // Dynamic Memory Allocation
    ptr = (float *)malloc(n*sizeof(float));
    printf("\n Please Enter %d real numbers with SPACE as delimeter: ", n);

    // Taking Input from User.
    for (i = 0; i < n; i++) scanf("%f", &ptr[i]);
    
    // Computing the Deviation from the Average
    for (i = 0; i < n; i++) sum = sum + pow( (ptr[i] - Find_Average(ptr,n)), 2) ;
    
    // Finding Variance and Standard Deviation
    Variance = sum / (float)n;
    Std_Deviation = sqrt(Variance);

    printf("\n The Standard deviation of Real Numbers Entered is = %f\n", Std_Deviation);

    free(ptr);
}

