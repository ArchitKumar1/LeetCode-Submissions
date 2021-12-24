// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> cnt(100010,-2);
        cnt[50050] = -1;
        int ans = 0;
        int curr = 50050;
        for(int i = 0;i<nums.size();i++){
            curr += (nums[i] == 1 ? 1 : -1);
            if(cnt[curr] != -2){
                ans = max(ans,i - cnt[curr]);
            }else{
                cnt[curr] = i;
            }
        }
        return ans;
        
    }
};