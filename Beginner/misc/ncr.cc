/*
Author: Sanjay Marreddi
Date: 09-09-2020
*/
#include <stdio.h>


/*
The function takes an Integer, Computes the Factorial and Outputs the Factorial of that Number.
Input : int
Output : int
*/
int factorial(int x) {   int i ;
    int fac = 1;

    if (x == 0) return(fac); 

    else
    { for (i = 1; i <= x; i++) fac = fac * i; } 

    return(fac);
}

int factorial_efficient(int x){
    if (x ==0) 
        {return 1 ;}
    else
        {return x* factorial_efficient(x-1) ;} }


int main()
{
    int n; 
    int r;
    int ncr;
 
    printf("\n Enter the value for n and r : ");
    
    // Taking the input from user.
    scanf("%d%d", &n, &r);

    // Calling the function "factorial" we have defined, to compute the value of ncr.
    ncr = factorial(n) / (factorial(r) * factorial(n - r)) ;

    printf("Value of ncr is =  %d", ncr);
}
 