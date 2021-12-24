// https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        
        map<int,int> m1[k];
        vector<int> sz(k,0);
        set<int> se[k];
        
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int c = nums[i];
            int idx = i%k;
            m1[idx][c]++;
            sz[idx]++;
            se[idx].insert(c);
        }
    
        int dp[2001][1024];
        memset(dp,-1,sizeof(dp));
        function<int(int,int)> solve = [&](int idx,int curr){
        
            if(dp[idx][curr]!=-1) return dp[idx][curr];
            if(idx == k-1){
                int cost = sz[idx] - m1[idx][curr];
                return dp[idx][curr]=cost;
            }
            int ans = INT_MAX;
            for(auto x : se[idx]){
                int cost = sz[idx] - m1[idx][x];
                ans = min(ans, cost + solve(idx+1,curr^x));
            }
            return dp[idx][curr]=ans;
        };
        return solve(0,0);
    }
};