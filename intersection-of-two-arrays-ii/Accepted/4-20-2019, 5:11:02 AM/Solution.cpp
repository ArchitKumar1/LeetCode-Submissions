// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m1; vector<int> ans;
        for(auto a : nums1) m1[a]++;
        for(auto b : nums2) if(m1[b]) m1[b] -=1,ans.push_back(b);
        return ans;
    }
};