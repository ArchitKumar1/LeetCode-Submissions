// https://leetcode.com/problems/minimum-cost-to-cut-a-stick

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int N = cuts.size();
        
        int dp[102][102] = {0};
        for(int l =0 ;l<N;l++){
            for(int i = 0;i+l<N;i++){
                int j = i+l;
                if(j>i+1){
                    dp[i][j] = 1e9;
                    for(int k = i+1;k<j;k++){
                        dp[i][j] = min(dp[i][j], + dp[i][k] + dp[k][j]);
                    }
                    dp[i][j] += cuts[j] - cuts[i];
                }
                
            }
        }
        return dp[0][cuts.size()-1];
    }
};