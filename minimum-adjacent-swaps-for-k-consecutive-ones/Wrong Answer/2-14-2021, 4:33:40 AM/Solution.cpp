// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        
        int ans = INT_MAX;
        int ones = 0;
        
        for(int i = 0,j = 0;j<n;j++){
            ones += nums[j];
            
            while(ones >  k || nums[i] == 0 && i < j){
                ones -= nums[i++];
            }
            if(ones == k){
                ans = min(ans,j-i+1 -ones);
            }
        }
        return ans;
    }
};