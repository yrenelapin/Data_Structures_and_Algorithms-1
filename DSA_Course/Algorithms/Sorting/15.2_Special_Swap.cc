#include <stdio.h>
int main(){

    int x = 20;
    int y = 30;

    x  = x^y;  // (^ stands for XOR)
    y  = x^y;
    x  = x^y;

    printf("%d %d", x , y);


}