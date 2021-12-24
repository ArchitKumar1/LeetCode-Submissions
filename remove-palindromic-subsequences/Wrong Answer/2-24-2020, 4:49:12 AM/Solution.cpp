// https://leetcode.com/problems/remove-palindromic-subsequences

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s == "0") return 1;
        string t = s;
        reverse(t.begin(),t.end());
        return (s == t ? 1 : 2);
    }
};