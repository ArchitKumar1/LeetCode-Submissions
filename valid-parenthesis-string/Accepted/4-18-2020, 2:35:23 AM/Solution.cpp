// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    string S;
    
    
    bool checkValidString(string s) {
        int l =0 ,u =0 ;
        for(char c : s){
            if(c == '(')l++,u++;  
            if(c == ')') l--,u--;
            if(c == '*') u++,l--;
            if(l < 0) l =0;
            if(u < 0) return 0;
        }
        return l == 0;
    
    }
};