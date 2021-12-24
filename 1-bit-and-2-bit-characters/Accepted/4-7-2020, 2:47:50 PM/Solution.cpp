// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        dp[0][0] = dp[0][1] = dp[0][2] =  1;
        for(int i = 1;i<=n;i++){
            if(bits[i-1] == 0){
                dp[i][0] |= dp[i-1][1] | dp[i-1][0] | dp[i-1][2];
            }
            if(i >=2){
                if(bits[i-1] == 0 && bits[i-2] == 1){
                    dp[i][1] |= dp[i-2][1] | dp[i-2][0] | dp[i-2][2];
                }
                if(bits[i-1] == 1 && bits[i-2] == 1){
                    dp[i][2] |= dp[i-2][1] | dp[i-2][0] | dp[i-2][2];
                }
            }
        }
        return (dp[n][0]) ;
    }
};