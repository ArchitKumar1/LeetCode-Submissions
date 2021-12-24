// https://leetcode.com/problems/count-all-possible-routes

class Solution {
public:
    
    vector<int> L;
    int S,E,F,N;
    const int mod = 1e9+7;
    
    
    int solve(int i,int f){
        int ans = 0;
        if(i == E) return 1;
        for(int x = 0;x<N;x++){
            if(i == x) continue;
            int cost = abs(L[x] - L[i]);
            if(cost <= f){
                ans += solve(x,f-cost );
                ans %= mod;
            }
        }

        return ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        L = locations,S = start,E = finish,F = fuel,N= L.size();
        return solve(S,F);
    }
};