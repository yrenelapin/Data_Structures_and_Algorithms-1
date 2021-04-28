#include <stdio.h>
 
void decimal_to_hexa(int num)
{
    int i = 0, remainder;
    char hexadecimal[50];
  
    while(num != 0)
    {
        remainder = num % 16;  

        if (remainder < 10)
        {
            hexadecimal[i++] = 48 + remainder;
        }
        else
        {
            hexadecimal[i++] = 55 + remainder;
        }

        num /= 16;  
    }


    for(int j = i - 1; j >= 0 ; j--)  
    {
        printf("%c", hexadecimal[j]);
    }    
}
 
int main() {
    int num;
    scanf("%d",&num);
    decimal_to_hexa(num);
}

