// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums[0] == 0)
            return 1;
        map<int,int> m1;
        int ans = 0;
        for(auto n : nums)
            m1[n]++;
        for(int i=0;i<nums.size();i++){
            if(m1[i] == 0)
                ans = i;
        }
        return ans;
    }
};