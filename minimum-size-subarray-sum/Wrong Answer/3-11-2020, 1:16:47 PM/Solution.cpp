// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l  =0 ;
        int r = 0;
        int n = nums.size();
        int ans = INT_MAX;
        long long int  sum = 0;
        while(r < n){
            sum += nums[r++];
            while(sum>=s){
                ans = min(ans,r-l);
                sum -=nums[l++];
            }
        }
        return sum;
    }
};