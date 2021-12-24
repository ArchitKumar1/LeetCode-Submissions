// https://leetcode.com/problems/permutations

class Solution {
public:
    int n;
    void calc(vector<int>& nums,vector<vector<int>>& res, int c){
        if(c == n){
            res.push_back(nums);
            return;
        }
        for(int i=c;i<n;i++){
            swap(nums[c],nums[i]);
            calc(nums,res,c+1);
            swap(nums[c],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> res;
        calc(nums,res,0);
        return res;
    }
};