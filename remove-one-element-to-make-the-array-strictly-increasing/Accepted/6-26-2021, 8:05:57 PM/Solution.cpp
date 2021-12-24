// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        bool ans = 0;
        int n = nums.size();
        
        for(int i =0;i<n;i++){
            vector<int> v;
            for(int j = 0;j <n;j++){
                if(i == j) continue;
                v.push_back(nums[j]);
            }
            bool safe = 1;
            for(int i = 0;i+1 < v.size();i++){
                if(v[i] >= v[i+1]) safe = 0;
            }
            if(safe == 1){
                ans = 1;
            }
        }
        bool safe = 1;
        for(int i = 0;i+1 < nums.size();i++){
            if(nums[i] >= nums[i+1]) safe = 0;
        }
        if(safe == 1){
            ans = 1;
        }
        return ans;
    }
};