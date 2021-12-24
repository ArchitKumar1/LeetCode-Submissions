// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        bool pali[n][n];
        memset(pali,0,sizeof(pali));
        
        for(int  l =0;l<n;l++){
            for(int i = 0;i+l<n;i++){
                int j = i+l;
                if(i == j && s[i] == s[j]) pali[i][j] = 1;
                else if(i+1 == j && s[i] == s[j]) pali[i][j] = 1;
                else if(s[i] == s[j] && pali[i+1][j-1]) pali[i][j] = 1;
            }
        }
        int dp[n];
        
        for(int i = 0;i<n;i++){
            dp[i] = INT_MAX;
            for(int j = 0;j<i;j++){
                if(pali[j+1][i]){
                    dp[i] = min(dp[i],1+dp[j]);
                }   
            }
            if(pali[0][i]) dp[i] = 0;
        }
        return dp[n-1];
    }
};