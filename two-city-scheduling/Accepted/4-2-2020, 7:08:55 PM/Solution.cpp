// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    int n;
    vector<vector<int>> C,dp;
    
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
        dp = vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return solve(0,0);
        
    }
};