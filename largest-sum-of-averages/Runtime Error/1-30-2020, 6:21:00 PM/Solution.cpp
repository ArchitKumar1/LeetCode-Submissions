// https://leetcode.com/problems/largest-sum-of-averages

class Solution {
public:
    double largestSumOfAverages(vector<int>& arr, int K) {
        int n = arr.size();
        vector<vector<double>> dpsum(n+1,vector<double>(n+1,0.0));
        vector<vector<double>> dpavg(n+1,vector<double>(n+1,0.0));
        
        
        for(int l = 0;l<n;l++){
            for(int i =0;i<n;i++){
                int j = i+l;
                if(i == j)dpsum[i][i] = arr[i];
                else{
                    dpsum[i][j] = dpsum[i+1][j-1] + arr[i] + arr[j];
                }
            }
        }
        for(int l = 0;l<n;l++){
            for(int i =0;i<n;i++){
                int j = i+l;
                if(i == j)dpavg[i][i] = arr[i];
                else{
                    dpavg[i][j] = dpsum[i][j]/(1.0 *(j-i+1));
                }
            }
        }
//         double dp[K+1][n+1];
//         memset(dp,0,sizeof(dp));
        
//         for(int i = 0;i<n;i++){
//             dp[1][i] = (dpsum[0][i])/(1.0*i+1);
//         }
//         for(int k=2;k<=K;k++){
//             for(int i = 0;i<n;i++){
//                 dp[k][i] = dpsum[k][i]/(i+1);
                
//                 for(int  j =0;j<=i;j++){
//                     dp[k][i] = max(dp[k][i],dp[k-1][j]/(j+1) + dpsum[j+1][i]/(i-(j-1) + 1));
//                 }
//             }
//         }
        return 1;
        //return dp[K][n-1];
        
    }
};