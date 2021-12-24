// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {

        int n = nums.size();
        int m = mul.size();
        int M = 1.1e3;
        int dp[M][M];
        memset(dp,-1,sizeof(dp));
        
        function<int(int,int)> solve = [&](int i,int j){
            int turn = i + n-1 -j;
            if(i > j) return 0;
            if(turn == m){
                return 0;
            }
            if(dp[i][n-1-j] != -1){
                return dp[i][n-1-j];
            }
            int ans = max(mul[turn]*nums[i]+ solve(i+1,j),mul[turn]*nums[j]+ solve(i,j-1));
            return dp[i][n-1-j] = ans;
            
        };
        
        
        return solve(0,n-1);
    }
};