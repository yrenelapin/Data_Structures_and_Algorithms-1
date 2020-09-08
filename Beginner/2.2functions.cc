#include <stdio.h>

/* 
The following line tells the complier that a function called square will be defined later.and the function takes an Int as Input and outputs an Int again.

This method helps us in situations like this where we have defined a function after using it 
Ex: We used "square" function in "sumofsquares" function but defined the function "square" later on.

We can also solve this problem by altering the position of code so that function is declared and defined before it is being used. 

*/
int square(int y);


// We need to define the type of value returned by the function


/*
This function computes sum of squares of two numbers and prints it.
Input : Int,Int
Output : None
*/
void sumofsquares(int x,int y){
    int sumofsq =square(x)+ square(y);
    printf("\nSum of Squares of %d and %d is %d",x,y,sumofsq);
    return ; // U may add this simply.
    }




/*
This ouputs Square of Integer 
Input:Int
Ouput:Int
*/
int square(int x){
    int sq = x*x ;
    return sq ;
}

// Ingenral any combinations of Input and Output are Possible between int and float


float squareoffloat(float y){
    return y*y;

}

// To define functions that wont return anything we use "void" type


// Functions will be defined by us outside main function.


// Executio of functions defined starts inside this main() function.
int main(){

    int y =5 ;
    int a ;
    float b = 5.7;
    a = square(y);

    printf("Square of %d = %d",y,a);
    printf("\nSquare of %0.2f = %.2f",b,squareoffloat(b));
    
    sumofsquares(y,y+1);

    return 0 ; // Main function can return integer to the Terminal

}




