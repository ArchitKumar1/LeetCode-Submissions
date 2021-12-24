// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    int n;
    vector<vector<int>> C,dp,dp2;
    
    int solve(int a,int b){
        if(dp[a][b] != -1) return dp[a][b];
        if(a == n && b == n){
            return 0;
        }
        if(a == n){
            return dp[a][b] = C[a+b][1] + solve(a,b+1);
        }
        if(b == n){
            return dp[a][b] = C[a+b][0] + solve(a+1,b);
        }
        return dp[a][b] = min(C[a+b][1] + solve(a,b+1), C[a+b][0] + solve(a+1,b));
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size() /2;
        C = costs;
        
        int N = 2*n;
        dp = vector<vector<int>>(n+1,vector<int>(n+1,-1));
        dp2 = vector<vector<int>>(N+1,vector<int>(N+1,0));
        
        for(int i = 1;i<=n;i++){
            
            dp2[i][0] = (costs[i-1][0]+dp2[i-1][0]);
        
        }
        for(int j = 1;j<=n;j++){
            dp2[0][j] = (costs[j-1][1]+dp2[0][j-1]);
        }
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dp2[i][j] = min(costs[i+j-1][0]+dp2[i-1][j],costs[i+j-1][1]+dp2[i][j-1]);
            }
        }
        return dp2[n][n];
        
    }
};