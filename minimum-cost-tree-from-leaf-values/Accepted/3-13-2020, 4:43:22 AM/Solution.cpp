// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values

class Solution {
public:
    
    
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        auto g= [&](int i,int j){
            int res = INT_MIN;
            for(int k = i;k<=j;k++){
                res = max(res,arr[k]);
            }
            return res;
        };
        for(int l = 0;l<n;l++){
            for(int i = 0;i+l<n;i++){
                int j = i+l;
                if(i == j){
                    dp[i][j] = arr[i];
                }else{
                    for(int k = i;k<j;k++){
                        dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + g(i,k)*g(k+1,j));
                    }
                }
            }
        }
        int sum = 0;
        for(int i = 0;i<n;i++)sum += arr[i];
        return dp[0][n-1] - sum;
        
    }
};