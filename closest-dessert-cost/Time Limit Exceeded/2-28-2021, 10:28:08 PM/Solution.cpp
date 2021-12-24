// https://leetcode.com/problems/closest-dessert-cost

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        
        int ans = 0;
        int bestdiff = INT_MAX;
        int m = toppingCosts.size();
        
        int MX = 1e5;
        
        auto upd = [&](int value){
            int diff = abs(value - target);
            if(diff < bestdiff){
                bestdiff = diff;
                ans = value;
            }
        };
        
        
        for(int x : baseCosts){
            
            set<int> present;
            
            
            vector<int> nums(MX);
            nums[x] = 1;
            for(int i = 0;i<m;i++){
                vector<int> new_nums(MX);
                for(int j = 0;j<=2;j++){
                    for(int k = 0;k+toppingCosts[i]*j < MX;k++){
                        if(nums[k] == 1){
                            new_nums[k+toppingCosts[i]*j] = 1;
                            present.insert(k+toppingCosts[i]*j);
                            //cout << "I " << k+toppingCosts[i]*j << endl;
                        }
                    }
                }
                swap(new_nums,nums);
            }
            auto lb = present.lower_bound(target);
            auto ub = present.upper_bound(target);
            
            if(lb!=present.begin()){
                auto lb2 = prev(lb);
                upd(*lb2);
            }
   
            if(ub!=present.end()) upd(*ub);
            if(lb!=present.end()) upd(*lb);
            
            
        }
        return ans;
    }
};