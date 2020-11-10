#include <stdio.h>


              // Extern Variable : Can be accessed by any Function.
int x = 100 ; // Again if this is defined below the "scope" function and "int x= 20" is removed in the scope function, Then an Error Occurs



void scope(){
    int x = 20 ; // If this declaration is removed and "int x =100" is present above this function,Then the below printf takes the value of x =100 from outside

    printf("\n Value of x in scope function = %d",x);
}


int main(){
    int x = 0 ; // If this line and "int x =20 " from scope function are removed and "intx =100" is present above, Then both outputs x=100.
    printf("\n Value of x in main = %d",x);
    scope();

    x = 50;
    scope() ;

// So it means same variable name can have different values depending on value being assigned at that scope

}


// Takeaway :-

/*
If a variable is declared inside the function, then the function uses the value to which the variable is assigned there .

If we didnot declare the variable inside a function, It takes the value from outside the function


So preference is for INSIDE.

When we are accessing a variable in a Function,

If the variable is not declared either in the same function or completely outside all the functions, It creates error even
if we defined that function in some other function...



*/