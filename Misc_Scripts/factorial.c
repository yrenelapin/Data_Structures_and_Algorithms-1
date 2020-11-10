#include <stdio.h>
int factorial(int num){
    if (num==0){ return 1; }                
    return(num*factorial(num-1));
}
int main(){
int testcases, num;
int result;
scanf("%d", &testcases);                        
while(testcases){
   scanf("%d", &num);
   result = factorial(num);
   printf("%d\n", result);
   testcases--; 
}
return 0 ;  
}
