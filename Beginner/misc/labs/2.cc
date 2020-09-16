#include <stdio.h>

// Declaration and Initialisation of Extern Variables.
int user_input[10];
int counter = 0 ;


int get_integers(){

    // Declaration and Initialisation of Local Variables.
    char c = getchar() ;
    int i;
    int num = 0 ;
    int helper = 0;
    
    while( c != '\n' ){

        i = c - '0';                                    // i has ASCII Code of Character(c) subtracted from ASCII Code of 0. 
                     
        if ((i<=9) && (i >=0)) {num = num*10 + i;} 

        if (i == -4)  { helper+=1;                              // 44 is the ASCII code of , - 48
                            user_input[helper-1]= num ; 
                            num=0; counter+=1 ;}

        c = getchar(); 
    
    if (counter > 9) {return -1 ;}

    }

    helper+=1 ;
    user_input[helper-1]= num ; 
    counter+=1 ;

    return 0 ;
}


/* 
swap - This function swaps the given two array elements
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
permutations- This is a recursive function which generates all the possible permutations of a given array.
Input  - Array, Two Integers.
Output - None
*/
void Permutations (int arr[], int arr_size, int i) {

	/* this function generates the permutations of the array
	 * from element i to element n-1
	 */
	int	j;

	/* if we are at the end of the array, we have one permutation
	 * we can use (here we print it; you could as easily hand the
	 * array off to some other function that uses it for something
	 */
	if (i == arr_size) {
		for (j=0; j<arr_size; j++) printf ("%d ", arr[j]);
		printf ("\n");
	} else
		/* recursively explore the permutations starting
		 * at index i going through index n-1
		 */
		for (j=i; j<arr_size; j++) {

			/* try the array with i and j switched */

			Swap (arr, i, j);
			Permutations (arr, arr_size, i+1);

			/* swap them back the way they were */

			Swap (arr, i, j);
		}
}
			


int main () {
    
    int res = 0;
    res = get_integers();

    if (res==-1){printf("More than 10 Integers are typed !!"); return 0 ;} 


    int result[counter] = {} ;

    for(int i =0; i<counter ; i++){result[i] = user_input[i];}

	Permutations(result,counter, 0);
   

}


