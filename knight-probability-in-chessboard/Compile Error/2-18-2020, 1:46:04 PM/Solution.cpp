// https://leetcode.com/problems/knight-probability-in-chessboard

class Solution {
public:

    //vector<vector<vector<int>>> dp;
    vector<int> dx = {1,2,2,1,-1,-2,-2,-1};
    vector<int> dy = {2,1,-1,-2,-2,-1,1,2};

    int n;
    int k;
    bool inside(int i,int j){
        return i>=0 && j>=0 && i<n && j<n;
    }
    
    double solve( int i,int j,int move,vector<vector<vector<double>>> &dp){
        if(inside(i,j) == 0){
            return 0;
        if(move == k){
            return 1;
        }
        if(dp[i][j][move] != -1){
            return dp[i][j][move];
        }
        double ans = 0;
        
        for(int m = 0;m<8;m++){
            ans += solve(i + dx[m],j + dy[m],move+1,dp)/8;
        }

        return dp[i][j][move] = ans;        
    }
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N+1,vector<vector<double>> (N+1,vector<double>(K+1,-1)));
        n= N;
        k= K;
 
        return solve(r,c,0,dp);
    }
};