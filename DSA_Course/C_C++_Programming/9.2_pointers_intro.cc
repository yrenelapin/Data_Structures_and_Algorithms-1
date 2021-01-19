#include <stdio.h>

int main()
{
    printf("Sizeof(int) in My Laptop is %d",sizeof(int));


    int x = 10 , y = 20;

    int z ;

    int *ip ; // Declare a pointer which points to an integer data-type

    // Other ways to declare a pointer.
    char* ptr_2 ; 
    float * ptr_3 ;

    // Assigning the address of variable x to pointer named ip

    ip = &x ; // We could have declared and asiigned at the same time using  int *ip = &x 

    // The value in the address pointed by ip is now assigned to z.

    z =  *ip ;


    printf("\n x = %d",x);

    // To print a non-negative number we can use %u
    printf("\n Address of x = %u",ip);

    printf("\n Value at location where ip points = %d",*ip);
    
    printf("\n z=%d",z);


    x = 11 ;  // equivalent to *ip = 11

    printf("\n\n After Changing the value of x");
    printf("\n x = %d",x);

    // To print a non-negative number we can use %u
    printf("\n Address of x = %u",ip);

    printf("\n Value at location where ip points = %d",*ip);
    
    printf("\n z=%d",z);


    *ip = 20 ;  // equivalent to x = 20

    printf("\n\n After Changing the value of x");
    printf("\n x = %d",x);

    // To print a non-negative number we can use %u
    printf("\n Address of x = %u",ip);

    printf("\n Value at location where ip points = %d",*ip);
    
    printf("\n z=%d",z);


    *ip = *ip + 10 ;  // x = x + 10

    printf("\n x = %d",x);

    // * and ++ are Singleton Operators. So better use ()

    (*ip)++ ;   // This is different from *(ip++)

    printf("\n x = %d",x);


}