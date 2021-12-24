// https://leetcode.com/problems/maximize-palindrome-length-from-subsequences

class Solution {
public:
    int longestPalindrome(string w1, string w2) {
        
        string W = w1+w2;
        int n = W.size();
        
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int l=0;l<n;l++){
            for(int i = 0;i+l<n;i++){
                int j = i+l;
                if(i == j){
                    dp[i][j] = 1;
                }else if(j-i ==1){
                    dp[i][j] = (W[i] == W[j])?2:1;
                }else{
                    if(W[i] == W[j]){
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }else{
                        dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                    }
                    
                }
            }
        }
        int ans = 0;
        int n1 = w1.size();
        int n2 = w2.size();

        for(int i= 0;i<n1;i++){
            for(int j = n1;j<n;j++){
                if(W[i] == W[j]){
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};