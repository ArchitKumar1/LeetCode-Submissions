// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int MAX = 0;
        int i = 0;
        while(i<nums.size()){
            int x = 0;
            if(nums[i] == 1){
                while(i<nums.size() && nums[i]==1){
                    x++;
                    i++;
                }
                MAX = max(MAX,x);
            }
            else{
                i++;
            }
        }
        return MAX;
    }
};