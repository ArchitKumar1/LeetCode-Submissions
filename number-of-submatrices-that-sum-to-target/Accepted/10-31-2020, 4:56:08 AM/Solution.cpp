// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        
        auto sum = [&](int x1,int y1,int x2,int y2){
            return dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        };
        
        int fans = 0;
        for(int i =1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                 for(int i2 =i;i2<=n;i2++){
                    for(int j2 = j;j2<=m;j2++){
                        if(sum(i,j,i2,j2) == target){
                            fans += 1;
                        }
                    }
                }   
            }
        }
        return fans;
        
    }
};