// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = 0;
        int temp = 0;
        for(int c : nums){
            temp += c;
            if(temp < 0)temp = 0;
            maxi = max(maxi,temp);
        }
        return maxi;
    }
};