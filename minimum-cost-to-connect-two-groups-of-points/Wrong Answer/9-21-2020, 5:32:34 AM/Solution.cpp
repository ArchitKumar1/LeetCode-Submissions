// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points

class Solution {
public:
    vector<vector<int>>C;
    vector<vector<int>>dp;
    int N,M;
    
    int solve(int i,int  mask){
        if(i == N){
            if(mask +1 == (1<<M)){
                return 0;
            }
            else{
                return 1e9;
            }
        }
        if(dp[i][mask]!=-1) return dp[i][mask];
        int &ans = dp[i][mask] = 1e9;
        for(int j = 0;j<M;j++){
            if((mask&(1<<j)) == 0){
                ans = min(ans,C[i][j] + solve(i+1,mask|(1<<j)));
            }
        }
        return ans; 
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        N = cost.size(),M = cost[0].size();
        C = cost;
        dp=vector<vector<int>>(N,vector<int>((1<<M),-1));
        
        return solve(0,0);
    }
};