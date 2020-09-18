/*
Author  : Sanjay Marreddi
Roll No : 1904119
Date    : 18th September 2020             

This file contains code for printing all Permutations of an array of elements entered by the user.
*/


#include <stdio.h>


// Declaration and Initialisation of Extern Variables.
int user_input[10];
int counter = 0 ;


/*
get_integers :- This function takes comma separated Integers as input from the user and appends them in the array named "user_input".   
                If user inputs more than 10 Integers, It returns -1.
Inputs: None
Output: Int 
*/
int get_integers(){

    // Declaration and Initialisation of Local Variables.
    char c = getchar() ;
    int i;
    int num = 0 ;
    int helper = 0;     // helps in appending the elements in Array.
    
    while( c != '\n' ){

        i = c - '0';                                    	// i has ASCII Code of Character(c) subtracted from ASCII Code of 0. 
                     
        if ((i<=9) && (i >=0)) {num = num*10 + i;} 			// If user Inputs Integer, It updates num variable accordingly.

        if (i == -4)  { helper+=1;                          // This checks for presence of comma.								
                            user_input[helper-1]= num ; 	// 44 is the ASCII code of , so 44 - '0' = -4
                            num=0; counter+=1 ;}

        c = getchar(); 
    
    if (counter > 9) {return -1 ;}					

    }

	// This helps in grabbing the last Integer entered by the User. (Assuming that No Comma is present at the end when user Inputs)
    helper+=1 ;
    user_input[helper-1]= num ; 
    counter+=1 ;

    return 0 ;
}


/* 
Swap - This function swaps the given two array elements.
Input  - Array, Two Integers.
Output - None
*/
void Swap (int arr[], int i, int j) {
	
    int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


/*
Permutations- This is a recursive function which generates all the possible permutations 
of a given array from element i to element ar_size-1.
	 
Input  - Array, Two Integers - i , ar_size .
Output - None
*/
void Permutations (int arr[], int arr_size, int i) {

	int	j;

	// If we are at the end of the array, we have only one permutation.
	if (i == arr_size) {
		printf("\n");
		for (j=0; j<arr_size; j++) printf ("%d ", arr[j]);
		
	} else
		
		// Recursively checking the permutations starting at index i going through index n-1.
		 for (j=i; j<arr_size; j++) {
			
			// Swap the array elements at i and j indices. 
			Swap (arr, i, j);
			
            // Calling the Permutations function again with i+1.
			Permutations (arr, arr_size, i+1);

			// Swap the elements at i and j indices again to keep them in the usual way. 
			Swap (arr, i, j);
		}
}
			

/*
main :- This function calls all the above defined functions and gives the functionality of Printing the Permutations.
Inputs: None
Output: Int 
*/
int main () {
    
    int res = 0;

	printf("\nEnter the Integers with comma separating them :- ");
    res = get_integers();

    if (res==-1){printf("\nMore than 10 Integers are typed !!"); return 0 ;} 

	printf("\nThe permutations of the entered Integers are :-");
	Permutations(user_input,counter, 0);   

}


