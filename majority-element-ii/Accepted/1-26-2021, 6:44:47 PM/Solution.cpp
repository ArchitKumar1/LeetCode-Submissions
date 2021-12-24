// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> m1;
        for(int c : nums) m1[c]++;
        vector<int> ans;
        for(auto x : m1) if (x.second > nums.size()/3 ) ans.push_back(x.first);
        return ans;
    }
};