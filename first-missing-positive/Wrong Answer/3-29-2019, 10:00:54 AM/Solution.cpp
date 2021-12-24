// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(auto n : nums){
            if(n == ans){
                ans = n+1;
            }
        }
        return ans;
    }
};