// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i =1;i<=1000;i++){
            auto it = lower_bound(nums.begin(),nums.end(),i);
                ans = max(ans,(int)(nums.end()-it));
           
        }
        return ans==0 ? -1 : ans;
    }
};