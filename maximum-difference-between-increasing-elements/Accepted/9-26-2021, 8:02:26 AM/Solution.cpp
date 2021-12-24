// https://leetcode.com/problems/maximum-difference-between-increasing-elements

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        
        int ans = INT_MIN;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(nums[i] < nums[j]){
                    ans = max(ans,nums[j]-nums[i]);
                }
            }
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};