// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nn) {
        vector<int> nums = nn;
        int s = 0;
        int ans = 0;
        int n = nums.size();
        int cnt = 0;
        for(int i = 0,j = 0;j<n;j++){
            while(cnt > 1){
                cnt -= nums[i] == 0;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans-1;
    }
};