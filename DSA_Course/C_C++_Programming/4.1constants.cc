#include <stdio.h>
#define ar_size_2 25   // Another way of defining "constants". In this method, Compiler goes through entire code 
                       //and then replaces all the occurences of ar_size_2 with 25.


// We may define constants inside a function too.
void func(){

    const int y =20;    
    printf("\n y=%d",y);
}




int main()

{   
    const int x =25;
    printf("x=%d",x);

    // use of "const"

    int ar[] ={1,2,3,4,5,6}; // This works fine i.e If we are not specifying size of array , we must write the elements there.

    // int ar[];   will create an Error as neither size nor Initialisation is done

    // int ar[10];  will work 

    const int ar_size = 30 ;    // So changing value here will help in dealing with various sizes.

    int array[ar_size];         // Better way to use for declaring arrays instead of using int array[30];

    func();




    // x= 300; Will create an error becoz type of x is "const" . Its value cant be changed anymore. 

}

