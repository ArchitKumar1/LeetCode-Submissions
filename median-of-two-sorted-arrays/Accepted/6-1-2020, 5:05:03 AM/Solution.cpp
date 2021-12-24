// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int c : nums1) ans.push_back(c);
        for(int c : nums2) ans.push_back(c);
        sort(ans.begin(),ans.end());
        int n = ans.size();
        if(n%2 == 0){
            return (1.0*ans[n/2] +  ans[-1 + n/2])/2;
        }else{
            return ans[n/2];
        }
    }
};