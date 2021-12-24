// https://leetcode.com/problems/maximum-length-of-repeated-subarray

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n  =A.size() ;
        int m = B.size();
        int ans = INT_MIN;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i =1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = 0;
                }
                if(dp[i][j] > ans){
                    ans = dp[i][j];
                }
            }
        }
        
        return ans;
    }
};