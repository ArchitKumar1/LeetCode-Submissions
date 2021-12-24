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
        int dp[n][n];
        
        
        for(int  l =0;l<n;l++){
            for(int i = 0;i+l<n;i++){
                int j = i+l;
                if(i == j) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = INT_MAX;
                for(int k = i;k<j;k++){
                    dp[i][j] = min(dp[i][j],(pali[i][j] ? 0 : 1 + dp[i][k] + dp[k+1][j]));
                }
            }
        }
        // cout << pali[0][1] << " " << pali[2][2] << endl;
        return dp[0][n-1];
        
    }
};