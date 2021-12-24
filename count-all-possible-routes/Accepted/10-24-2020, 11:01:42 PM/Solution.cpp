// https://leetcode.com/problems/count-all-possible-routes

class Solution {
private:
    const static int M = 105;
public:
    
    vector<int> L;
    int S,E,F,N;
    const int mod = 1e9+7;
    int dp[M][2*M];
    int fans = 0;
    
    int solve(int pos,int f){
        if(dp[pos][f]!=-1){
            return dp[pos][f];
        }
        int ans = 0;
        if(pos == E) ans += 1;
        for(int x = 0;x<N;x++){
            if(pos == x) continue;
            int cost = abs(L[x] - L[pos]);
            if(cost <= f){
                ans += solve(x,f-cost );
                ans %= mod;
            }
        }
        return dp[pos][f] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        L = locations,S = start,E = finish,F = fuel,N= L.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(S,F);
        return ans;
    }
};