// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        int ans = INT_MIN;
        for(int l = 0;l<n;l++){
            for(int  i = 0;i+l<n;i++){
                int j = i+l;
                if(i == j){
                    dp[i][j] = arr[i];
                }else if(j-i ==1){
                    dp[i][j] = arr[i]*dp[i+1][j];
                }else{
                    dp[i][j] = arr[i]*dp[i+1][j-1]*arr[j];
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};