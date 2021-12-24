// https://leetcode.com/problems/number-of-good-pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int  h=0;h<i;h++){
                ans += nums[h] == nums[i];
            }
        }
        return ans;
    }
};