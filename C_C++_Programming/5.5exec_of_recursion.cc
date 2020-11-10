#include <stdio.h>

/*
There are two methods of Producing Indentations similar to BLOCK EXECUTION of Recursive Functions.
In Method 1, We define the tab as EXTERN VARIABLE. We manipulate it manually outside.
In Method 2, We pass it as an Argument to function and also Manipulate it while calling the factorial recursively.
*/


// METHOD - 1

int tab = 0 ;

void print_tab(){
    int i = 0 ;
    printf("\n");
    for(i=0; i<tab; i++) printf("\t");
}


int factorial(int n){

    int x = 0;

    // In Method 1 as tab is in Global Space No need of passing the tab parameter for print_tab function.
    print_tab(); printf("n = %d", n);
    print_tab(); printf("x = %d",x );   


    if (n==0){
        print_tab();  printf("Base Case - Return 1");
        return 1;
        } // Base Case

    print_tab(); printf("Going to call the factorial function.");
    
    tab++;

    x = factorial(n-1) ;    // Recursive Step
    
    tab--;  

    print_tab(); printf("Returned from Recursive Step");
    print_tab(); printf("x=%d",x);
    print_tab(); printf("Return %d", n*x);

    return(n*x);

}


int main(){

    int fac;
    int m =3 ;
    fac = factorial(m);
    printf("\n\nFactorial of %d is %d",m,fac);

}




//----------------------------------------------------------------------------------------------------------------

// METHOD - 2



// #include <stdio.h>

// void print_tab(int tab){
//     int i = 0 ;
//     printf("\n");
//     for(i=0; i<tab; i++) printf("\t");
// }


// int factorial(int n, int tab){

//     int x = 0;
    

//     print_tab(tab); printf("n = %d", n);
//     print_tab(tab); printf("x = %d",x );   


//     if (n==0){
//         print_tab(tab);  printf("Base Case - Return 1");
//         return 1;
//         } // Base Case

//     print_tab(tab); printf("Going to call the factorial function.");
    
   

//     x = factorial(n-1, tab+1) ;    // Recursive Step
    
//     print_tab(tab); printf("Returned from Recursive Step");
//     print_tab(tab); printf("x=%d",x);
//     print_tab(tab); printf("Return %d", n*x);

//     return n*x ;
// }


// int main(){

//     int fac;
//     int m =3 ;
//     fac = factorial(m,0);
//     printf("\n\nFactorial of %d is %d",m,fac);
// }



