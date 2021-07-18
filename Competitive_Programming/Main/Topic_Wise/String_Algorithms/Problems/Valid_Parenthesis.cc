// https://leetcode.com/problems/valid-parenthesis-string/solution/

class Solution {
public:
    bool checkValidString(string s) {
        int lower = 0, upper = 0;
        for (char c : s){
            
            lower += ( ( c == '(' ) ? 1  : -1 );
            upper += ( ( c != ')' ) ? 1  : -1 );
            
            if (upper < 0){ break; }
            lower = max(0, lower);
        }
        return (lower == 0);
        
    }
};