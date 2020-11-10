#include <stdio.h>

/*  && is for AND
    || is for OR
    !  is for NEGATION
*/

int main()
{
    int cs220 = 95;

    // Unlike Python, We need not use Indentation or : 
    // But better to use Indentation for better Readability

    // if (cs220>=40) 
    //     printf("Passed");
    // else 
    //     printf("Failed");


    if ( !(cs220 >=40) )   
        printf("Failed\n");

    else 
        printf("Passed\n");
    

    // Giving Grades based on marks 

    if (cs220>90){ 
        printf("A grade\n");
        printf ("Congrats"); }

    else 
        if ((cs220 <= 90) && (cs220 >80) ) 
            {printf("B Grade\n");
            printf("A little more effort required") ;}
        else
            if ((cs220 <= 80) && (cs220 >70) ) 
                {printf("C Grade\n") ;}
            else
            {
                printf("Less than C grade\n") ;
                printf("Work Hard !!");
            }
            
    
    
// Using { } everytime even if we have less than 2 commands is better for readability

}

