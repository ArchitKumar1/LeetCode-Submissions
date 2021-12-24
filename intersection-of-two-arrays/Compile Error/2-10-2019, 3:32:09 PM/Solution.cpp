// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> result(max(nums1.size(),nums2.size()));
        
        auto it= set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),results.begin());
        results.resize(it-result.begin());
        
        it=unique(result.begin(),result.end());
        result.resize(it-result.begin());
        return result;
    }
};