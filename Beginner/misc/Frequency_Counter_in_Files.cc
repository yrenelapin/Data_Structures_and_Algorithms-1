/*
Author : Sanjay Marreddi
Roll No : 1904119
Date: 22nd October 2020             

This file contains code for a program which reads a text file "file.txt" and prints how many times the word "IIT" occurs in the file.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*
Frequency_Counter :- It Returns the Frequency(Number of times it Occured) of a word in given file.
Input : File Pointer, Constant Char Array
Output: Int 
*/
int Frequency_Counter(FILE *ptr, const char *word)
{   
    const int BUFFER = 500;
    char str[BUFFER];
    char *pos;
    int i, c;
    c = 0;

    // Reading each line from file untill end of file.
    while ((fgets(str, BUFFER, ptr)) != NULL)
    {
        i = 0;

        // Finding the next occurrence of given "word" in our Array "str"
        while ((pos = strstr(str + i, word)) != NULL)
        {
            i = (pos - str) + 1;

            c++;
        }
    }

    return c;
}

int main()
{
    FILE *ptr;

    char word[] = "IIT";

    ptr = fopen("file.txt", "r");

    if (ptr == NULL)
    {
        printf("Unable to open the given file.\n");
        return -1;
    }

    int counter = Frequency_Counter(ptr, word);

    printf("\nThe Word '%s' is found %d times in the given file.", word, counter);

    fclose(ptr);

    return 0;
}

