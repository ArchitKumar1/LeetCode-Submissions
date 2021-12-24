// https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int s = 0;
        for(int c : nums)s+= c;
        
        long long int diff = abs(goal -s);
        long long int ans = diff/limit + ((diff%limit)>0);
        return ans;
        
    }
};