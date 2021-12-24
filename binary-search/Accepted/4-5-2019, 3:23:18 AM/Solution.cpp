// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int r  = nums.size() -1;
       ios_base::sync_with_stdio(false);cin.tie(NULL);
        while(l<=r){
            int mid =  l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(target<nums[mid]){
                r = mid-1;
            }else{
                l= mid+1;
            }
        }
        return -1;
    }
};