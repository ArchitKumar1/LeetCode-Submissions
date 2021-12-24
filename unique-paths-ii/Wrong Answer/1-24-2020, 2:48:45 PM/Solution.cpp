// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        if(n == 1 && m == 1){
            if(g[0][0] == 1){
                return 0;
            }else{
                return 1;
                }
        }
        vector<vector<int>> dp(n,vector<int> (m,0));
        dp[0][0] = 1;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(i == 0 && j == 0)continue;
                if(g[i][j] == 1) continue;
                dp[i][j] = (i-1>=0 ? dp[i-1][j] : 0) + (j-1>=0 ? dp[i][j-1] : 0); 
            }
        }
    
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){  
                cout << dp[i][j] << " ";
            
            }
            cout << endl;
        }
        return dp[n-1][m-1];
    }
};