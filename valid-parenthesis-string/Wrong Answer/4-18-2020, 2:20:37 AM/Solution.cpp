// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    string S;
    
    
    bool checkValidString(string s) {
        int buffer = 0;
        int bal = 0;
        for(char c : s){
            cout << bal << " " << buffer << endl;
            if(c == '('){
                bal += 1;
            }
            if(c == ')'){
                if(bal ==0 ){
                    if(buffer>=1){
                        buffer--;
                    }else{
                        return 0;
                    }
                }else{
                    bal--;
                }
            }
            if(c == '*') buffer++;
        }
        if(bal > 0){
            if(buffer >=bal){
                return 1;
            }else return 0;
        }else{
            return 1;
        }
    
    }
};