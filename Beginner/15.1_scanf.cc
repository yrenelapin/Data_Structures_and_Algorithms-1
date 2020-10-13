#include <stdio.h>

/*
Returns 1 if both are same
*/
int strcmp(char *str1, char* str2){
    int index = 0;
    while ((str1[index]!= '\0') && (str2[index]!= '\0'))
    {
        if (str1[index] != str2[index]) return 0 ;
        index++ ;
    }
    if ((str1[index] == '\0') && (str2[index] == '\0')) return 1;
    return 0;
 
}


int main(){

    char str1[50];
    char str2[50];

    printf("\nEnter String 1: ");
    // scanf("%s",str1); // This will take Delimeter as SPACE

    scanf("%[^\n]",str1); // This says to stop only when NEW LINE is entered 

    printf("\nEnter String 2: ");
    scanf("%s",str2);
    
    printf("\n(%s,%s)\n",str1,str2);

    if (strcmp(str1,str2)==1) printf("\nStrings are Same");
    else printf("\nStrings are different");


    int x ;
    printf("\n Enter an integer:");
    scanf("%d", &x);
    printf("\nInteger Entered is %d",x);

    float y ;
    printf("\n Enter a float:");
    scanf("%f", &y);
    printf("\nfloat Entered is %f",y);

}   