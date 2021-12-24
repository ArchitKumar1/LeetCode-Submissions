// https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        
        int n = nums.size();
        int m = groups.size();
        map<vector<int>,int> m1;
        
        int dp[m+1][n+1];
        
        memset(dp,-1,sizeof(dp));
        function<bool(int,int)> dfs = [&](int g,int i) -> bool{
            if(g == m)return 1;
            if(i == n) return 0;
            
            if(dp[g][i]!= -1)return dp[g][i];
            vector<int> curr;
            bool ans = 0;
            ans|= dfs(g,i+1);
            for(int j = i;j<n;j++){
                curr.push_back(nums[j]);
                if(curr == groups[g]){
                    ans |= dfs(g+1,j+1);
                }
            }
            return dp[g][i] = ans; 
        };
        return dfs(0,0);
        
    }
};