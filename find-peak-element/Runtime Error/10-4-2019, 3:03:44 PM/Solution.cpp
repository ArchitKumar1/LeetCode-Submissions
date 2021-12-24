// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int ans =  0;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]<=nums[mid+1]){
                ans = mid+1;
                l = mid+1;
            }else h = mid-1;
        }
        return ans;
    }
};