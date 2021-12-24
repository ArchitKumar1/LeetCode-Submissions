// https://leetcode.com/problems/create-target-array-in-the-given-order

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans;
        for(int c : index){
            ans.insert(ans.begin() +c,nums[i]);
        }
        return ans;
    }
};