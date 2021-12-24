// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string b="()";
        vector<string> s;
        set<string> ans;
        s.push_back(b);
        for(int i=2;i<=n;i++){
            ans.clear();
            for(int j=0;j<s.size();j++){
                string a,b,c;
                a='('+s[j]+')';
                ans.insert(a);
                b=s[j]+string("()");
                ans.insert(b);
                c=string("()")+s[j];
                ans.insert(c);
            }
            s.clear();
            for (auto it=ans.begin(); it != ans.end(); ++it) 
                s.push_back(*it);
        }
        return s;
    }
};