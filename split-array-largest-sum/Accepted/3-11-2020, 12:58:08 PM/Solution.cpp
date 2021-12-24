// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long long maxi[n+1] = {0};
        
        for(int i = 1;i<=n;i++){
            maxi[i] = maxi[i-1] + nums[i-1];
        }
        auto get = [&](int i,int j){
            return maxi[j+1] - maxi[i];
        };
        long long K = 51;
        long long dp[K][n];
        for(int i = 0;i<n;i++){
            dp[0][i] = get(0,i);
        }
        for(int k = 1;k<K;k++){
            for(int i = 0;i<n;i++){
                dp[k][i] = dp[k-1][i];
                for(int j = 0;j<i;j++){
                    dp[k][i] = min(dp[k][i], max(dp[k-1][j],get(j+1,i)));
                }
            }
        }
        return dp[m-1][n-1];
        
    }
    
};