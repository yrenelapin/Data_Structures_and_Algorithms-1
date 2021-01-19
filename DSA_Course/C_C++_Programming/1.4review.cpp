/*
Reviewing the concepts by making simple Info Sheet.
*/

#include <stdio.h>

int main()

{   char Gender = 'M' ;
    int mark_cs101 = 10;
    int mark_ee101 = 9 ;
    int mark_me101 = 10;
    int mark_hs101 = 9 ;

    float cs101 = mark_cs101 ; // Making sum as float
    float cgpa = (cs101+mark_ee101+mark_hs101+mark_me101)/4 ;

    printf("Name: Sanjay Marreddi\n") ;
    printf("Gender: %c \n",Gender);
    printf("\n---------------------------");
    printf("\nFirst Semester Mark Sheet");
    printf("\n---------------------------");
    printf("\nProgramming CS101:\t %d",mark_cs101);           // Using "\t" helped in maintaining the Order of the Output.
    printf("\nElectronics EE101:\t %d",mark_ee101);
    printf("\nMechanics ME101:\t %d",mark_me101); 
    printf("\nHumanities HS101:\t %d",mark_hs101);   
    printf("\n---------------------------");
    printf("\nCGPA:\t\t\t %0.2f",cgpa);


}