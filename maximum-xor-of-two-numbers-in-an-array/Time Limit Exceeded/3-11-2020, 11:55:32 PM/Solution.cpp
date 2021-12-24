// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0 ;
        int n = nums.size();
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                ans = max(ans, nums[i] ^ nums[j]);
            }
        }
        return ans;
    }
};