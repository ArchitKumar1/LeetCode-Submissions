// https://leetcode.com/problems/longest-common-subsequence

class Solution {
private:
    int dp[1001][1001];
public:
    int n , m;
    string s,t;
    
    int solve(int i,int j){
        if(i < 0  || j < 0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = 1 + solve(i-1,j-1);
        }else{
            return dp[i][j] = max(solve(i-1,j),solve(i,j-1)); 
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        s = text1;
        t = text2;
        n = text1.size();
        m = text2.size();
        
        return solve(n-1,m-1);
    }
};