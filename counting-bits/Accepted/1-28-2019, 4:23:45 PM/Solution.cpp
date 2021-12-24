// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        dp[0] =0;
        dp[1] =1;
        dp[2] =1;
        
        for(int i=3;i<=num;i++){
            if(i&1) dp[i] =dp[i/2]+1;
            else dp[i] = dp[i/2];
       } 
        return dp;
            
    }
};