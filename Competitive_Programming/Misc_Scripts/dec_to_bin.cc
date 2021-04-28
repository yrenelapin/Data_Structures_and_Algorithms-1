/*Author : Sanjay Marreddi
Date     : 23rd September 2020                                                           
*/

#include <stdio.h> 


/*
This Function takes a Decimal and returns the Binary form of that Decimal.
*/
int decimal_to_binary(int decimal) 

{   int temp1, temp2;

    if (decimal == 0)                               // Base Case
        return 0;  
    
    temp1 = decimal_to_binary(decimal / 2) ;        // Recursive Step

    temp2 = 10*temp1 ;

    return (decimal % 2 + temp2 ); 
} 
  
int main() 
{  
    printf("The Binary form of %d is %d",4,decimal_to_binary(4)); 
    return 0; 
} 
