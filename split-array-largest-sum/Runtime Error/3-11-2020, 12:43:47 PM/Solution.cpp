// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int maxi[n][n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                maxi[i][j] = 0;
            }
        }
        for(int l = 0;l<n;l++){
            for(int i =0 ;i+l<n;i++){
                int j = i + l;
                if(i == j){
                    maxi[i][j] = nums[i];
                }else{
                    maxi[i][j] =  nums[i] + nums[j] + maxi[i+1][j-1];
                }
            }
        }
        int K = 55;
        int dp[K][n];
        for(int i = 0;i<n;i++){
            dp[0][i] = maxi[0][i];
        }
        for(int k = 1;k<K;k++){
            for(int i = 0;i<n;i++){
                dp[k][i] = dp[k-1][i];
                for(int j = 0;j<i-1;j++){
                    dp[k][i] = min(dp[k][i], max(dp[k-1][j],maxi[j+1][i]));
                }
            }
        }
        return dp[m-1][n-1];
        
    }
    
};