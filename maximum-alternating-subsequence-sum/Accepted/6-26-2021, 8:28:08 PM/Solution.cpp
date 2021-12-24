// https://leetcode.com/problems/maximum-alternating-subsequence-sum

class Solution {
public:
    vector<int> nums;
    vector<vector<long long>> dp;
    long long n;
    long long solve(int i, int t){
        if(i == nums.size()) return 0;
        if(dp[i][t] != -1) return dp[i][t];
        long long ans;
        if(t == 0){
            ans = max(solve(i+1,t),nums[i]*1LL + solve(i+1,t^1));
        }else{
            ans = max(solve(i+1,t),-nums[i]*1LL + solve(i+1,t^1));
        }
        return dp[i][t] = ans;
    }
    long long maxAlternatingSum(vector<int>& NUMS) {
        nums = NUMS;
        n = nums.size();
        dp = vector<vector<long long>> (n,vector<long long>(2,-1));
        return solve(0,0);
    }
};