// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        multiset<int> ms;
        int i = 0;
        int ans= 0 ;
        for(int j =0;j<nums.size();j++){
            
            ms.insert(nums[j]);
            while( ms.size() && (*ms.rbegin() - *ms.begin() >  limit)){
                ms.erase(ms.find(nums[i]));
                i++;
            }
            ans =max(ans,j-i+1);
        }
        return ans;
    }
};