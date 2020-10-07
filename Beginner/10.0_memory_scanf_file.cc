#include <stdio.h>

int main(){

    char ar[100];
    // Takes only single Char Array 
    scanf("%s",ar);
    printf("%s \n",ar);


    // Reading the Data from file..
    char ar2[100];

    FILE *fp;
    
    fp = fopen("test.txt","a");
    fscanf(fp,"%s",ar2);
    printf("%s",ar2);
    
    // Appending the Data to the File.
    char ar3[100] = "Bye !" ;
    fprintf(fp,"%s",ar3) ;
    fclose(fp);


}