// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        int ans = 0;
        int n =s.size();
        
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int le = 0;
        int index = 0;
        
        for(int l = 0;l<n;l++){
            for(int i = 0;i+l<n;i++){
                int j = i+l;
                if(j-i == 0){
                    dp[i][j] = 1;
                }else if(j-i == 1){
                    dp[i][j] = 2*(s[i] == s[j]);
                }else{
                    if(s[i] == s[j] && dp[i+1][j-1] > 0){
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }else{
                        dp[i][j] = 0;
                    }
                }
                if(dp[i][j] > 0){
                    if(j-i+1 > le){
                        le = j-i+1;
                        index = i;
                    }  
                }
                
            }
        }
        return s.substr(index,le);
    }
};