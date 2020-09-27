/*
Pointers and Arrays have Close relationship.

*/

#include <stdio.h>


int strlen(char *pstr){
    int len = 0 ;
    // String always has a 0 at the end.

    while (*(pstr+len) != 0 )  len++ ;

    return len ;

}


int main(){ 

    int ar[5]= {10,2,3,4,5};
    int br[5] ={2,4,5,7,8};

    int i = 3 ;
    int z;

    char str[] = "IIT Goa!";
    char *pstr = str ; // We need not use & for arrays.

    // We assigned the address of the first element in array ar to pa.
    int* pa = &ar[0] ;

    printf("Array Value at Index %d is = %d",i,ar[i]);

    // Using pointers to access array elements.
    printf("\n *pa = %d",*pa);

    // Using Pointer just like array.    
    printf("\n pa[%d] = %d", i,pa[i]);

    // Array element can be accessed by using the notation *(pa+i)
    z =  *(pa+i) ;
    printf("\n *(pa+%d) = %d",i,z);

    // Incrementing the pointers in the same way like Integers.
    pa++ ;
    printf("\n *(pa++) = %d",*pa);

    // Another way of accessing.
    printf("\n *(ar+%d) = %d",i, *(ar+i));

    // We assigned the address of the array br to pa. We need not use & for arrays.
    pa = br;
    // In above line we changed the pointer from array ar to br. 


    // ar = br ; 
    // It is not possible to change ar to br like above line.

    // So, Pointer can change its pointing to other location. But array cant do that (From Line 43 and 39).

    // Since we currently know that, Arrays and Pointers are almost same, We can pass and return arrays to Functions using pointers.

    // It just points to first letter of string.
    printf("\n %c",*pstr);

    printf("\n %s",pstr);

    printf("\n%c", *(pstr+2));


    printf("\n Length of (%s) is = %d", pstr,strlen(pstr));
}