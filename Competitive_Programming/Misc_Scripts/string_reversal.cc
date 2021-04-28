/*
Author : Sanjay Marreddi
Roll No : 1904119
Date: 15th October 2020             

This file contains code for Reversing a string using Dynamic Memory Allocation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Returns the Length of String
*/
int string_len(char *ptr)
{
   int i = 0;
 
   while( *(ptr+i) != '\0' )
      i++;
   return i;
}

int main(){

    char *ptr;
    ptr = (char *)malloc(20*sizeof(char));

    printf("\n Enter the String you want to reverse !! ");
    scanf("%[^\n]",ptr);
    printf("\n The Entered String is : %s ",ptr);

    int len = string_len(ptr);

    int i = 0;
    
    printf("\n The Reversed String is : ");

    for(i=len-1; i>=0;i-=1){
       printf("%c",ptr[i]) ;
    }

    free(ptr);

}
