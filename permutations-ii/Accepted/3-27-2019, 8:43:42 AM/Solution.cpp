// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    void calc(set<vector<int>> & res,vector<int>& nums,int p){
        if(p == nums.size()){
            res.insert(nums);
        }
        for(int i=p;i<nums.size();i++){
            swap(nums[p],nums[i]);
            calc(res,nums,p+1);
            swap(nums[p],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        calc(res,nums,0);
        return vector<vector<int>>(res.begin(),res.end());
    }
};