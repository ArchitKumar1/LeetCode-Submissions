// https://leetcode.com/problems/out-of-boundary-paths

class Solution {
public:
    int mod = 1000*1000*1000 + 7;
    int solve(vector<vector<vector<int>>> &dp,int m,int n,int N ,int i,int j){
        if(i<0 || i>m-1 || j<0 || j>n-1){
            return 1;
        }
        else if(N == 0) return 0;
        if(dp[i][j][N]!=-1){
            return dp[i][j][N];
        }
        int dx[4]= {0,-1,0,1};
        int dy[4]= {1,0,-1,0};
        int total=0;
        for(int k =0 ;k<4;k++){
            total = (total+ solve(dp,m,n,N-1,i+dx[k],j+dy[k]))%mod;
        }
        dp[i][j][N] = total;
        return dp[i][j][N];
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(N+1,-1)));
        return solve(dp,m,n,N,i,j);
    }
};