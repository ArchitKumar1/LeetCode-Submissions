// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    
    string solve(string x){
        string ans = "";
        for(char c : x){
            if(c != '#'){
                ans += c;
            }else{
                if(ans != ""){
                    ans.erase(ans.begin() + ans.size()-1);
                }
            }
        }
        return ans;
    }
    bool backspaceCompare(string S, string T) {
        string a = solve(S);
        string b = solve(T);
        cout << a << ":" << b << ":" <<endl;
        return a == b;
        
    }
};