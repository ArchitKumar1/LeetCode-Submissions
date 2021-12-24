// https://leetcode.com/problems/best-team-with-no-conflicts

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<array<int,2>> v(n);
        for(int i = 0;i<n;i++){
            v[i][0] = ages[i],v[i][1] = scores[i];
        }
        sort(v.begin(),v.end());
        vector<int>dp(n+1,0);
        
        for(int i = 1;i<=n;i++){
            dp[i] = v[i-1][1];
            for(int j = 1;j<i;j++){
                if(v[j-1][1] <= v[i-1][1]){
                    dp[i] = max(dp[i],dp[j] + v[i-1][1]);
                }
            }
        }

        return *max_element(dp.begin(),dp.end());
        
        
    }
};