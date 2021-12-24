// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {  
        if(e.size() == 0) return 0;
        auto cmp = [](vector<int> &a,vector<int> &b){
            return ((long)a[1]*a[0] <= (long)b[0]*b[1]); 
        };
        int n = e.size();
        
        sort(e.begin(),e.end(),cmp);
        vector<int> dp(n,1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(e[i][0] > e[j][0] && e[i][1] > e[j][1]){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};