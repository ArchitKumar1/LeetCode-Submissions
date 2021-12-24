// https://leetcode.com/problems/shortest-palindrome

class Solution {
public:
    string shortestPalindrome(string s) {
        auto is = [&](string s){
            string t = s;
            reverse(t.begin(),t.end());
            return t == s;
        };
        
        
        string ans;
        for(int i = 0;i < s.size();i++){
            string t = s.substr(i) + s;
            if(is(t)) ans = t;
        }
        return ans;
    }
};