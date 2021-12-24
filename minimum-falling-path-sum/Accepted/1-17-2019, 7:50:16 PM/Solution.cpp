// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        int n=A[0].size();
        int dp[n][n];
        int M=1e6;
        if(n==1) return A[0][0];
        memset(dp,0,sizeof(dp));
        int down,downleft,downright;
        for(int j=0;j<n;j++){
            dp[n-1][j]=A[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i == n-1) down=M;
                else down=dp[i+1][j];
                if((j == n-1) || (i == n -1)) downright=M;
                else downright=dp[i+1][j+1];
                if((j == 0) || (i == n-1))  downleft=M;
                else downleft=dp[i+1][j-1];
                dp[i][j]=A[i][j]+min(down,min(downright,downleft));
            }
        }
        int ans=1e7;
        for(int j = 0; j < n; j++){
            ans=min(dp[0][j],ans);
        }
        return ans;
    }
};