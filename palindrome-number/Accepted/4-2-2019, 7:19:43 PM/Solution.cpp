// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        string a = to_string(x);
        
        for(int i=0;i<a.length();i++){
            if(a[i]!= a[a.length() - 1 - i])
                return false;
        }
        return true;
    }
};