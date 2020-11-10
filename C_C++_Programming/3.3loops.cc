#include <stdio.h>

// To print the sum of integers in the array
int sum_forloop(int ar[], int sumupto){

    int sum =0 ;

    printf("\nInside sum function- using for loop");
    int i;

    //for loop :-
    
    // for(Initialisation ; Conditional ; Incrementation/Decrementation)

    //If the condition is not satisfied(False) in the first iteration itself, It wont go through the loop at all.

    // We can use any type of Incrementation/Decrementation like i=i+10, i-=2, i=8*i+1,...

    // If there is only one statement in for loop {} neednot be used 

    for(i=0; i <sumupto; i++){

        sum+=ar[i] ;
        printf("\nValue of i=%d, partialsum=%d",i,sum);

    }

    printf("\nSum = %d",sum);
    printf("\nReturning from sum function- using for loop\n");
    return sum;


}

int sum_whileloop(int ar[], int sumupto) {
    printf("\nInside sum function- using while loop");
    int i;
    int sum;

    i=0 ;
    sum=0;
    while(i<sumupto){
        sum+= ar[i] ;
        printf("\nValue of i=%d, partialsum=%d",i,sum);
        i+=1;

    }
    printf("\nSum = %d",sum);
    printf("\nReturning from sum function- using while loop\n");
    return sum;

}


int main()

{
    int ar[] = {1,2,3,4,5};
    int sumupto = 2;

    sum_forloop(ar,sumupto) ;
    sum_whileloop(ar,sumupto);

    
    printf("\nSumming using do-while loop");
    int i;
    int sum;
    i=0 ;
    sum=0;

    do{  
        sum+= ar[i] ;
        printf("\nValue of i=%d, partialsum=%d",i,sum);
        i+=1;
    }
    while(i<sumupto);

    printf("\nSum = %d",sum);
   
    
}


// Even if we keep sumupto=0, do while still executes once !!
// First program runs once and then Condition is checked in do-while loop unlike while and for loops
