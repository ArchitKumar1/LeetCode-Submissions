// https://leetcode.com/problems/sum-of-beauty-in-the-array

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> mx = nums,mi = nums;
        for(int i = 1;i < n;i++){
            mx[i] = max(mx[i-1],nums[i]);
        }
        for(int i = n -2;i >=0;i--){
            mi[i] = min(mi[i+1],nums[i]);
        }
        int ans = 0;
        for(int i = 1;i < n-1;i++){
            if( mx[i-1] < nums[i] && nums[i] < mi[i+1]) ans += 2;
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) ans+= 1;
        }
        return ans;
    }
};