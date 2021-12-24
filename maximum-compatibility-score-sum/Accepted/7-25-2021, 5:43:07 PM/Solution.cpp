// https://leetcode.com/problems/maximum-compatibility-score-sum

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = mentors.size();
        int n = mentors[0].size();
        
        vector<vector<int>> match(m,vector<int>(m,0));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < m;j++){
                for(int k = 0;k < n;k++){
                    match[i][j] += students[i][k] == mentors[j][k];
                }
            }
        }
        
        vector<int> dp(1 << m);
        for(int i = 0;i < m;i++){
        
            vector<int> ndp = dp;
            for(int j = 0;j < 1 << m;j++){
                for(int k = 0;k < m;k++){
                    if((j >> k & 1) == 0){
                        ndp[j | (1 << k)] = max(ndp[j | (1 << k)],dp[j] + match[i][k]);
                    }
                }
            }
            swap(dp,ndp);
        }
        return dp[-1 + (1 << m)];
    }
};