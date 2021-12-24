// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        
        map<int,string> m1;
        m1[2] = "abc";
        m1[3] = "def";
        m1[4] = "ghi";
        m1[5] = "jkl";
        m1[6] = "mno";
        m1[7] = "pqrs";
        m1[8] = "tuv";
        m1[9] = "wxyz";
        
        vector<string> v;
        
        function<void(int,string)> dfs = [&](int i,string s){
            // cout << s << endl;
            if(i == digits.size()){
                v.push_back(s);
            }
            // cout << digits[i]-'0' << " "  << i << endl;
            for(char c : m1[digits[i]-'0']){
                // cout << c <<  " " << i << endl;
                s.push_back(c);
                dfs(i+1,s);
                s.pop_back();
            }    
        };
        dfs(0,"");
        return v;
    }
};