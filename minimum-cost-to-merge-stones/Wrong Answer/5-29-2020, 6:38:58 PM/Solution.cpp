// https://leetcode.com/problems/minimum-cost-to-merge-stones

class Solution {
    const int inf = 1e9;
public:
    int n,K;
    vector<int> S;
    vector<int> psum;
    
    int solve(int i,int j,int p){
        // cout << i << " " << j << " " << p <<endl;
        if(i == j) {
            return (p == 1 ? 0 : inf);
        }
        int ans = 1e9;
        if(p == 1){
            // cout << "p == 1 " << i << " " << j << " " << p <<endl;
            ans = solve(i,j,K) + psum[j+1] - psum[i];
        }else{
            
            for(int k = i;k<j;k++){
                ans = min(ans,solve(i,k,p-1) + solve(k+1,j,1));
            }
        }
        return ans;
            // dp[i][i][1] = 0;
            // dp[i][j][1] = min over t( dp[i][j][K] + sum[i,j]);
            // dp[i][j][k] = minover  t(dp[i][t][k-1] + dp[t+1][j][1]);
        
    }
    int mergeStones(vector<int>& stones, int k) {
        S = stones;
        n  =stones.size();
        K = k;
        psum.assign(n+1,0);
        for(int i = 1;i<=n;i++){
            psum[i] = psum[i-1] + stones[i-1];
        }
        return solve(0,n-1,1);
    }
};