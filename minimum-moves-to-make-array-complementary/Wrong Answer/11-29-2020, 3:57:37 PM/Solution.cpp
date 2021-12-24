// https://leetcode.com/problems/minimum-moves-to-make-array-complementary

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0,j = n-1;i<j ;i++,j--){
            if(nums[i] == limit && nums[j] == limit){
                ans += 2;
            }else if(nums[i]+nums[j] !=limit){
                ans += 1;
            }
            
        }
        return ans;
    }
};