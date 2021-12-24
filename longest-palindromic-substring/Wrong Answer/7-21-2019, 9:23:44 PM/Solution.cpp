// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        int n = s.length();
        
        int dp[n][n];
        
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        for(int i =0;i+1<n;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = 1;
            }
        }
        int index= 0;
        int val = INT_MIN;
        for(int k = 2;k<n;k++){
            for(int i =0;i+k<n;i++){
                if(s[i] == s[i+k] && dp[i+1][i+k-1] == 1){
                    dp[i][i+k] = 1;
                    if( k + 1 > val){
                        val = k+1;
                        index= i;
                    }
                }
            }
        }
        return s.substr(index,index + val);
    }
};