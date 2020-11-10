#include <stdio.h>

int main()
{
    int i = 1, 2, 3;
    
    printf("%d", i);
    
    /*COMPLIER ERROR
    Comma acts as a separator here. The compiler creates an integer variable and initializes it with 1. The compiler fails to create integer variable 2 because 2 is not a valid identifier.*/

    return 0;
}


#include <stdio.h>

int main()
{
    int i = (1, 2, 3);
    
    printf("%d", i);
    /*
    Prints 3
    The bracket operator has higher precedence than assignment operator. The expression within bracket operator is evaluated from left to right but it is always the result of the last expression which gets assigned. 
    
    */
    
    return 0;
}



#include <stdio.h>

int main()
{
    int i;
    
    i = 1, 2, 3;
    printf("%d", i);
    /*
    Prints 1
    Comma acts as an operator. The assignment operator has higher precedence than comma operator. So, the expression is considered as (i = 1), 2, 3 and 1 gets assigned to variable i.
    */
    
    return 0;
}