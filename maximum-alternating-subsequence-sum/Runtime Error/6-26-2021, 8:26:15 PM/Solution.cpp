// https://leetcode.com/problems/maximum-alternating-subsequence-sum

class Solution {
public:
    vector<int> nums;
    vector<vector<int>> dp;
    int n;
    int solve(int i, int t){
        if(i == nums.size()) return 0;
        if(dp[i][t] != -1) return dp[i][t];
        int ans;
        if(t == 0){
            ans = max(solve(i+1,t),nums[i] + solve(i+1,t^1));
        }else{
            ans = max(solve(i+1,t),-nums[i] + solve(i+1,t^1));
        }
        return dp[i][t] = ans;
    }
    long long maxAlternatingSum(vector<int>& NUMS) {
        nums = NUMS;
        n = nums.size();
        dp= vector<vector<int>> (n,vector<int>(2,-1));
        return solve(0,0);
    }
};