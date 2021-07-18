/*
https://leetcode.com/problems/basic-calculator/

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Constraints:
1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation.
'-' could be used as a unary operation but it has to be followed by parentheses.
Every number and running calculation will fit in a signed 32-bit integer.
*/

class Solution {
public:
    int calculate(string s) {
        
        long long result=0; 

        int num=0, sign=1; 
        stack<int> nums, ops; 
        
        for(int i=0; i<s.size(); ++i){
            
            char c=s[i];
            
            if(isdigit(c)){
                num = 10*num + (c-'0'); 
            }
            
            else if(c=='+'){
                result += num*sign; // Everytime we encounter an operator(+ or -), sum up previous number
                num=0;              // Reset number value to zero, since previous number ended.
                sign=1;             // sign is the sign of next number
            }
            
            else if(c=='-'){
                result += num*sign;
                num=0; 
                sign=-1; 
            }
            
            else if(c=='('){
                
                // Push back the result till now into stack.
                // ...(1+3+(..xx..)+...)... before go into cur (..xx..), record the forefront result (in this case it is 1+3 ) into nums array    
                nums.push(result);  
                
                // Push back the sign of the current bracket expression.
                // record cur (..xx..) sign
                ops.push(sign);    
                
                // Reset the result & sign variable so that we can store the answer for the current bracket level.
                // result is to record the total value in the cur (..xx..)
                result=0;            
                sign=1;
            }
            
            else if(c==')' && ops.size()){ 
                // && ops.size() is just to make sure that the expression is valid. i.e, When we encountered a CLOSE bracket, there must
                // be open bracket too. Since in this question, It is given that it is already valid, This may be ignored. 
                
                // This is req. to deal with the cases where only 1 element is in parenthesis.
                // For case: 1-(5)
                result += num*sign;   
                num=0;
                
                // Adding the current bracket seq. result to the overall answer.
                // ...(1+3+(..xx..)+...)... sum up cur (..xx..)  and the forefront result (in this case it is 1+3 )
                result = result*ops.top() + nums.top();  
                nums.pop();
                ops.pop();
            }
        }
        
        // This is required for the cases like:  1+2+3 
        result+=num*sign;          
        return result; 
    }
};