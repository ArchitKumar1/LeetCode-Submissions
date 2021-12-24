// https://leetcode.com/problems/count-all-possible-routes

class Solution {
public:
    
    vector<int> L;
    int S,E,F,N;
    const int mod = 1e9+7;
    
    int fans = 0;
    
    int solve(int pos,int f){
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
        cout << pos << " " << f << endl;
        cout << ans << endl;

        return ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        L = locations,S = start,E = finish,F = fuel,N= L.size();
        int ans = solve(S,F);
        return ans;
    }
};