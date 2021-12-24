// https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid

class Solution {
public:
    int minCost(vector<int>& sp, vector<int>& hp, vector<int>& rc, vector<int>& cc) {
        int n = rc.size();
        int m = cc.size();
        int ans = 0;
        int x=sp[0],y=sp[1];
        int X=hp[0],Y=hp[1];
        
        int sx = abs(X-x);
        int sgx = (x<X)?1:-1;
        while(sx--){
            x += sgx;
            ans += rc[x];
        }
        
        int sy = abs(Y-y);
        int sgy = (y<Y)?1:-1;
        while(sy--){
            y += sgy;
            ans += cc[y];
        }
        return ans;
    }
};