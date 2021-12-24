// https://leetcode.com/problems/closest-dessert-cost

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        
        int ans = 0;
        int bestdiff = INT_MAX;
        int m = toppingCosts.size();
        
        
        auto upd = [&](int value){
            int diff = abs(value - target);
            if(diff < bestdiff){
                bestdiff = diff;
                ans = value;
            }
        };
        const int M = 2e5;
        
        
        bitset<M> bm;
        for(int base : baseCosts){
            bitset<M> b;
            b[base] = 1;
            for(int top : toppingCosts){
                b = b | (b<<1) | (b<<2);
            }
            bm|= b; 
        }
        for(int i = 0;i<M;i++){
            if(bm[i]) upd(i);
        }
        return ans;
    }
};