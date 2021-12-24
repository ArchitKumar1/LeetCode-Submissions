// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median1,median2;
        if(nums1.size() == 0) median1 = 0;
        else median1 = (nums1.size()%2 == 0 ? (1.0*(nums1[nums1.size()/2]+nums1[-1 + nums1.size()/2]))/2 : nums1[nums1.size()/2]);
        if(nums2.size() == 0) median2 = 0;
        else median2 = (nums2.size()%2 == 0 ? (1.0*(nums2[nums2.size()/2]+nums2[-1 + nums2.size()/2]))/2 : nums2[nums2.size()/2]);
        return (median1 + median2)/2;
    }
}; 