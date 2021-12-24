// https://leetcode.com/problems/removing-minimum-and-maximum-from-array

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        auto mx = *max_element(nums.begin(),nums.end());
        auto mi = *min_element(nums.begin(),nums.end());
        
        auto it1 = find(nums.begin(),nums.end(),mx) - nums.begin();
        auto it2 = find(nums.begin(),nums.end(),mi) - nums.begin();
        if(it1 > it2) swap(it1,it2);
        int ans = min({1 + max(it1,it2),2 + it1 + (n-1-it2), 1 + n-1-min(it1,it2)});
        return ans;
    }
};