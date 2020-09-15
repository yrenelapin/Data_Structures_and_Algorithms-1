#include <stdio.h>


/*This function returns the factorial of an Integer*/
int factorial(int n){

    int x = 0;

    if (n==0){       
        return 1;
        }                           // Base Case

    x = factorial(n-1) ;            // Recursive Step

    return(n*x);
}


/* The function returns the sum of the integers in the input array*/
int sumofarray(int ar[] , int size_of_array){
    
    int x =0 ;

    if (size_of_array== 0){return 0;}       // Base Case

    x = sumofarray(ar, size_of_array-1);    // Recursive Step - It computes the sum of size_of_array-1 numbers.

    return ( x + ar[size_of_array-1] ); 
}



int main(){

    int fac;
    int m =3 ;
    fac = factorial(m);
    printf("\n\nFactorial of %d is %d",m,fac);

    const int ar_size= 5 ;
    int arr[ar_size] = {1,2,3,4,5};
    printf("\n Sum of integers in the array = %d", sumofarray(arr,ar_size)) ;
}


// Above both functions are examples of LINEAR RECURSION