#include <stdio.h>
#define MAXSIZE 30

/*
getnum- Takes a number from the user and returns the Number in Int type
Input : None
Output: An integer type of Number inputted by user.
*/
int getnum(){

    char c;
    int i=0 ;
    int sum = -1;    // This is used so that When user Inputs Nothing and Types Enter, "-1" is returned as an indication of Error in input
    
    c = getchar();

    // When exiting the block, sum will be the integer notation for the number entered.

    while (c != '\n'){

    /*    printf("\nCharacter, c=%c",c );

        i = c;              // Storing character as its Ascii code Integer

        printf("\nASCII Code for the character is:%d",i);

        i = c - '0';        // It means subtracting the character's ASCII code from ASCII Code of zero to get number in Integer Notation

        printf("\nNumber in integer notation:%d",i);

    */   


        i = c- '0' ;                     // if c='5' (letter 5), then i=5(integer 5).

        if ((i<0) || (i>9))
        {   return -1;    }

        if ( sum== -1){ sum=0 ; };  // Once we entered the while loop, It indicates that atleast one character is
                                    // typed by user before pressing Enter. It means now we can keep sum=0 to start our process
                                    // of finding Number Typed by User.

        sum = sum*10 + i ;          // This is the point where important calculation is being done. 

        c = getchar();
    }

    return sum;
}


char str[MAXSIZE];  // Array of char's.

int getstring(){

    int i = 0 ;
    char c = getchar();
    while (c != '\n'){

        str[i] = c ;  // Assigning the elements to an Array

        c = getchar();
        i+=1;}

    str[i] = '\0' ;  // Adding the End Element for the Array
    return i;

}

int main()

{
    
int num =0;
printf("\nPlease enter a number: ");

num = getnum();
printf("\n Number = %d and two times that number is : %d",num,2*num);

printf("\nInput String : ");
getstring();
printf("String = %s",str);
printf("\n");

}