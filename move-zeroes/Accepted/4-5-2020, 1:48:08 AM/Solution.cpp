// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        bool f = 0;
        int j = 0;
        for(int i = 0;i<n;i++){
            
            if(nums[i] != 0){
                swap(nums[i],nums[j]);
                j++;
            }
            
        }
    }
};