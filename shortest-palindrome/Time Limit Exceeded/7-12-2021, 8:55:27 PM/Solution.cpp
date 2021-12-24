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
        string rev = s;
        reverse(rev.begin(),rev.end());
        for(int i = 0;i < s.size();i++){
            string t = rev.substr(0,s.size()-i) + s;
            if(is(t)) ans = t;
        }
        if(is(s)) ans = s;
        return ans;
    }
};