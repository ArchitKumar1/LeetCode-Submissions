// https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int s = 0;
        for(int c : nums)s+= c;
        
        int diff = abs(goal -s);
        int ans = diff/limit + ((diff%limit)>0);
        return ans;
        
    }
};