// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int N=s.length();
        int dp[N+1];
        dp[1]=1;
        for(int i=2;i<=N;i++)
            dp[i]=i*dp[i-1];
        return dp[N];
    }
};