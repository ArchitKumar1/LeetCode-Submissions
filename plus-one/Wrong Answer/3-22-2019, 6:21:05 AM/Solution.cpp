// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n = 0;
        int l = 0;
        reverse(nums.begin(),nums.end());
        for(int num : nums){
            n += num*pow(10,l++);
        }
        n++;
        vector<int> ans;
        while(n){
            ans.push_back(n%10);
            n = n/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};