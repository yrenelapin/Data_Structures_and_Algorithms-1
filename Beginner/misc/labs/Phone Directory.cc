/*
Author  : Sanjay Marreddi
Roll No : 1904119
Date    : 1st November 2020             

This file contains code for making a Phone Directory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct PhoneNumber
{
    long long int Number;
    char Details[50];
};

struct Phone_Dir
{
    char name[50];
    int noOfPhone;
    struct PhoneNumber *phone ;
};


/*
writeToFile -> It takes an Phone Directory Structure and writes it to the File.  
*/
int writeToFile(struct Phone_Dir phonedir){

        int i ;

        FILE* fp = fopen("directory.txt","a");

        if (fp==NULL) return 1;

        fprintf(fp,"%s \n%d \n", phonedir.name, phonedir.noOfPhone);

        for(i=0;i<phonedir.noOfPhone;i++){
            fprintf(fp,"%lld %s \n",phonedir.phone[i].Number, phonedir.phone[i].Details);

        }

        fclose(fp);
        return 0 ;
}



/* 
readStudentInfo -> It takes input from the User and Populates the Structure and returns it. 
*/
struct Phone_Dir readStudentInfo(){
    struct Phone_Dir phonedir ;
    int i;

    printf("\nEnter the name: ");
    char temp = getchar();
    scanf("%[^\n]",phonedir.name);
    printf("\nEnter the Number of Phone Numbers you have: ");
    scanf("%d",&phonedir.noOfPhone);

    // Allocating Dynamic Memory
    phonedir.phone = (struct PhoneNumber*) malloc(phonedir.noOfPhone*sizeof(struct PhoneNumber));

    for (i=0;i<phonedir.noOfPhone;i++){
        printf("\nEnter your Phone Number %d : ", i+1);
        scanf("%lld", &phonedir.phone[i].Number);
        char temp = getchar();
        printf("\nEnter a Comment regarding Phone Number %d : ",i+1);
        scanf("%[^\n]",phonedir.phone[i].Details);

    }
    temp =  getchar();
    return phonedir;
}


/*
printStudentInfo  -> It takes an Phone Directory Structure and Prints the Contents of it.
*/
void printStudentInfo(struct Phone_Dir phonedir){

    if (phonedir.noOfPhone != 0 ){

    int i ;

    printf("\nTelphone Directory \n Name: %s \n Number of Phone Numbers : %d \n",phonedir.name,phonedir.noOfPhone);

    for(i=0;i<phonedir.noOfPhone;i++){
        printf("\n(%d) Phone Number is %d \nDetails of Phone Number:%s",i+1,phonedir.phone[i].Number,phonedir.phone[i].Details);
    }
    }

    else {printf("Sorry! No Entries Found !!");}
    char temp1 = getchar();  
}


/*
clearMemory  -> It Clears the Dynamically alloted memory.
*/
void clearMemory(struct Phone_Dir phonedir){
    free (phonedir.phone);
}


/*
readFromFile -> Reading all the Structures from the File one by one and checks if it has name that matches with the User Input and returns the
Corresponding Structure If it exists. If it does not exist, It returns an Empty Structure.  
*/
struct Phone_Dir* readFromFile(){

    int i ;

    struct Phone_Dir *phonedir = (struct Phone_Dir* ) calloc(1,sizeof(struct Phone_Dir));

    FILE* fp = fopen("directory.txt","r");

    if (fp==NULL) return NULL;

    char temporary = getchar();

    char user[50];

    printf("\nEnter the name to look up :");

    scanf("%[^\n]",user);

    while ( (fscanf(fp,"%[^\n]",phonedir->name) != EOF ) )
    {
            
            fscanf(fp,"%d", &phonedir->noOfPhone);

            phonedir->phone = (struct PhoneNumber*) calloc (phonedir->noOfPhone,sizeof(struct PhoneNumber));

            for(i=0;i<phonedir->noOfPhone;i++){
                fscanf(fp,"%d %[^\n]",&phonedir->phone[i].Number,
                phonedir->phone[i].Details);}

            int j = 0 ;
            int check = 0 ;

            while(user[j] != '\0')
            {
                if(user[j]==phonedir->name[j]){
                    check = 1;
                    j++; }
                else {check = 0 ; break ;}    
            }

           
            if (check == 1)  return phonedir;

    }

    clearMemory(*phonedir);
    struct Phone_Dir *temp_struct = (struct Phone_Dir* ) calloc(1,sizeof(struct Phone_Dir));
    temp_struct->noOfPhone = 0 ;
    return  temp_struct;
    fclose(fp);

}


/*
SearchAndInform -> It calls the above required functions and renders the Functionality of Searching and giving the Information.
*/
void SearchAndInform(){

    struct Phone_Dir *phd = readFromFile();
    printStudentInfo(*phd);
    clearMemory(*phd);
    free(phd);

}


/*
Replace -> It Replaces all the occurrences of a given a word in string.
Input   -> String, Two Words
*/
void Replace(char *str, const char *Old_Word, const char *New_Word)
{   
    const int BUFFER_SIZE = 1000 ;
    char temp[BUFFER_SIZE];

    char *position ;
    int index = 0;
    int Old_Len = strlen(Old_Word);

    // Repeat till all occurrences are replaced. 
    while ((position = strstr(str, Old_Word)) != NULL)
    {
        // Copying the Current Line
        strcpy(temp, str);

       // Getting the Index
        index = position - str;

        // Ending the string after word found index
        str[index] = '\0';

        // Concatenate str with new word 
        strcat(str, New_Word);
        
        // Concatenate str with remaining words after Old_Word found index.
        strcat(str, temp + index + Old_Len);
    }
}


/*
FindAndReplaceInFile -> It looks for the word in the text file and replaces with the new specified word.
*/
void FindAndReplaceInFile()
{   
    int i ;
    const int BUFFER_SIZE = 1000 ;
    char buffer[BUFFER_SIZE];

    for (i = 0 ; i<2 ;i++){

    FILE * File_Ptr;
    FILE * Temp_File_Ptr;
    char path[100] = "directory.txt";
    
    char Old_Word[30], New_Word[30];

    if ( i== 0 ){ 
    printf("Enter the Name you want to Modify: ");
    char temp = getchar ();
    scanf("%[^\n]", Old_Word);

    printf("Replace the above one with :-  ");
    temp = getchar ();
    scanf("%[^\n]", New_Word);}

    else {
    
    printf("\nEnter the Number you want to Modify: ");
    char temp = getchar ();
    scanf("%[^\n]", Old_Word);

    printf("Replace the above one with :-  ");
    temp = getchar ();
    scanf("%[^\n]", New_Word);
    
    }

    File_Ptr  = fopen(path, "r");
    Temp_File_Ptr = fopen("replace.tmp", "w"); 


    if (File_Ptr == NULL || Temp_File_Ptr == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    // Read line from Main file and write to destination file after replacing the given word.

    while ((fgets(buffer, BUFFER_SIZE, File_Ptr)) != NULL)
    {
        // Replace all occurrence of word from current line
        Replace(buffer, Old_Word, New_Word);

        // After replacing write it to temp file.
        fputs(buffer, Temp_File_Ptr);
    }


    fclose(File_Ptr);
    fclose(Temp_File_Ptr);

    // Deleting the original source file 
    remove(path);

    // Renaming the temp file as original file
    rename("replace.tmp", path);

    printf("\nSuccessfully replaced '%s' with '%s'.", Old_Word, New_Word);

    }
    char temp = getchar();
}


/*
Calling the above Functions and giving the entire Functionality of Phone Directory
*/
int main(){

    do {
    printf("\nWelcome to your name's phone directory! \nEnter a command (S - for Search, A - Add, M - Modify, Q - Quit): ");    
    char cmd ;
    scanf("%c",&cmd);

    if(cmd=='A'){
    struct Phone_Dir phonedir = readStudentInfo();
    writeToFile(phonedir);
    clearMemory(phonedir);
   }
   
    if(cmd=='M'){ FindAndReplaceInFile();}

    if(cmd=='S'){ SearchAndInform();  }

    if (cmd=='Q') {break ;}

    } while (true);

    return 0 ;
}