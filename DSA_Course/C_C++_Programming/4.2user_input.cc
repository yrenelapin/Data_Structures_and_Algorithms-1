#include <stdio.h>

int main(){

    char c = getchar();         //scanf - can also be used to get input.

    // getchar() is used to take one character from user input.

    // printf("The letter from Keyboard is : %c",c);

    // We need to take all characters untill we press Enter. Enter is treated as "\n"

    while (c != '\n'){
        printf("\nThe letter from Keyboard is : %c",c);             
        c = getchar();

    }

    printf("\n");

}
/*
Dont put ; after the condition of while loop
Correct way :- while(){}
*/