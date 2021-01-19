/*
Author : Sanjay Marreddi
Roll No : 1904119
Date: 11th September 2020             

This file contains code for an Arithmetic Calculator which can perform addition, subtraction, multiplication, division 
of the two integers provided.
*/

#include <stdio.h>


/*
get_integer :- This function takes input from the user and returns the complete int if the user inputs int. 
                If user inputs float/String It shows Error and returns 0.
Inputs: None
Output: Int 
*/
int get_integer(){

    // Declaring and Initialising the variables.
    char c = getchar() ;
    int i ;
    int num = 0, dots =0 ,chars =0 ;

    // Taking each character from user at a time and identifying the type of character.
    while( c != '\n' ){

        i = c - '0' ;                                       // i has ASCII Code of Character(c) subtracted from ASCII Code of 0. 
    
        if ((i<=9) && (i >=0)) {num = num*10 + i;}          // Checks for Integers and finds the entire number being typed.

        if ((c == '.') && ( (i>9 )|| (i<0)) ){dots+=1;}     // Checks the number of dots(.) present in user input and updates dots variable.

        if ((c != '.') && ( (i>9 ) || (i<0)) ){chars+=1;}   // Checks the number of chars present in user input and updates chars variable.
        
        c = getchar(); }


        //  Checks if the user input is Float and throws error accordingly.
        if ((dots>=1) && (chars==0)){ 
            printf("\nUser input should only be in integer.");
            printf("\n\nBye!");
            return 0 ;
        }

        //  Checks if the user input is String and throws error accordingly.
        if (chars > 0){ 
            printf("\nError in input.");
            printf("\n\nBye!");
            return 0;

        }


    // returns the num if user typed an Integer. 
    return num;    
}



/*
get_operator:- This function takes input from the user and returns the operator if user inputs either of +,-,/,* . 
                If user inputs any other thing, it shows Error and returns 0.
Inputs: None
Output: Char
*/
char get_operator(){
    
    // Declaring and Initialising the variables.
    int check = 0, i = 0 ;
    char operators[4]= {'+','-','*','/'};  // Creating an array of arithmetic operators.
    char op[1] = {} ;                      // Creating an array to store the input characters.
    char c = getchar() ;

    // Taking each character from user at a time and storing in array.
    while( c != '\n' ){
        op[i] = c ;
        i++ ;                 
        c = getchar(); }

    // Checking the presence of operators in user input.
    for(int j=0;j<4;j++)
        {if(operators[j]== op[0])check+=1;}

    // Checks the correctness of user input.
    if ((check <1) || (check>1)){       
        printf("\nError in input.");
        printf("\n\nBye!");
        printf("\n-------------------");
        return 0 ;}

    return op[0];
}



/*
calculate:- This function takes 2 Int inputs and 1 operator from +,-,/,* and does the computation between those two Integers
            and outputs the result. 
Inputs: 2 Ints and 1 Char
Output: float
*/
float calulate(int  x, int y, char c){

    if (c == '+'){ return (x+y); }
    if (c == '-'){ return (x-y); }
    if (c == '/'){ float temp; temp = x; return (temp/y); } // Divison must be done with atleast one float to have an accurate output. 
    if (c == '*'){ return (x*y); }

    return 1.0 ;
}



/*
main :- This function calls all the above defined functions and gives the functionality of a simple Arithmetic Calculator.
Inputs: None
Output: Int 
*/
int main(){

    printf("\nSanjay's Calculator");
    printf("\n-------------------");
    printf("\nEnter the first number:");

    int n1 ;
    n1 = get_integer() ;
    if (n1==0){return 0;}

    printf("\nEnter the operation from +,-,*,/:");
    
    char oper;
    oper = get_operator() ;
    if (oper == 0){return 0;}
    
    printf("\nEnter the second number:");

    int n2 ;
    n2 = get_integer() ;
    if (n2==0){return 0;}

    printf("\nAnswer = %0.3f", calulate(n1,n2,oper));
    printf("\n\nBye!");
    printf("\n-------------------");

    return 0 ;
}
