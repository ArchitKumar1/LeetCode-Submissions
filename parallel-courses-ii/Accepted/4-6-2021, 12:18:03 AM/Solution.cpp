// https://leetcode.com/problems/parallel-courses-ii

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> preq(n,0);
        
        for(auto x : dependencies){
            int p = x[0] - 1;
            int c = x[1] - 1;
            
            preq[c] |= (1 << p);
        }
        
        vector<int> dep(1 << n,0);
        
        for(int i = 0; i < 1 << n;i++){
            for(int j = 0;j<n;j++){
                if(i >>j&1){
                    dep[i] |= preq[j];
                }
            }
        }
        vector<int> dp(1 << n,1e9);
        
        dp[0] = 0;
        
        for(int i = 0; i < 1 << n;i++){
            int left = i ^ ((1 << n) - 1);
            for(int j = left ;j ;j = (j-1)&left){

                if(__builtin_popcount(j) > k) continue;
                if((dep[j] & i) == dep[j]){
                    dp[i | j] = min(dp[i | j] ,dp[i] + 1);
                }
            }
        }
        return dp.back();
    }
};