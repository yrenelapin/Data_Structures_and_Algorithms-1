#include <stdio.h>


// Returns the n-th fibonnaci number

int fibonacci(int n){
    if ((n==1)|| (n==2)) return 1;
    
    return (fibonacci(n-1)+ fibonacci(n-2)) ;
}


int main(){

    int n = 10;
    printf("%d -th Fibonnaci number is %d",n,fibonacci(n));
    printf("\n");

}