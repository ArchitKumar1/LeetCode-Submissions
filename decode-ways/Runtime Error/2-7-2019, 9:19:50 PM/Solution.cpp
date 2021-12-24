// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        long long  N=s.length();
        long long dp[N+1];
        dp[1]=1LL;
        for(long long i=2LL;i<=N;i++)
            dp[i]=i*dp[i-1];
        return dp[N];
    }
};