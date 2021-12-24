// https://leetcode.com/problems/closest-dessert-cost

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        
        int ans = 0;
        int bestdiff = INT_MAX;
        int m = toppingCosts.size();
        
        int MX = 3e5;
        
        auto upd = [&](int value){
            int diff = abs(value - ans);
            if(diff < bestdiff){
                bestdiff = diff;
                ans = value;
            }
        };
        for(int x : baseCosts){
            
            vector<int> nums(MX);
            set<int> present;
            nums[0] = 1;
            for(int i = 0;i<m;i++){
                for(int j = 0;j<=2;j++){
                    for(int k = 0;k+toppingCosts[i]*j < MX;k++){
                        if(nums[k] == 1){
                            nums[k+toppingCosts[i]*j] = 1;
                            present.insert(k+toppingCosts[i]*j);
                        }
                
                    }
                }
            }
            auto lb = present.lower_bound(target);
            auto ub = present.upper_bound(target);
            
            if(lb!=present.begin()){
                auto lb2 = prev(lb);
                cout << *lb2 << endl;
                upd(*lb2);
            }
            
            if(ub!=present.end()){
                
                cout << *ub << endl;
                cout << *lb << endl;
                upd(*lb);
                upd(*ub);
            }
            
        }
        return ans;
    }
};