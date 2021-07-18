#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/basic-calculator-ii/

Basic Calculator
You are given a string S. It contains only non-negative integers, +, -, *, / operators.
Implement a basic calculator to evaluate a simple expression string.

Note: The integer division should truncate toward zero.
Note: Expressions are evaluated based on DMAS rule. 
It just means that (/,*) have more priority when compared to (+,-).
(+,-) have same & (/, *) have same.
*/


// Intuition: We keep on pushing elements with sign when +, - operators are encountered.
// When we encounter /, * we pop elements from stack & perform operation & push the result.

int main(){
    string s; cin >> s;
    long long res = 0, tmp = 0; char sign = '+'; // Since all are non neg, 1st digit is +
    stack<int> myStack;
    for (int i = 0; i<s.size(); i++){
        if (isdigit(s[i])) tmp = tmp*10 + s[i]-'0';
        if (( !isdigit(s[i]) and !isspace(s[i]) ) or i == s.size()-1){
            if (sign == '+') myStack.push(tmp);
            else if (sign == '-') myStack.push(-tmp);
            else if (sign == '*'){
                int topp = myStack.top(); myStack.pop();
                int respush = topp*tmp; myStack.push(respush);
            }
            else if ( sign == '/'){
                int topp = myStack.top(); myStack.pop();
                int respush = topp/tmp; myStack.push(respush);
            }
            sign = s[i];
            tmp = 0;
        }
    }
    while(!myStack.empty()){
        res += myStack.top(); myStack.pop();
    }
    cout << res;
	return 0;
}