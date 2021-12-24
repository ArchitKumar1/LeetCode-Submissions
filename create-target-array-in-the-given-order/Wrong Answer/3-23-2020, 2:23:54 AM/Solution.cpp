// https://leetcode.com/problems/create-target-array-in-the-given-order

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        sort(nums.begin(),nums.end(),[&](int x ,int y){
            int a = 0;
            int b = 0;
            for(int i = 0;i<nums.size();i++){
                if(nums[i] == x){
                    a = index[i];
                }
                if(nums[i] == y){
                    b = index[i];
                }
            }
            return a < b;
        });
        return nums;
    }
};