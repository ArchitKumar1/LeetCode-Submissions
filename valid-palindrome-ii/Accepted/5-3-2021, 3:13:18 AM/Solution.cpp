// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    
    
     bool ispali(string &s,int i,int j){
        for(; i<= j; i++,j--){
            if(s[i] != s[j]) return 0;
        }
        return 1;
    }
    bool pali(string &s,int i,int j){
        while(i <= j){
            if(s[i]!=s[j]){
                return ispali(s,i+1,j) | ispali(s,i,j-1);
            }
            i++,j--;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        return pali(s,0,n-1);
    }
};