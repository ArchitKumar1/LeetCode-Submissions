// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0,j = 0,cnt = 0;j<n;j++){
            cnt += (nums[j] == 0);
            while(cnt > 1){
                cnt -= (nums[i] == 0);
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans-1;
    }
};