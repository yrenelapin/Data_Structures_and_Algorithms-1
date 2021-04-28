#include <stdio.h>
#include <ctype.h>
 
 
int anagram_checker(char s1[], char s2[])
{

    int j,k;

    // Converting the Strings into Lower Case
    for(k = 0; k < 100; k++)
        s1[k] = tolower(s1[k]);
    
    for(j = 0; j < 100; j++)
        s2[j] = tolower(s2[j]);


    int num1[26] = {0}, num2[26] = {0}, i = 0;
 
    while (s1[i] != '\0')
        {
            num1[s1[i] - 'a']++;
            i++;
        }

    i = 0;
    while (s2[i] != '\0')
        {
            num2[s2[i] -'a']++;
            i++;
        }

    for (i = 0; i < 26; i++)
        {
            if (num1[i] != num2[i])
                return 0;
        }
    return 1;
}
 
int main() {
    char string1[100], string2[100];
 
    scanf("%s",string1);
    scanf("%s",string2);
 
    if (anagram_checker(string1, string2) == 1)
        printf("Given Strings are anagrams\n");
    else
        printf("Given Strings are not anagrams\n");
 
    return 0;
}

