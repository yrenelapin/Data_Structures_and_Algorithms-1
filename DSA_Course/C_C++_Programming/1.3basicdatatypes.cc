/*
1. Integers    - int
2. Floats      - float
3. Characters  - char
*/


#include <stdio.h>

int main()

{   // We need to specify datatype in C for each variable
    float floatnum, floatnum2;
    int q; 
    int var = 20; 
    char ch = 'a' ; // Note that We should use '' (Single Quotes) for char and  Only 1 Letter should be present in char datatype's value

    q = var * 2 ;

    q+=1;       // q++ or q=q+1 are doing same increment

    q = q - var ;

    q = q/2;   // As q is told to be int, 10.5 is converted to 10

                // In C Fractional Numbers are called floats.

                // We cant change datatype of a variable once declared 

    floatnum = 10.5; // All the declarations must be done at the beginning of function for ease of notation.

    printf("var=%d , q= %d \n",var,q);  // printing variables using printf

    printf("floatnum=%f \n",floatnum);

    printf("floatnum=%0.2f \n",floatnum);  // prints only 2 digits after decimal

    // %d --> For Integers
    // %f --> For Floats
    // %c --> For Characters


    // floatnum = 21/2; // Prints 10 only becoz compiler thinks integer/integer should be integer

    // floatnum2 =21;
    // floatnum = floatnum2/2 ;  // prints 10.5 becoz float/Int is done here

    printf("Character=%c \n",ch); 

}