#include <stdio.h>
#include "4.3_Stacks.h"  // Need to make the Header 


int numberofsymb = 3;
char opensymb[] = "([{"  ;
char closesymb[] = ")]}" ;


bool isOpenBracket(char ch){
    for (int i =0; i<numberofsymb; i++){
        if (opensymb[i] == ch) return 1 ;
    }
    return false;
}

int isCloseBracket(char ch){
    for (int i =0; i<numberofsymb; i++){
        if (closesymb[i] == ch) return i+1 ;
    }
    return 0;
}


bool ParenthesesMatch(char ar[], int len)
{

    class Stack stk;
    for(int i=0; i<len; i++){

        if (isOpenBracket(ar[i])) stk.push(ar[i]);

        int y = isCloseBracket(ar[i]);

        if (y>0){

            if (stk.isEmpty()) return false ;
            if ( stk.top() == opensymb[y-1]) stk.pop();
                else return false; 
        }

    }
    if (stk.isEmpty()) return true;
    return false;

}