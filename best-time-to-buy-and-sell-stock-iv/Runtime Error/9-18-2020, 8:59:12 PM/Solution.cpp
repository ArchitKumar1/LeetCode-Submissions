// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int N,K;
    vector<int> P;
    vector<vector<int>> dp;
    vector<pair<int,int>> ind;
    int solve(int i,int k){
        
        if(i<0 || k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int &ans = dp[i][k] = 0;
        
        int id = ind[i].second;
        int mi = ind[i].first;
        if(id == -1) return 0;
        mi = min(mi,P[i]);
        if(mi <= P[i]){
            ans = max(ans, P[i] - mi + solve(id-1,k-1));
        }
        ans = max(ans,solve(i-1,k));
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        N= prices.size(),K = min(N/2,k);
        
        dp = vector<vector<int>>(N+1,vector<int>(K+1,-1));
        ind.resize(N);
        
        ind[0].first = -1;
        ind[0].second = -1;
        
        P = prices;
        int mi = P[0];
        int id = 0;
        
        for(int i = 1;i<N;i++){
            ind[i].first = mi;
            ind[i].second = id;
            if(P[i]<=mi){  
                mi = P[i];
                id = i;
            }
           // cout << ind[i].first << " " << ind[i].second << endl;
        }
        
        
        int ans = solve(N-1,K);
        return ans==INT_MIN?0:ans;
    }
};